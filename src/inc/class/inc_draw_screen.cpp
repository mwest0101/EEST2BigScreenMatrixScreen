
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
  //digitalWrite(pintToActive, ledState);

  //this->pantalla.setLed(0, posX, posY, ledState);
}

