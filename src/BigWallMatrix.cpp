#include <Arduino.h>
#include "inc_include.h"



  
BigWallMatrix::BigWallMatrix()
{

    dsl("");
    #ifdef IS_LCDSCREEN
    MatrizLed vPantalla;
    
    #endif
    // this->time = micros();
    // this->lastTime = time;
    // this->waitTime = WAIT_TIME_LOOP;

   
    #ifdef DEBUG_SERIAL
        Serial.begin(9600);
    #endif

    #ifdef DEBUG
        debug_init();
    #endif
    
    #ifdef IS_LCDSCREEN
        vPantalla.begin(12, 11, 10, 1); // dataPin, clkPin, csPin, numero de matrices de 8x8
        vPantalla.setIntensidad(1);
    #endif

    #ifdef IS_LCDSCREEN
        vPantalla.borrar();
        
    #endif

    convProgToArray(vecPins, C_Pins, (sizeof(C_Pins) / 2));
    vecPins.print();

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
        this->dm.fillArrrayOfChars(this->vecChar, this->strToShow);

        if (this->contCharAdded > vecChar.getSize())
            this->contCharAdded = 0;
        this->canAddChar = this->dm.canAddChar();
        this->getIfisEnd = pm.getIfisEnd();

        ds("canAddChar=");
        dsl(this->canAddChar);
        ds("getIfisEnd=");
        dsl(this->getIfisEnd);

        // if (pm.getIfisEnd() && this->dm.canAddChar())
        if (this->action != 15 && this->dm.canAddChar())
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
        this->an.getAnim(this->aFrame, this->strOption);

        dsl("Despues de if strOption");
        ds(" strOption: ");
        dsl(this->strOption);
    }

    if (action == 0)
    {
        this->aFrame.reset();
        this->dm.GetFrame(this->matrix,this->aFrame);
        this->matrix.print();
    }

    if (action == 0 || action == 15)
    {
        dsl("Antes de imprimir");
        this->aFrame.print();
    }

    sm.PrintLedMatrix(aFrame, aLastFrame, vecPins);
    if (action == 0 && this->dm.getPosLastChar() > 0)
    {
        this->dm.moveMatrixToLeft(this->matrix);
    }

    //}
    // this->matrix.print();
    if (this->an.getIfisEnd())
    {
        this->an.reset();
        strOption = "";
        action = 0;
        // action = 0;
    }
    ds("action=");
    dsl(action);
}
