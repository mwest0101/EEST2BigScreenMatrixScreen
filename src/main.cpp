#include <Arduino.h>
#include "inc_include.h"
int *aPins;
int nElements = 0;
//int *aFrame;
int *aT2;
int *busChars;
int *aPacman;
int *aPacman2;
int *aPacman3;
// static int * aChar;
int *AChar;
int *BChar;
int posLetDesp = 0;
//int * aFrame;
//int **matrix;
int pinState = 0;
#ifdef IS_LCDSCREEN
MatrizLed pantalla;
#endif
DriveMatrix dm;
ShowMatrix sm;    //012345678901234567890123456789
//String strToShow = "Bienvenidos a la EEST Nº2  de Junin Buenos Aires 2023";
String strToShow = "(e:1)(a:pa1)(a:te1)E.E.S.T. Nº2";
//String strToShow = "abcdefghijklmnopqrstuvwxyz01234";
//String strToShow = "Mauricio Pablo West";
String lastStrToShow = "";
int *test;
int oldCodSumTo = 0;
int contChars = 0;
int firstPass=0;
VectorClass vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
MatrixClass matrix(BUILD_MATRIX_ROWS,BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE); 
VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
int numOfcharacter = 0;
int contCharAdded=0;
unsigned long time=0;
unsigned long lastTime=0;
unsigned long difTime=0;
unsigned long waitTime=0;

void setup(){
    time = micros();
    lastTime = time;
    difTime=0;
    waitTime=WAIT_TIME_LOOP;

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

    #ifdef IS_LCDSCREEN
        pantalla.borrar();
        sm.setPantalla(pantalla);
    #endif
        
        convProgToArray(vecPins,C_Pins, (sizeof(C_Pins) / 2));
        vecPins.print();
        
}
// Secuencia de la matriz
void loop(){
    time = micros();
    difTime=time-lastTime;
    // dsi("time:");
    // dsi(time);
    // dsi(" lastTime:");
    // dsi(lastTime);
    // dsi(" difTime:");
    // dsil(difTime);
    // dm.fillArrrayOfChars(vecChar,strShow)
    if (difTime>=waitTime){
        lastTime=time;        
        dm.fillArrrayOfChars(vecChar,strToShow);
        

        if(contCharAdded>vecChar.getSize()) contCharAdded=0;
        dsis("Antes de  bucle de loop");
        dsil("char : ");
        dsil((char)vecChar.get(contCharAdded));
        dsil(" int : ");
        dsil(vecChar.get(contCharAdded));

        if(firstPass==0 || dm.canAddChar()==1){
            dsis("Inicio de for");
            dm.getValuesOfCharMatrixAndAddToMatrix(matrix,aIntCharMatrix,vecChar,contCharAdded);
            contCharAdded++;
            firstPass=1;
        }

        /*dsis("LastPoschar:");
        dsil(dm.getPosLastChar());*/
        matrix.print();
        aFrame.reset();

        dm.GetFrame(matrix,aFrame);
        dsl("aFrame------------------------>");
        aFrame.print();

        //aLastFrame.print();

        vecPins.print();

        dsl("------------------------------>");

        sm.PrintLedMatrix(aFrame,aLastFrame,vecPins);
        dm.moveMatrixToLeft(matrix);

    }
}