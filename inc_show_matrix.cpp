#include "inc_include.h"
//#include "inc_show_matrix.h"


ShowMatrix::ShowMatrix()
{
  Serial.println("");
}


void ShowMatrix::InitShowMatrix(int *aPins, int nFrameElements, MatrizLed vPantalla)
{
  pantalla=vPantalla;
  for (int i = 0; i < nFrameElements; i++)
  {
    pinMode(aPins[i], OUTPUT);
  }
  aLastFrame = convProgToArray(C_EMPTY, (sizeof(C_EMPTY) / 2));
}

void ShowMatrix::PrintData(int data){
  Serial.print(data);
  Serial.print("text");
}

void ShowMatrix::PrintLed(int ledNum,int pintToActive,int ledState){
    int posX = 0;
    int posY = 0;
    posX = (int)(ledNum / 7);
    posY = (int)(ledNum % 7);

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
  //int posY = 0;
  int lastPosX = 0;
  //int ia=0;
  
  debugl("");  
  debugl("___________________________________________");
  

  for (int i = 0; i < nFrameElements; i++)
  {
    posX = (int)(i / 7);
    //posY = (int)(i % 7);   
    
     if (DEBUG_MATRIX){
        if (lastPosX != posX){
          debugl(" ");
          lastPosX = posX;
        }      
      }

    pinState = aFrame[i];
    pinNum=aPins[i];
    if (pinState < 2 ){
   
      if (DEBUG_MATRIX){
        debuge(pinState);
        //dd(" ");
      }
    
      if(aFrame[i] != aLastFrame[i]){            
          aLastFrame[i] = pinState; // update the values of matriz temp to only update the changed values
          ShowMatrix::PrintLed(i,pinNum,pinState);       
      }           
    }
  }
}
