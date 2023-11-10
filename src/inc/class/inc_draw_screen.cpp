
#include <Arduino.h>
#include "inc/include.h"

int DrawScreen::getPixX() {
  return this->pixX;
}
void DrawScreen::setPixX(int pixX) {
  this->pixX = pixX;
}

int DrawScreen::getPixY() {
  return this->pixY;
}
void DrawScreen::setPixY(int pixY) {
  this->pixY = pixY;
}


 int DrawScreen::GetMaxWidth(){
    return this->maxWidth;
  }

  void DrawScreen::SetMaxWidth(int maxWidth) {
    this->maxWidth = maxWidth;
  }

  int DrawScreen::GetMaxHeight(){
    return this->maxHeight;
  }

  void DrawScreen::SetMaxHeight(int maxHeight) {
    this->maxHeight = maxHeight;
  }

DrawScreen::DrawScreen() {
  //this.vecPins = new VectorClass(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

  convProgToArray(this->vecPins, C_Pins, (sizeof(C_Pins) / 2));

  dsl("");
}



void DrawScreen::setPantalla(MatrizLed& vPantalla) {
  this->pantalla = vPantalla;
}

int DrawScreen::GetPosArray(int x, int y ){

  if(x<GetMaxWidth() && y<GetMaxHeight()){
    return (y*7)+(x%7);
  }else{
    if(x>=GetMaxWidth()){ds("Bad pos X to led: ");dsl(x);}
    if(y>=GetMaxHeight()){ds("Bad pos y to led: ");dsl(y);}
    return -1;
  }
}

void DrawScreen::setPix(int x, int y, bool status) {
  int posInArray=-1;
  this->setPixX(x);
  this->setPixY(y);
  posInArray=GetPosArray(x,y);

  vecScreens.set(posInArray,status);
  
}

void DrawScreen::PrintPixel(int numPixel,int ledState){
  #ifdef IS_LCDSCREEN    
    int posX = 0;
    int posY = 0;
    posX = (int)(numPixel / 7);
    posY = (int)(numPixel % 7);    
    pantalla.setLed(0, posX, posY, ledState);
  #endif

  #ifdef IS_BIGSCREEN
    digitalWrite(pintToActive, ledState);
  #endif

  //this->pantalla.setLed(0, posX, posY, ledState);
}

void DrawScreen::PrintFrame(){
  int sizeArray=V_SCR_SIZE;

  for (int i = 0; i < sizeArray; i++) {

    PrintPixel(i,vecScreens.get(i));
  }

    /*
    posX = (int)(i / MATRIX_WIDTH);
    pinState = aFrame.get(i);
    pinNum = vecPins.get(i);
    if (pinState < 2) {
      if (lastPosX != posX) {
        dsl(" ");
        lastPosX = posX;
      }
      //dsl("===>es igual");
      if (aFrame.get(i) != aLastFrame.get(i)) {
        //        dsl("===>es distinto");
        aLastFrame.set(i, aFrame.get(i)); // update the values of matriz temp to only update the changed values
        ShowMatrix::PrintLed(i, pinNum, pinState);
      }
    }*/
  
}
