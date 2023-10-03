#include <Arduino.h>
#include "inc_include.h"



  
BigWallMatrix::BigWallMatrix()
{

    dsl("");
    #ifdef IS_LCDSCREEN
    void setPantalla(MatrizLed &vPantalla);
    #endif
    this->time = micros();
    this->lastTime = time;
    this->waitTime = WAIT_TIME_LOOP;

    // this->vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    // this->aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    // this->vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    // this->vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    // this->matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    // this->aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    // this->aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    VectorClass vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
    VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

    MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);


    DriveMatrix dm();
    ShowMatrix sm();
    ProgmemManager pm();
    AnimManager an();

    //this->sm = ShowMatrix();
    //this->dm = DriveMatrix();
    //this->pm = ProgmemManager();
    //this->an = AnimManager();
    // difTime = 0;

    #ifdef DEBUG_SERIAL
        Serial.begin(9600);
    #endif

    #ifdef DEBUG
        debug_init();
    #endif
    
    #ifdef IS_LCDSCREEN
        this->pantalla.begin(12, 11, 10, 1); // dataPin, clkPin, csPin, numero de matrices de 8x8
        this->pantalla.setIntensidad(1);
    #endif

    #ifdef IS_LCDSCREEN
        this->pantalla.borrar();
        ShowMatrix::setPantalla(this->pantalla);
    #endif

    convProgToArray(this->vecPins, C_Pins, (sizeof(C_Pins) / 2));
    this->vecPins.print();

}
/*
void BigWallMatrix::init()
{
    
}*/

void BigWallMatrix::setText(String text)
{
    this->strToShow = text;
}
bool BigWallMatrix::ifWaitTime()
{
    //int difTime = 0;
    this->time = micros();
    this->difTime = this->time - this->lastTime;

    if (this->difTime >= this->waitTime)
    {
        this->lastTime = this->time;
        return true;
    }
    else
    {
        return false;
    }
}

void BigWallMatrix::getTime()
{
    this->lastTime = this->time;
}
// Secuencia de la matriz
void BigWallMatrix::nextFrame()
{
    if (this->ifWaitTime())
    {
        dsd();
        dsl("LOOP in timeout");
        this->getTime();
        DriveMatrix::fillArrrayOfChars(this->vecChar, this->strToShow);

        if (this->contCharAdded > vecChar.getSize())
            this->contCharAdded = 0;
        this->canAddChar = dm.canAddChar();
        this->getIfisEnd = pm.getIfisEnd();

        ds("canAddChar=");
        dsl(this->canAddChar);
        ds("getIfisEnd=");
        dsl(this->getIfisEnd);

        // if (pm.getIfisEnd() && dm.canAddChar())
        if (this->action != 15 && dm.canAddChar())
        {
            dss();
            dsl("Inicio de proceso");
            this->charReaded = (char)this->vecChar.get(this->contCharAdded);
            this->strOption = concParamsOfString(this->charReaded, this->strOption, this->action);

            this->contCharAdded++;
        }
        else
        {
            dss();
            ds("Entra a captura de texto a concatenar:");
            ds(this->contCharAdded++);
            firstPass = 1;
        }
    }
    if (action == 15)
    {
        an.getAnim(this->aFrame, this->strOption);

        dsl("Despues de if strOption");
        ds(" strOption: ");
        dsl(this->strOption);
    }

    if (action == 0)
    {
        this->aFrame.reset();
        dm.GetFrame(this->aFrame);
        this->matrix.print();
    }

    if (action == 0 || action == 15)
    {
        dsl("Antes de imprimir");
        this->aFrame.print();
    }

    sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
    if (action == 0 && dm.getPosLastChar() > 0)
    {
        dm.moveMatrixToLeft(matrix);
    }

    //}
    // matrix.print();
    if (an.getIfisEnd())
    {
        an.reset();
        strOption = "";
        action = 0;
        // action = 0;
    }
    ds("action=");
    dsl(action);
}
