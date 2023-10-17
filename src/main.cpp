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
*/

// String inputString2 = "Bienvenidos a la EEST Nº2  de Junin Buenos Aires 2023";
//String inputString2 = "a:efe1|a:efe2|a:efe3|a:efe4|a:efe5|a:efe6|a:efe7|a:tec1|a:tec2|a:tec3|a:tec4|a:tec5|a:tec6|a:tec7|E.E.S.T. Nº2";
// String inputString2 = "(a:efe1|a:efe2|a:efe3|a:efe4|a:efe5|a:efe6|a:efe7|tec1|tec2|tec3|tec4|tec5|tec6)E.E.S.T. Nº2";
// String inputString2 = "a:efe1;x:1;v:2|a:efe2;x:3;v:4|m:tést de, texto|a:efe1;x:4;v:2";
// String inputString2 = "(a:efe333|x:2|v:3|a:efe1|a:efe333|a:efe2)E.E.S.T. Nº2";
 //String inputString2 = "a:efe1|m:E.E.S.T. Nº2";
 String inputString2 = "a:efe1|m:E.";
// String inputString2 = "(a:efe1)E.E.S.T. Nº2";
// String inputString2 = "abcdefghijklmnopqrstuvwxyz01234";
// String inputString2 = "Mauricio Pablo West";
/*
String lastStrToShow = "";
int *test;
int oldCodSumTo = 0;
int contChars = 0;
int firstPass = 0;
VectorClass vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);


String aPara[200];
String aVals[200];
int numOfcharacter = 0;


char charReaded;
char lastCharReaded;
int action = 0;
String strOption = "";
bool getIfisEnd = false;
bool canAddChar = false;
bool getNextChar = true;
int found=0;
unsigned int aLargoString=0;*/
#ifdef IS_LCDSCREEN
MatrizLed pantalla;
#endif

DriveMatrix dm;
ShowMatrix sm;
AnimManager an;

int stateAction = 0;
String effectOption = "";
String text = "";

int repeat = DEFAULT_REPEAT;
int velocity = DEFAULT_VELOCITY;
int contCharAdded = 0;

unsigned long time = 0;
unsigned long lastTime = 0;
unsigned long difTime = 0;
unsigned long waitTime = 0;
VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

String lastStrToShow = "";
//String inputString2 = "a:aefe1;x:1;v:2|m:tést de, texto";
//String inputString2 = "a:aefe1";
String option = "";
int foundAnim = 0;


void setup() {
    time = micros();
    lastTime = time;
    difTime = WAIT_TIME_LOOP;
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
    an = AnimManager();

#ifdef IS_LCDSCREEN
    pantalla.borrar();
    sm.setPantalla(pantalla);
#endif
    time = micros();

    convProgToArray(vecPins, C_Pins, (sizeof(C_Pins) / 2));
    vecPins.print();


    difTime = waitTime;


    // String oneGroup="";
    // VectorClassString vecStr(0);
    // VectorClassString vecStrParam(0);
    VectorClassString vecStrOne(0);

    //oneGroup=getOneGroup(inputString2, stateAction);
    //vecStr.print();
    /*proccesAction(inputString2,option,effectOption,text,velocity,repeat);
    vecStrOne.print();
    proccesAction(inputString2,option,effectOption,text,velocity,repeat);
    vecStrOne.print();
    proccesAction(inputString2,option,effectOption,text,velocity,repeat);
    vecStrOne.print();
    proccesAction(inputString2,option,effectOption,text,velocity,repeat);
    vecStrOne.print();*/
    // proccesAction(inputString2,effectOption,text,velocity,repeat);
    // vecStrOne.print();
    // proccesAction(inputString2,effectOption,text,velocity,repeat);
    // vecStrOne.print();
    // proccesAction(inputString2,effectOption,text,velocity,repeat);
    // vecStrOne.print();
    // proccesAction(inputString2,effectOption,text,velocity,repeat);
    // vecStrOne.print();



}

// Secuencia de la matriz
void loop() {
    dst("LOOP");


    if (option == "") {
        ds("-->Step 01<--");
        proccesAction(inputString2, option, effectOption, text, velocity, repeat);
    }
    //vecStrOne.print();

//Test de escirtura con teclado mecanico


    time = micros();
    if (option == "m" && (lastStrToShow != text)) {
        ds("-->Step 02<--");
        dm.fillArrrayOfChars(vecChar, text);
        lastStrToShow = text;

    }
    //--------------------------------------------------------------------
    // Si la opcion es marquee y se puede agregar un caracter a la matriz 
    // lo agrega    
    if (option == "m" && dm.canAddChar()) {
        ds("-->Step 03<--");
        aIntCharMatrix.clear();
        getCharMatrix(aIntCharMatrix, vecChar.get(contCharAdded));
        dm.AddConsToMatrix(matrix, aIntCharMatrix, vecChar.get(contCharAdded));
        dm.setCanAddChar(false);
        contCharAdded++;
    }
    //--------------------------------------------------------------------
    // si la opcion es marquee y se puede mover se mueve la matriz hacia 
    // la izquierda hasta que llega a 0
    ds5("option=");ds5l(option);


    if (option == "m") {
        ds("-->Step 04<--");
        matrix.print();
        if (dm.getPosLastChar() > 0){
             dm.GetFrame(matrix, aFrame);
             dm.moveMatrixToLeft(matrix);
             ds("dm.getPosLastChar()=");dsl(dm.getPosLastChar());
        }
        dsl("Paso m por acá->m 1");
    }
    
    ds5("an.getIfAnimIsEnd()=");ds5l(an.getIfAnimIsEnd());

    if (option == "a" && !an.getIfAnimIsEnd()) {
        ds("-->Step 05<--");
        foundAnim = an.getAnim(aFrame, effectOption);
        dsl("Paso m por acá->a 2");
    }
    
    if (option=="a" || option=="m"){
        ds("-->Step 06<--");
        sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
        dsl("Paso m por acá-> 3");
    }
    ds5(" dm.getIfIsStringEnd()=");ds5l(dm.getIfIsStringEnd());
    ds5(" an.getIfAnimIsEnd()=");ds5l(an.getIfAnimIsEnd());
    
    
    if ((contCharAdded>=vecChar.getSize() && dm.getIfIsStringEnd()) || an.getIfAnimIsEnd()){
        ds("-->Step 07<--");

        option ="";
        an.reset();
        dm.ResetInitPosMatrix();
        dm.setIfIsStringEnd(false);
        vecChar.clear();
        dsl("Paso m por acá-> 4");
    }
    /*
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