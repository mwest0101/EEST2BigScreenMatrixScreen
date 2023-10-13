#include <Arduino.h>
#include "inc/include.h"
/*<-(QUITA ESTO) int *aPins;
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

AnimManager an;
// String strToShow = "Bienvenidos a la EEST Nº2  de Junin Buenos Aires 2023";
// String strToShow = "(a:efe1|a:efe2|a:efe3|a:efe4|a:efe5|a:efe6|a:efe7|tec1|tec2|tec3|tec4|tec5|tec6|tec7)E.E.S.T. Nº2";
//String strToShow = "(a:efe1|a:efe2|a:efe3|a:efe4|a:efe5|a:efe6|a:efe7|tec1|tec2|tec3|tec4|tec5|tec6)E.E.S.T. Nº2";
String strToShow = "(a:efe333|x:2|v:3|a:efe1|a:efe333|a:efe2)E.E.S.T. Nº2";
//String strToShow = "(a:efe1|a:efe2:x2)E.E.S.T. Nº2";
//String strToShow = "(a:efe1)E.E.S.T. Nº2";
// String strToShow = "abcdefghijklmnopqrstuvwxyz01234";
//  String strToShow = "Mauricio Pablo West";
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
String aPara[200];
String aVals[200];
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
bool getNextChar = true;
int found=0;
unsigned int aLargoString=0;*/
DriveMatrix dm;
ShowMatrix sm;

AnimManager an;
int stateAction=0;

void setup()
{
    /*<-(QUITA ESTO)time = micros();
    lastTime = time;
    difTime = WAIT_TIME_LOOP;
    waitTime = WAIT_TIME_LOOP;

#ifndef WAIT_TIME_LOOP
#define WAIT_TIME_LOOP 500000
#endif
*/

#ifdef DEBUG_SERIAL
    Serial.begin(9600);
#endif


/*<-(QUITA ESTO)
#ifdef DEBUG
    debug_init();
#endif
#ifdef IS_LCDSCREEN
    pantalla.begin(12, 11, 10, 1); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.setIntensidad(1);
#endif
    sm = ShowMatrix();
    dm = DriveMatrix();
    an = AnimManager();

#ifdef IS_LCDSCREEN
    pantalla.borrar();
    sm.setPantalla(pantalla);
#endif
    time = micros();

    convProgToArray(vecPins, C_Pins, (sizeof(C_Pins) / 2));
    vecPins.print();
    difTime = waitTime;*/
    String inputString2 = "a:efe1;x:4;v:2|a:efe2;x:6;v:3|test de, texto|a:efe1;x:4;v:2";
    
    VectorClassString vecStr(0);
    VectorClassString vecStrParam(0);
    VectorClassString vecStrOne(0);
  
    getAction(vecStrParam, inputString2, stateAction);
    //vecStr.print();
    proccesAction(vecStrParam,vecStrOne);
    vecStrOne.print();
}

// Secuencia de la matriz
void loop()
{

    /*
    time = micros();
    dm.fillArrrayOfChars(vecChar, strToShow);

    dsl("");dsl("========================LOOOOOP=================================");    
    ds(" |contCharAdded=");ds(contCharAdded);ds(" |strOption=");ds(strOption);
    canAddChar = dm.canAddChar();
    getIfisEnd = an.getIfAnimIsEnd();
    ds(" |canAddChar=");ds(canAddChar);ds(" |getIfisEnd=");dsl(getIfisEnd);ds(" |actionAnterior=");ds(action);

    strToVector(strToShow,aPara,aVals);
    */
     
    /*<-(QUITA ESTO)
    //aLargoString=(sizeof(aPara)/sizeof(aPara[0]));
    strToVector(strToShow,aPara,aVals);
    aLargoString=3;

    for(unsigned int i;i<aLargoString;i++){ 
        ds("[");ds(aPara[i])ds("]=");dsl(aVals[i]);
    }
       
    if (getNextChar)
    {
        
        dsl("entro al selector");dss();dsl("Inicio de proceso");
        if (contCharAdded > vecChar.getSize()) contCharAdded = 0;
        charReaded = (char)vecChar.get(contCharAdded);
        
        ds(" |charReaded=") ds(charReaded);
        
        strOption = concParamsOfString(charReaded, strOption, action);
        
        ds(" |action=");dsl(action);
        
        if (action == 0)
        {
            dss();ds("Entra a captura de texto a concatenar:");ds(charReaded);

            dm.getValuesOfCharMatrixAndAddToMatrix(matrix, aIntCharMatrix, vecChar, contCharAdded);
            dm.setCanAddChar(false);
            getNextChar = false;

        }

        if (action == 19)
        {
            dsl("Desactiva busqueda de caracteres")
            getNextChar = false;
            an.setIfisEnd(false);
        }

        contCharAdded++;
    }

    if (difTime >= waitTime)
    {
        dsl("LOOP in timeout");
        lastTime = time;
        // if (pm.getIfisEnd() && dm.canAddChar())
        if (action == 19)                                           found=an.getAnim(aFrame, strOption); //{   found=an.getAnim(aFrame, strOption); dss();           dsl("Despues de if strOption");           ds(" strOption: ");           dsl(strOption);        }
        if (action == 0) {                                          aFrame.reset();dm.GetFrame(matrix, aFrame);}//  { aFrame.reset(); dm.GetFrame(matrix, aFrame);dsl("Antes de imprimir");matrix.print();}

        if (action == 0 || (found==1 && action == 19))              sm.PrintLedMatrix(aFrame, aLastFrame, vecPins); //{ aFrame.print(); sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);}
        if (action == 0 && dm.getPosLastChar() > 0)                 dm.moveMatrixToLeft(matrix); //{ dm.moveMatrixToLeft(matrix);}
        if (found==(-1) || (an.getIfAnimIsEnd() && action==19)){    an.reset();dsl("Entro a reset");strOption = "";action = 0;}        
    }

    if (found==(-1) || (dm.canAddChar() && an.getIfAnimIsEnd())){   found=0;getNextChar = true;}

    difTime = time - lastTime;
    */
   
}