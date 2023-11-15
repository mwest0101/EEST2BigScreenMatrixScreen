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
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
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
DrawScreen dr;


int stateAction = 0;
String effectOption = "";
String text = "";
int contParam = 0;

int repeat = DEFAULT_REPEAT;
int contRepeat = 0;

int velocity = DEFAULT_VELOCITY;




int contCharAdded = 0;

unsigned long time = 0;
unsigned long lastTime = 0;
unsigned long difTime = 0;
unsigned long loopWaitTime = 0;


double promTime3 = 0;
unsigned long  loopTime = 0;
VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aFrame(V_SCR_SIZE, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(V_SCR_SIZE, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClassString vecStr(0);
VectorClassString vecStrFromBt(0);
VectorClassString vecStrParam(0);

MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

String lastStrToShow = "";
String BTstrReceived = "";
String lastBTstrReceived = "";

//String inputString = "a:efe2;v:1;r:2|m:AB";
String inputString = "a:efe1;v:1;r:1|a:efe2;v:1;r:1|a:efe3;v:1;r:1|a:efe4;v:1;r:1|a:efe5;v:1;r:1|a:efe3;v:1;r:1|a:efe4;v:1;r:1|a:efe5;v:1;r:1|a:efe6;v:1;r:1|a:efe7;v:1;r:1|a:tec1;v:1;r:1|a:tec2;v:1;r:1|a:tec3;v:1;r:1|a:tec4;v:1;r:1|a:tec5;v:1;r:1|a:tec6;v:1;r:1|m:Escuela";
//String inputString = "a:tet1;v:5;r:1;i:1|m:Escuela";



String option = "";
unsigned long foundAnim = 0;
unsigned long contLoop = 0;
int     loopVelocity = 0;
int     globalVelocity = DEFAULT_VELOCITY;
int     globalInvert = 0;
int     globalControl = 0;
String  globalStatus = "Play_Pres";
String  globalMode = "Pres";

int     invert = 0;

SoftwareSerial BTSerial(52, 53);
String strBt = "";
char charBT = '\0';
int sizeParams = 0;
bool isBtBuilding = false;
bool isStrUpdatedByBt = false;


String tempOption = "";
String tempEffectOption = "";
String tempText = "";
int tempVelocity = 0;
int tempRepeat = 0;
int tempInvert = 0;
int calcDirection = 0;
bool horizontalInvertFrame = false;
bool verticalInvertFrame = false;
int bandInvVert = 1;
int bandInvHori = 1;

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
    dr = DrawScreen();

#ifdef IS_LCDSCREEN
    pantalla.borrar();
    sm.setPantalla(pantalla);
    dr.setPantalla(pantalla);
#endif
    time = micros();
    convProgToArray(vecPins, C_Pins, (sizeof(C_Pins) / 2));

    difTime = WAIT_TIME_LOOP;
    //loopWaitTime = WAIT_TIME_LOOP;

    //loopTime =loopWaitTime*DEFAULT_VELOCITY;
    //loopTime =calcLoopTime(velocity,globalVelocity);


    difTime = loopTime;

    globalVelocity = DEFAULT_VELOCITY;

    proccesActionFull(inputString, vecStr);
    sizeParams = vecStr.getSize();
    ds("sizeParams=")dsl(sizeParams);
    vecStr.print();

    /*dr.setPix(1,1,1);
    dr.setPix(7,1,1);
    dr.setPix(1,5,1);
    dr.setPix(7,5,1);
    

    dr.PrintFrame();

    dr.Print(4,3,1);*/
    //dr.setCursor(4,3,1);
    // dr.SetPixTempX(4);
    // dr.SetPixTempY(3);  

    dr.setPosCursor(4,3);


}

void loop() {


    /*
    dsd();
    dsl("LOOP");
    dsd();
    */
   
    time = micros();
    contLoop++;

    
    strBt = getBluetoot(BTSerial, charBT);


    if (charBT == '$') {
        vecStr.clear();
        isBtBuilding = true;
    }
    else if (strBt != "" && strBt != "-1") {


        getAndSetParams(strBt, 0, tempOption,
            tempEffectOption, tempText,
            tempVelocity, tempRepeat, tempInvert,
            globalControl, globalInvert,
            globalVelocity, globalStatus,
            globalMode);


        if (tempOption == "a" || tempOption == "m") {
            isBtBuilding = true;
            vecStr.push(strBt);
            //isStrUpdatedByBt=true;
            //vecStr.print();

        }
        else if (tempOption == "iv" || tempOption == "ip" ||  tempOption == "ii" || 
                 tempOption == "ic" || tempOption == "id") {


            //vecStr.print();
            //loopTime =calcLoopTime(velocity,globalVelocity);

            ds("loopWaitTime=");dsl(loopWaitTime);
            ds("globalVelocity=");dsl(globalVelocity);
            ds("globalControl=");dsl(globalControl);
            ds("loopTime=");dsl(loopTime);

            isBtBuilding = false;
            //isStrUpdatedByBt=true;
            ds("iv/ip:strBt=");dsl(strBt);
        }

        strBt = "";
    }
    else if (charBT == '@') {
        sizeParams = vecStr.getSize();
        ds("@:strBt=");dsl(strBt);
        isBtBuilding = false;
    }


    


    //loopTime =calcLoopTime(velocity,globalVelocity);
    dss();
    dsl("vecStr Antes de entrar")
        //vecStr.print();
    dss();

    ds("globalVelocity=");dsl(globalVelocity);
    //______________________________________________________________________
    //--------CONTROL DE TIEMPO---------------------------------------------

    // loopTime=(loopVelocity/loopWaitTime*globalVelocity);
    // ds("loopTime=");dsl(loopTime);
    ds("difTime=");ds(difTime);ds(" loopTime=");dsl(loopTime);
    ds("isBtBuilding=");dsl(isBtBuilding);
    ds("option=");dsl(option);
    //================================================================
    //==MAIN DE MARQUE Y EFECTOS======================================

    loopTime = calcLoopTime(velocity, globalVelocity);

    if (!isBtBuilding && (difTime >= loopTime) && (globalStatus == "Play_Pres" || globalStatus == "Play_Flip")) {
        
        ds("contRepeat=");ds(contRepeat);ds(" repeat=");dsl(repeat);
        ds("Entro por tiempo=");dsl(contParam);

        //dsl("--->(1)-----------");    
        if ((dm.getIfIsStringEnd() && an.getIfAnimIsEnd())) {
            dsd();
            dsd();
            dsl("New parameter");
            dsd();
            dsl("--->(2)-----------");
            ds("c=");ds(contParam);
            //toMA UN PARAMETRO DEL VECTOR DE PARAMETROS
            getAndSetParamsOne(vecStr.get(contParam), option,
                effectOption, text,
                velocity, repeat, invert,
                globalControl, globalInvert,
                globalVelocity, globalStatus,
                globalMode);






            if (option == "m" && (lastStrToShow != text)) {
                dsl("--->(2A)-----------");
                // Get the int codes and pass to array of each CHAR in the string
                dm.fillArrrayOfChars(vecChar, text);
                lastStrToShow = text;
                dm.setIfIsStringEnd(false);

            }
            else if (option == "a") {
                dsl("--->(2B)-----------");

                an.setIfisEnd(false);
            }
            //loopTime =loopWaitTime*(velocity+(DEFAULT_VELOCITY-globalVelocity));
        //    loopTime =calcLoopTime(velocity,globalVelocity);
        }

        //loopTime =calcLoopTime(velocity,globalVelocity);
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

        calcDirection = invert * globalInvert;

        //if(globalInvert==1 || globalInvert==3){
        bandInvHori = 1;
        if (invert == 1 || invert == 3)       bandInvHori *= -1;
        if (globalInvert == 1 || globalInvert == 3) bandInvHori *= -1;
        if (bandInvHori == -1) sm.flipHorizontalFrame(aFrame);

        bandInvVert = 1;
        if (invert == 2 || invert == 3)       bandInvVert *= -1;
        if (globalInvert == 2 || globalInvert == 3) bandInvVert *= -1;
        if (bandInvVert == -1) sm.flipVerticalFrame(aFrame);

        if (option == "a" || option == "m") {
            dsl("--->(5)-----------");
            sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
        }

        if ((contCharAdded >= vecChar.getSize() && option == "m") || 
            (an.getIfAnimIsEnd() && option == "a")) {
                
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

    }else if (!isBtBuilding && globalStatus=="Play_Draw") {


        lastTime = time;
        //ds("tempOption=");dsl(tempOption);
        if(tempOption == "id"){
            //dsl("entre a tmepOption=id");
            if(globalControl ==1){dr.decY();globalControl=-1;dsl("Entre1");}
            if(globalControl ==2){dr.incX();globalControl=-1;dsl("Entre2");}
            if(globalControl ==3){dr.incY();globalControl=-1;dsl("Entre3");}
            if(globalControl ==4){dr.decX();globalControl=-1;dsl("Entre4");}
            if(globalControl ==0){dr.StampCursorInFrame();globalControl=-1;dsl("Entre4");}
            //if(globalControl ==0) dr.defX();

            
        }
        dr.PrintFrame();
        dr.UpdateCursor();
        

    }

    //================================================================
    //==MAIN DE DIBUJO======================================


    difTime = time - lastTime;


}






















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
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝