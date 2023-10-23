

// ╔══════════════════════════════════════════════════════════════════╗
// ║   ____    _             __  __           _            _          ║
// ║  |  _ \  (_)           |  \/  |         | |          (_)         ║
// ║  | |_) |  _    __ _    | \  / |   __ _  | |_   _ __   _  __  __  ║
// ║  |  _ <  | |  / _` |   | |\/| |  / _` | | __| | '__| | | \ \/ /  ║
// ║  | |_) | | | | (_| |   | |  | | | (_| | | |_  | |    | |  >  <   ║
// ║  |____/  |_|  \__, |   |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\  ║
// ║                __/ |                                             ║
// ║               |___/                                              ║
// ║                                                                  ║
// ║  _         _____   _____      _____                           _  ║
// ║ | |       / ____| |  __ \    |  __ \                         | | ║
// ║ | |      | |      | |  | |   | |__) |   __ _   _ __     ___  | | ║
// ║ | |      | |      | |  | |   |  ___/   / _` | | '_ \   / _ \ | | ║
// ║ | |____  | |____  | |__| |   | |      | (_| | | | | | |  __/ | | ║
// ║ |______|  \_____| |_____/    |_|       \__,_| |_| |_|  \___| |_| ║
// ║                                                                  ║
// ║                                                                  ║
// ║                                                                  ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝

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
int globalVelocity=0;
String globalStatus="play";


int contCharAdded = 0;

unsigned long time = 0;
unsigned long lastTime = 0;
unsigned long difTime = 0;
unsigned long waitTime = 0;

unsigned long lastTime2 = 0;
unsigned long difTime2 = 0;

double promTime2 = 0;

unsigned long lastTime3 = 0;
unsigned long difTime3 = 0;

double promTime3 = 0;

int repeatloop = 0;
int contRepeatLoop = 0;
VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
//VectorClassString vecStrOne(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClassString vecStrOne(0);

MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

String lastStrToShow = "";
String BTstrReceived = "";
String lastBTstrReceived = "";
//String inputString = "a:aefe1;x:1;v:2|m:tést de, texto";
//String inputString = "a:aefe1";
//String inputString = "a:efe1|a:efe2|a:efe3|a:efe4|a:efe5|a:efe6|a:efe7|a:tec1|a:tec2|a:tec3|a:tec4|a:tec5|a:tec6|m:E.E.S.T. Nº2";
String inputString = "a:efe1;v:1;r:2|m:Original";
String strBackup="";
String option = "";
int foundAnim = 0;
int contLoop = 0;
unsigned long loopVelocity = 0;
SoftwareSerial BTSerial(52,53); 
String strBt="";

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
    

    //Serial.begin(9600);
    BTSerial.begin(9600);

        SoftwareSerial BTSerial(PIN_BT_RXD, PIN_BT_TXD);  //10 RX, 11 tx


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
    loopVelocity = waitTime * DEFAULT_VELOCITY;

    ds("loopVelocity=");dsl(loopVelocity);
    //VectorClassString vecStrOne(0);

}

// Secuencia de la matriz
void loop() {

    //dsd();dsl("---LOOP---LOOP---LOOP---LOOP---LOOP---LOOP---LOOP---LOOP---");dsd();dss();

    
    //ds("contLoop=");dsl(contLoop);
    contLoop++;
    strBt=getBluetoot(BTSerial);
    



    
    if(strBt!="") {
        strBackup=inputString;
        inputString=strBt;
        proccesAction(inputString, vecStrOne);        
        updateStateAndEffect(vecStrOne,option,effectOption,text,velocity,repeat,globalVelocity,globalStatus);

    }
    
        
    if (contRepeatLoop >= repeatloop) {
        
        contRepeatLoop = 0;
        option == "";
            dsl("-->Step 01<--");
  //      proccesAction(inputString, option, effectOption, text, velocity, repeat);
        proccesAction(inputString, vecStrOne);        
        updateStateAndEffect(vecStrOne,option,effectOption,text,velocity,repeat,globalVelocity,globalStatus);
  
        loopVelocity = waitTime * velocity;
        repeatloop = repeat;
    }
    
    

    //vecStrOne.print();

//Test de escirtura con teclado mecanico
    /*
    DESCOMENTAR ESTO
    if (difTime >= loopVelocity) {

        if (option == "m" && (lastStrToShow != text)) {
            dsl("-->Step 02<--");
            dm.fillArrrayOfChars(vecChar, text);
            lastStrToShow = text;

        }
        //--------------------------------------------------------------------
        // Si la opcion es marquee y se puede agregar un caracter a la matriz 
        // lo agrega    
        if (option == "m" && dm.canAddChar() && contCharAdded < vecChar.getSize()) {
            dsl("-->Step 03<--");
            ds("contCharAdded=");dsl(contCharAdded);
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
            dsl("-->Step 04<--");
            matrix.print();
            if (dm.getPosLastChar() > 0) {
                dm.GetFrame(matrix, aFrame);
                dm.moveMatrixToLeft(matrix);
                ds("dm.getPosLastChar()=");dsl(dm.getPosLastChar());
            }
            dsl("Paso m por acá->m 1");
        }

        ds5("an.getIfAnimIsEnd()=");ds5l(an.getIfAnimIsEnd());

        if (option == "a" && !an.getIfAnimIsEnd()) {
            dsl("-->Step 05<--");
            foundAnim = an.getAnim(aFrame, effectOption);
            dsl("Paso m por acá->a 2");
        }

        if (option == "a" || option == "m") {
            dsl("-->Step 06<--");
            sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
            dsl("Paso m por acá-> 3");
        }
        ds5(" dm.getIfIsStringEnd()=");ds5l(dm.getIfIsStringEnd());
        ds5(" an.getIfAnimIsEnd()=");ds5l(an.getIfAnimIsEnd());


        if ((contCharAdded >= vecChar.getSize() && dm.getIfIsStringEnd()) || an.getIfAnimIsEnd()) {
            dsl("-->Step 07<--");

            //option = "";
            an.reset();
            dm.ResetInitPosMatrix();
            dm.setIfIsStringEnd(false);
            matrix.clear();
            contCharAdded = 0;
            dsl("Paso m por acá-> 4");
            contRepeatLoop++;
        }
        lastTime = time;
    }
    FIN DESCOMENTAR ESTO
    */

    time = micros();
    difTime = time - lastTime;
    difTime2 = time - lastTime2;

}