
#include <Arduino.h>
#include "inc_include.h"
ShowMatrix::ShowMatrix()
{

  dsl("");
}
#ifdef IS_LCDSCREEN
void ShowMatrix::setPantalla(MatrizLed &vPantalla)
{
  this->pantalla = vPantalla;
}
#endif
void ShowMatrix::InitShowMatrix(VectorClass vecPins)
{

  // aPins=vaPins;
  // nElements=nFrameElements;
  // VectorClass tempVectorLastFrame(35, 0, 10);
  for (int i = 0; i < vecPins.getSize(); i++)
  {

    pinMode(vecPins.get(i), OUTPUT);
    // ds(vaPins[i]);
  }
  // dsl("");
  // tempVectorLastFrame = convProgToArray(C_EMPTY, 0, (sizeof(C_EMPTY) / 2));
}
//____________________________________________________________________
//------------Function------------------------------------------------
void ShowMatrix::PrintData(int data)
{

  ds(data);
  ds("text");
}
//____________________________________________________________________
//------------Function------------------------------------------------
void ShowMatrix::PrintLed(int ledNum, int pintToActive, int ledState)
{



#ifdef IS_BIGSCREEN

  digitalWrite(pintToActive, ledState);
#endif

#ifdef IS_LCDSCREEN
  int posX = 0;
  int posY = 0;
  posX = (int)(ledNum / 7);
  posY = (int)(ledNum % 7);

   ds3l("IS_LCDSCREEN");
   ds3("posX:");
   ds3(posX);
   ds3("| posY:");
   ds3(posY);
   ds3("| ledState:");
   ds3l(ledState);

   

  this->pantalla.setLed(0, posX, posY, ledState);

#endif
}
//____________________________________________________________________
//------------Function------------------------------------------------
void ShowMatrix::PrintLedMatrix(VectorClass &aFrame, VectorClass &aLastFrame, VectorClass &vecPins)
{

  int pinState = 0;
  int pinNum = 0;
  int posX = 0;
  int lastPosX = 0;
  
  lastPosX = posX;
  for (int i = 0; i < 35; i++)
  {

    posX = (int)(i / MATRIX_WIDTH);
    pinState = aFrame.get(i);
    pinNum = vecPins.get(i);
    if (pinState < 2)
    {
      if (lastPosX != posX)
      {
        dsl(" ");
        lastPosX = posX;
      }
      //dsl("===>es igual");
      if (aFrame.get(i) != aLastFrame.get(i))
      {
      //        dsl("===>es distinto");
        aLastFrame.set(i, aFrame.get(i)); // update the values of matriz temp to only update the changed values
        ShowMatrix::PrintLed(i, pinNum, pinState);
      }
    }
  }
}
