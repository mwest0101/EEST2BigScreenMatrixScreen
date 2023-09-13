#include "inc_include.h"
//#include "inc_show_matrix.h"


ShowMatrix::ShowMatrix()
{
  debugl("");
}


void::InitShowMatrix(VectorClass vecPins, MatrizLed vPantalla)
{
  pantalla=vPantalla;
  //aPins=vaPins;
  //nElements=nFrameElements;
  
  VectorClass tempVectorLastFrame(35, 0, 10);

  for (int i = 0; i < vecPins.getSize(); i++)
  {
    pinMode(vecPins.get(i), OUTPUT);
    //debug(vaPins[i]);
  }
  //debugl("");
  
  tempVectorLastFrame = convProgToArray(C_EMPTY, 0, (sizeof(C_EMPTY) / 2));
  
  
  
  
  
}

void ShowMatrix::PrintData(int data){
  debug(data);
  debug("text");
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
  /*
  debugl("");  
  debugl("___________________________________________");*/
  
  lastPosX = posX;
  for (int i = 0; i < nElements; i++)
  {
    
    //posY = (int)(i % 7);   
    
   
    posX = (int)(i / MATRIX_WIDTH);
    pinState=vlFrame[i];
    pinNum=aPins[i];

    if (pinState < 2 ){
      if (lastPosX != posX){
          debugl(" ");
          lastPosX = posX;
        } 
      
        #ifdef DEBUG_MATRIX
          debug("|");         
          debug(pinState);          
          //debug("|");
          //debuge(" ");
         /*
          debug("|");
          debug(i);
          debug(":");
          debug(pinState);
          debug(":");
          debug(pinNum);
          debuge("|");
          debuge(" ");
          */
        #endif
      if(vlFrame[i] != aLastFrame[i]){            
          aLastFrame[i] = pinState; // update the values of matriz temp to only update the changed values
          ShowMatrix::PrintLed(i,pinNum,pinState);       
      }           
    }
  
  }
  
  
}
