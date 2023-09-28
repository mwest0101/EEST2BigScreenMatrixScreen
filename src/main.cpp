#include <Arduino.h>
#include "inc_include.h"
int *aPins;
int nElements = 0;
// int *aFrame;
int *aT2;
int *busChars;
int *aPacman;
int *aPacman2;
int *aPacman3;
// static int * aChar;
int *AChar;
int *BChar;
int posLetDesp = 0;
// int * aFrame;
// int **matrix;
int pinState = 0;
#ifdef IS_LCDSCREEN
MatrizLed pantalla;
#endif
DriveMatrix dm;
ShowMatrix sm;
ProgmemManager pm;
// String strToShow = "Bienvenidos a la EEST Nº2  de Junin Buenos Aires 2023";
String strToShow = "(a:pac1)(a:tet1)(a:pac2)E.E.S.T. Nº2";
// String strToShow = "abcdefghijklmnopqrstuvwxyz01234";
// String strToShow = "Mauricio Pablo West";
String lastStrToShow = "";
int *test;
int oldCodSumTo = 0;
int contChars = 0;
int firstPass = 0;
VectorClass vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
int numOfcharacter = 0;
int contCharAdded = 0;
unsigned long time = 0;
unsigned long lastTime = 0;
unsigned long difTime = 0;
unsigned long waitTime = 0;
char charReaded;
char lastCharReaded;
int action = 0;
String strOption = "";
bool getIfisEnd = false;
bool canAddChar = false;

void setup()
{
    time = micros();
    lastTime = time;
    difTime = 0;
    waitTime = WAIT_TIME_LOOP;

#ifndef WAIT_TIME_LOOP
#define WAIT_TIME_LOOP 500000
#endif

#ifdef DEBUG_SERIAL
    Serial.begin(9600);
#endif

#ifdef DEBUG
    debug_init();
#endif
#ifdef IS_LCDSCREEN
    pantalla.begin(12, 11, 10, 1); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.setIntensidad(1);
#endif
    sm = ShowMatrix();
    dm = DriveMatrix();
    pm = ProgmemManager();

#ifdef IS_LCDSCREEN
    pantalla.borrar();
    sm.setPantalla(pantalla);
#endif

    convProgToArray(vecPins, C_Pins, (sizeof(C_Pins) / 2));
    vecPins.print();
}
// Secuencia de la matriz
void loop()
{
    time = micros();
    difTime = time - lastTime;

    if (difTime >= waitTime)
    {
        dsd();
        dsl("LOOP in timeout");
        lastTime = time;
        dm.fillArrrayOfChars(vecChar, strToShow);

        if (contCharAdded > vecChar.getSize())
            contCharAdded = 0;
        canAddChar = dm.canAddChar();
        getIfisEnd = pm.getIfisEnd();

        ds("canAddChar=");
        dsl(canAddChar);
        ds("getIfisEnd=");
        dsl(getIfisEnd);

        //if (pm.getIfisEnd() && dm.canAddChar())
        if(action!=15 && dm.canAddChar())
        {
            dss();
            dsl("Inicio de proceso");
            charReaded = (char)vecChar.get(contCharAdded);
            if (charReaded == '(')
            {
                dss();
                ds("se encuentra (");
                ds(" contCharAdded: ");
                dsl(contCharAdded);

                strOption = "";
                action = 10;
                contCharAdded++;
            }
            else if (charReaded == ')')
            {
                dss();
                dsl("se encuentra )");

                ds(" contCharAdded: ");
                dsl(contCharAdded);
                // action=5;
                contCharAdded++;
                pm.setIfisEnd(false);
                action = 15;
            }
            else if (action == 10)
            {

                strOption = strOption + charReaded;
                dss();
                dsl("Concatena:");
                ds("strOption:");
                dsl(strOption);

                contCharAdded++;
                ds("Entre a concatenacion de efectos ");
                ds(" contCharAdded: ");
                dsl(contCharAdded);
                ds(" strOption: ");
                dsl(strOption);
            }
            else
            {
                dss();
                ds("Entra a captura de texto a concatenar:");
                ds(charReaded);
                dm.getValuesOfCharMatrixAndAddToMatrix(matrix, aIntCharMatrix, vecChar, contCharAdded);
                contCharAdded++;
                firstPass = 1;
            }
        }
        if (action == 15)
        {
            if (strOption == "a:pac1")
            {
                dsl("----->Paso por a:pac1");
                aFrame.clear();
                pm.convProgToArrayByFrame(aFrame, C_PACMAN_ANIM_01, (sizeof(C_PACMAN_ANIM_01) / 2));
            }
            if (strOption == "a:pac2")
            {
                dsl("----->Paso por a:pac2");
                aFrame.clear();
                pm.convProgToArrayByFrame(aFrame, C_PACMAN_ANIM_02, (sizeof(C_PACMAN_ANIM_02) / 2));
            }
            if (strOption == "a:tet1")
            {
                dsl("----->Paso por a:tet1");
                aFrame.clear();
                pm.convProgToArrayByFrame(aFrame, C_TETRIS_ANIM_01, (sizeof(C_TETRIS_ANIM_01) / 2));
            }
            
            dsl("Despues de if strOption");
            ds(" strOption: ");
            dsl(strOption);
        }

        // action=0;
        /*dsis("LastPoschar:");
        dsil(dm.getPosLastChar());*/
        
        // if(action==0){
        //-->matrix.print();
        if (action == 0)
        {
            aFrame.reset();
            dm.GetFrame(matrix, aFrame);
            matrix.print();
            
        }
        // dsl("aFrame------------------------>");
        //aFrame.print();

        // aLastFrame.print();

        //-->vecPins.print();

        // dsl("------------------------------>");

        if (action == 0 || action == 15)
        {
            dsl("Antes de imprimir");
            aFrame.print();
        }

        sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
        if (action == 0 && dm.getPosLastChar() > 0)
        {    
            dm.moveMatrixToLeft(matrix);
        }

        //}
        //matrix.print();
        if (pm.getIfisEnd())
        {
            pm.reset();
            strOption="";
            action=0;
            // action = 0;
        }
        ds("action=");
        dsl(action);
    }
}