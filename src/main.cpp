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

#ifdef IS_LCDSCREEN
MatrizLed pantalla;
#endif

DriveMatrix dm;
ShowMatrix sm;
AnimManager an;

int stateAction = 0;
String effectOption = "";
String text = "";
int contParam = 0;

int repeat = DEFAULT_REPEAT;
int contRepeat = 0;

int velocity = DEFAULT_VELOCITY;

String globalStatus = "play";


int contCharAdded = 0;

unsigned long time = 0;
unsigned long lastTime = 0;
unsigned long difTime = 0;
unsigned long loopWaitTime = 0;


double promTime3 = 0;
unsigned long calcLoopTime=0;
VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClassString vecStr(0);
VectorClassString vecStrFromBt(0);
VectorClassString vecStrParam(0);

MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

String lastStrToShow = "";
String BTstrReceived = "";
String lastBTstrReceived = "";
String inputString = "a:efe2;v:1;r:2|m:AB";

String option = "";
unsigned long foundAnim = 0;
unsigned long contLoop = 0;
int loopVelocity = 0;
int globalVelocity=0;
SoftwareSerial BTSerial(52, 53);
String strBt = "";
char charBT = '\0';
int sizeParams = 0;
bool isBtBuilding=false;
bool isStrUpdatedByBt=false;

void setup() {
    //ds("");
    dsl("------SETUP--------------------------");
    time = micros();
    lastTime = time;
    

#ifndef WAIT_TIME_LOOP
#define WAIT_TIME_LOOP 500000
#endif


#ifdef DEBUG_SERIAL
    Serial.begin(115200);
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
    
    difTime = WAIT_TIME_LOOP;
    loopWaitTime = WAIT_TIME_LOOP;

    calcLoopTime =loopWaitTime*DEFAULT_VELOCITY;
    difTime = calcLoopTime;

    globalVelocity=DEFAULT_VELOCITY;

    proccesActionFull(inputString, vecStr);
    sizeParams = vecStr.getSize();
    ds("sizeParams=")dsl(sizeParams);
    vecStr.print();
    

    
    
}

void loop() {
   
   
   dsd();
   dsl("LOOP");
   dsd();
    time = micros();
    contLoop++;

    //******************************************************************
    //*****CAPTURA DE BLUETHOT******************************************
    strBt = getBluetoot(BTSerial, charBT);
    
    
    if (charBT == '$') {
        vecStr.clear();
        isBtBuilding=true;
    }else if (strBt != "" && strBt != "-1") {
        
        getAndSetParams(strBt,          0,          option,     effectOption,
                        text,           velocity,   repeat,     globalVelocity,
                        globalStatus);


        if (option == "a" || option == "m") {
            isBtBuilding=true;
            vecStr.push(strBt);
            isStrUpdatedByBt=true;
            //vecStr.print();
            
        }else if (option == "iv" || option == "ip") {
            //vecStr.print();
            calcLoopTime =loopWaitTime*globalVelocity;
            ds("loopWaitTime=");dsl(loopWaitTime);            
            ds("globalVelocity=");dsl(globalVelocity);                        
            ds("calcLoopTime=");dsl(calcLoopTime);

            isBtBuilding=false;
            isStrUpdatedByBt=true;
            ds("iv/ip:strBt=");dsl(strBt);
        }
        
        strBt = "";
    }else if (charBT == '@') {
        sizeParams = vecStr.getSize();
        ds("@:strBt=");dsl(strBt);
        isBtBuilding=false;
    }
    dss();
    dsl("vecStr Antes de entrar")
    vecStr.print();
    dss();
    
    ds("globalVelocity=");dsl(globalVelocity);
    //______________________________________________________________________
    //--------CONTROL DE TIEMPO---------------------------------------------
    
    // calcLoopTime=(loopVelocity/loopWaitTime*globalVelocity);
    // ds("calcLoopTime=");dsl(calcLoopTime);
    ds("difTime=");ds(difTime);ds(" calcLoopTime=");dsl(calcLoopTime);
    ds("isBtBuilding=");dsl(isBtBuilding);
    ds("option=");dsl(option);
    
    if (!isBtBuilding && difTime >= calcLoopTime) {

        

        ds("contRepeat=");ds(contRepeat);ds(" repeat=");dsl(repeat);
        
        ds("Entro por tiempo=");dsl(contParam);

        //dsl("--->(1)-----------");    
        if ((dm.getIfIsStringEnd() && an.getIfAnimIsEnd()) || isStrUpdatedByBt) {
            dsl("--->(2)-----------");
            ds("c=");ds(contParam);
            //toMA UN PARAMETRO DEL VECTOR DE PARAMETROS
            getAndSetParamsOne(vecStr.get(contParam), option, effectOption, text, velocity, repeat, globalVelocity, globalStatus);

            if (option == "m" && (lastStrToShow != text)) {
                dsl("--->(2A)-----------");
                // Get the int codes and pass to array of each CHAR in the string
                dm.fillArrrayOfChars(vecChar, text);
                lastStrToShow = text;
                dm.setIfIsStringEnd(false);
            }else if (option == "a") {
                dsl("--->(2B)-----------");
                an.setIfisEnd(false);
            }
        }

   
        if (option == "m" && dm.canAddChar() && contCharAdded < vecChar.getSize()) {

            dsl("--->(3)-----------");

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


        if (option == "m") {

            dsl("--->(4)-----------");
            matrix.print();
            if (dm.getPosLastChar() > 0) {
                dsl("--->(4A)-----------");
                dm.GetFrame(matrix, aFrame);
                dm.moveMatrixToLeft(matrix);
            }
        }
        else if (option == "a" && !an.getIfAnimIsEnd()) {
            dsl("--->(4B)-----------");
            foundAnim = an.getAnim(aFrame, effectOption);

        }

        if (option == "a" || option == "m") {
            dsl("--->(5)-----------");
            sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
        }       
        
        if ((contCharAdded >= vecChar.getSize() && option == "m") || (an.getIfAnimIsEnd() && option == "a")) {
            dsl("--->(7)----------");
            // dsl("Entro a reset final");
            an.reset();
            contCharAdded = 0;
            dm.ResetInitPosMatrix();
            //dm.setIfIsStringEnd(false);
            dm.setIfIsStringEnd(true);
            matrix.clear();
            contRepeat++;
            contCharAdded = 0;
        }
        dsl("--->(8)-----------");
        ds("contParam=");ds(contParam);ds(" sizeParams=");dsl(sizeParams);
        ds("contRepeat=");ds(contRepeat);ds(" repeat=");dsl(repeat);

        if (contRepeat >= repeat) {
            contRepeat = 0;
            contParam++;
            dsl("--->(9)-----------");
            ds("contRepeat=");ds(contRepeat);ds(" contParam=");dsl(contParam);

            if (contParam >= sizeParams) {

                contParam = 0;
                dsl("--->(1)-----------");
                ds(" contParam=");dsl(contParam);
            }
        }

        lastTime = time;

    }
    
    difTime = time - lastTime;
    
  
}