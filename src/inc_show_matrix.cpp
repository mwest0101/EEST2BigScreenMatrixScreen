#include "inc_include.h"
//#include "inc_show_matrix.h"


ShowMatrix::ShowMatrix()
{
  Serial.println("");
}


void ShowMatrix::InitShowMatrix(int *vaPins, int nFrameElements, MatrizLed vPantalla)
{
  pantalla=vPantalla;
  aPins=vaPins;
  nElements=nFrameElements;
  for (int i = 0; i < nFrameElements; i++)
  {
    pinMode(aPins[i], OUTPUT);
    debug(vaPins[i]);
  }
  debugl("");
  aLastFrame = convProgToArray(C_EMPTY,0, nFrameElements);
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

void ShowMatrix::PrintLedMatrix(int *vlFrame)
{
  int pinState = 0;
  int pinNum = 0;
  int posX = 0;
  int lastPosX = 0;
  
  debugl("");  
  debugl("___________________________________________");
  
  lastPosX = posX;
  for (int i = 0; i < nElements; i++)
  {
    
    //posY = (int)(i % 7);   
    
     if (DEBUG_MATRIX){
        if (lastPosX != posX){
          debugl(" ");
          lastPosX = posX;
        }      
      }
    posX = (int)(i / MATRIX_WIDTH);
    pinState=vlFrame[i];
    pinNum=aPins[i];

    //if (pinState < 2 ){
   
      if (DEBUG_MATRIX){
        debug("|");
        debug(i);
        debug(":");
        debug(pinState);
        debug(":");
        debug(pinNum);
        debug("|");
        debuge(" ");
        //dd(" ");
       }
    
      if(vlFrame[i] != aLastFrame[i]){            
          aLastFrame[i] = pinState; // update the values of matriz temp to only update the changed values
          ShowMatrix::PrintLed(i,pinNum,pinState);       
      }           
    //}
  
  }
  
  
}
