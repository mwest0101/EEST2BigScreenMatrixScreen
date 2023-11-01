

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
int globalVelocity = 0;
String globalStatus = "play";


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

//int repeat = 0;

VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClassString vecStr(0);

//VectorClassString vecStrOne(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClassString vecStrFromBt(0);
VectorClassString vecStrParam(0);

MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

String lastStrToShow = "";
String BTstrReceived = "";
String lastBTstrReceived = "";
//String inputString = "a:aefe1;x:1;v:2|m:tést de, texto";
//String inputString = "a:aefe1";
String inputString = "a:efe1|a:efe2|a:efe3|a:efe4|a:efe5|a:efe6|a:efe7|a:tec1|a:tec2|a:tec3|a:tec4|a:tec5|a:tec6|m:E.E.S.T. Nº2";
//String inputString = "a:efe2;v:1;r:2|m:AB";

String option = "";
unsigned long foundAnim = 0;
unsigned long contLoop = 0;
unsigned long loopVelocity = 0;
SoftwareSerial BTSerial(52, 53);
String strBt = "";
char charBT = '\0';
int sizeParams = 0;


void setup() {
    dsd();
    dsl("------SETUP--------------------------");
    time = micros();
    lastTime = time;
    difTime = WAIT_TIME_LOOP;
    waitTime = WAIT_TIME_LOOP;

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
    difTime = waitTime;
    loopVelocity = waitTime * DEFAULT_VELOCITY;
    proccesActionFull(inputString, vecStr);
    sizeParams = vecStr.getSize();
    ds("sizeParams=")dsl(sizeParams);
    vecStr.print();
}

void loop() {
    time = micros();
    contLoop++;

    //******************************************************************
    //*****CAPTURA DE BLUETHOT******************************************
    strBt = getBluetoot(BTSerial, charBT);

    if (charBT == '$') {
        vecStr.clear();
    }
    if (strBt != "" && strBt != "-1") {
        getAndSetParams(strBt, 0, option, effectOption,
            text, velocity, repeat, globalVelocity,
            globalStatus);


        if (option == "a" || option == "m") {
            vecStr.push(strBt);
        }
        else if (option == "iv" || option == "ip") {
            vecStr.print();
        }
        strBt = "";
    }
    if (charBT == '@') {

        sizeParams = vecStr.getSize();
        // ds("Se modifico vecStr= ");vecStr.print();dsl();
        // ds("Size vecStr= ");vecStr.getSize();dsl();
        //contRepeat=repeat;
        //vecStr.print();
    }

    //******************************************************************



    //******************************************************************
    //*****CONTROL DE TIEMPO********************************************

    if (difTime >= loopVelocity) {
        // dss();

        // //if(contLoop>3000){
        // dss()
        // dsl("--->(0)-----------");   
        ds("contRepeat=");ds(contRepeat);ds(" repeat=");dsl(repeat);
        // ds("contParam=");ds(contParam);ds(" sizeParams=");dsl(sizeParams);
        // dsl("..####....####...##..##..######..........#####....####...#####....####...##...##.");
        // dsl(".##..##..##..##..###.##....##............##..##..##..##..##..##..##..##..###.###.");
        // dsl(".##......##..##..##.###....##............#####...######..#####...######..##.#.##.");
        // dsl(".##..##..##..##..##..##....##............##......##..##..##..##..##..##..##...##.");
        // dsl("..####....####...##..##....##....######..##......##..##..##..##..##..##..##...##.");
        // dsl(".................................................................................");

       

        dss();

        //controla que haya terminado las animciones y marquee
        ds("Entro por tiempo=");dsl(contParam);

        // ds("dm.getIfIsStringEnd()=");   ds(dm.getIfIsStringEnd());
        // ds(" an.getIfAnimIsEnd()");      dsl(an.getIfAnimIsEnd());

        //dsl("--->(1)-----------");    
        if (dm.getIfIsStringEnd() && an.getIfAnimIsEnd()) {
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
            }
            if (option == "a") {
                dsl("--->(2B)-----------");
                an.setIfisEnd(false);
            }
        }

        //--------------------------------------------------------------------            
        // Si la opcion es marquee y se puede agregar un caracter a la matriz
        // lo agrega
        // ds("option =");ds(option);
        // ds(" dm.canAddChar()=");ds(dm.canAddChar());
        // ds(" contCharAdded =");ds(contCharAdded);
        // ds(" vecChar.getSize()=");ds(vecChar.getSize());
        // dss()
        // dsl("--->(5)-----------");    
        if (option == "m" && dm.canAddChar() && contCharAdded < vecChar.getSize()) {

            dsl("--->(3)-----------");
            // //dsl()
            // dsl(".######..######..##..##..######.");
            // dsl("...##....##.......####.....##...");
            // dsl("...##....####......##......##...");
            // dsl("...##....##.......####.....##...");
            // dsl("...##....######..##..##....##...");
            // dsl("................................");

            ds("contCharAdded=");dsl(contCharAdded);
            aIntCharMatrix.clear();
            getCharMatrix(aIntCharMatrix, vecChar.get(contCharAdded));
            dm.AddConsToMatrix(matrix, aIntCharMatrix, vecChar.get(contCharAdded));
            dm.setCanAddChar(false);


            contCharAdded++;
        }




        //--------------------------------------------------------------------


            //--------------------------------------------------------------------
            // si la opcion es marquee y se puede mover se mueve la matriz hacia
            // la izquierda hasta que llega a 0
        dss();

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

            // dsl("..####...##..##..######..##...##.");
            // dsl(".##..##..###.##....##....###.###.");
            // dsl(".######..##.###....##....##.#.##.");
            // dsl(".##..##..##..##....##....##...##.");
            // dsl(".##..##..##..##..######..##...##.");
            // dsl(".................................");


            foundAnim = an.getAnim(aFrame, effectOption);
            // dsl("Paso m por acá->a 2");
        }

        // dss();
        // //--Enciende las luces o la matriz led.
        // dsl("--->if(option == a || option == m sm.PrintLedMatrix");
        if (option == "a" || option == "m") {
            dsl("--->(5)-----------");
            sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
        }
        /*
        if (contCharAdded >= vecChar.getSize()) {
            dsl("--->(6)-----------");
            contCharAdded = 0;
            ds("Setea a 0 contCharAdded=");dsl(contCharAdded);
            dm.setIfIsStringEnd(true);
        }*/

        //si llegal final de los efectos o animaciones reinicializa todo y cuenta una repeticion
        // dss();

        // dsl("--->(10)----------");    
        // ds("contCharAdded=")dsl(contCharAdded);
        // ds("vecChar.getSize()=")dsl(vecChar.getSize());
        // ds("dm.getIfIsStringEnd()=")dsl(dm.getIfIsStringEnd());
        // ds("an.getIfAnimIsEnd()=")dsl(an.getIfAnimIsEnd());                
        
        // dm.getIfIsStringEnd()) && 
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
    
        // dsl("--->(11)----------");    
        // ds("contRepeat=")dsl(contRepeat);
        // ds("contCharAdded=")dsl(contCharAdded);
        // ds("vecChar.getSize()=")dsl(vecChar.getSize());
        // ds("dm.getIfIsStringEnd()=")dsl(dm.getIfIsStringEnd());
        // ds("an.getIfAnimIsEnd()=")dsl(an.getIfAnimIsEnd());   

        //contLoop=0;

        lastTime = time;

    }
    difTime = time - lastTime;

}