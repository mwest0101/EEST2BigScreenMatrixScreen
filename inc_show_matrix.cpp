#include "inc_show_matrix.h"
#include "inc_include.h"

ShowMatrix::ShowMatrix(int pinNumber)
{
  pin = pinNumber;
  
  pinMode(pin, OUTPUT);
}

void ShowMatrix::InitMatrix(int *aPins, int nFrameElements, MatrizLed vPantalla)
{
  pantalla=vPantalla;
  for (int i = 0; i < nFrameElements; i++)
  {
    pinMode(aPins[i], OUTPUT);
  }
  aLastFrame = convProgToArray(C_EMPTY, (sizeof(C_EMPTY) / 2));
}

void ShowMatrix::PrintData(int data){
  Serial.print("text");
}

void ShowMatrix::PrintLed(int ledNum,int pintToActive,int ledState){
    int posX = 0;
    int posY = 0;
    posX = (int)(ledNum / 7);
    posY = (int)(ledNum % 7);
    /*
    Serial.print("posX=");Serial.print(posX);
    Serial.print(" posY=");Serial.print(posY);
    Serial.print(" pintToActive=");Serial.print(pintToActive);
    Serial.print(" ledState=");Serial.print(ledState);

    Serial.println("");
    */
    if (IS_BIGSCREEN){
        digitalWrite(pintToActive, ledState);
    }else{
        pantalla.setLed(0, posX, posY, ledState);
    }
}

void ShowMatrix::PrintLedMatrix(int *aFrame, int *aPins, int nFrameElements)
{
  int pinState = 0;
  int pinNum = 0;
  int posX = 0;
  int posY = 0;
  int lastPosX = 0;
  Serial.println(" ");
  Serial.println("==============================");
  for (int i = 0; i < nFrameElements; i++)
  {
    posX = (int)(i / 7);
    posY = (int)(i % 7);
    

     if (DEBUG_MATRIX)
      {
        if (lastPosX != posX)
        {
          Serial.println(" ");
          lastPosX = posX;
        }
      //  Serial.print(pinState);
      //  Serial.print(" ");
      }
    pinState = aFrame[i];
    pinNum=aPins[i];
    if (pinState < 2 ){
   
      //Serial.print(" ps=");
      //Serial.print("(");
      
      /*
      if(aFrame[i] != aLastFrame[i]){    
        Serial.print("!=");
      }else{
        Serial.print("==");
      }
      */
      Serial.print(aFrame[i]);
      Serial.print(" ");
      

      //Serial.print(aLastFrame[i]);
      
    //Serial.println(" ");
    
      if(aFrame[i] != aLastFrame[i]){    
        
          aLastFrame[i] = aFrame[i]; // update the values of matriz temp to only update the changed values
          //Serial.print("aFrame[i]=");
          //Serial.println(aFrame[i]);

          /*
          Serial.print("i=");Serial.print(i);
          Serial.print("aPins[i]=");Serial.print(pinNum);
          Serial.print("pinState=");Serial.print(pinState);
          Serial.println("");
          */

          ShowMatrix::PrintLed(i,pinNum,pinState);
         // Serial.print("!=");
      }//else{
        //Serial.print("==");
      //}
      
     
    }
  }
}
