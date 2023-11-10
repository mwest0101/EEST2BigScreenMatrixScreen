
#include <Arduino.h>
#include "inc/include.h"

int DrawScreen::getPixX() {
  return this->pixX;
}
void DrawScreen::setPixX(int pixX) {
  this->pixX = pixX;
  if(pixY<1 || pixY>this->GetMaxHeight()){
    ds("DrawScreen::X Out of range:: ");dsl(pixX);
    
    
  }else{
    this->pixX = pixX;
  }
}

int DrawScreen::getPixY() {
  return this->pixY;
}
void DrawScreen::setPixY(int pixY) {
  if(pixY<1 || pixY>this->GetMaxHeight()){
    ds("DrawScreen::Y Out of range: ");dsl(pixY);    
  }else{
    this->pixY = pixY;
  }
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
  bool DrawScreen::GetStartDraw(){
    return this->startDraw;
  }

  void DrawScreen::SetStartDraw(bool value) {
    this->startDraw=value;
  }


  void DrawScreen::incX(){
    this->setPixX(this->pixX++);
  }
  void DrawScreen::decX(){
    this->setPixX(this->pixX--);
    
  }
  void DrawScreen::incY(){
    
    this->setPixX(this->pixY++);
  }
  void DrawScreen::decY(){
    
    this->setPixX(this->pixY--);
  }

  void DrawScreen::stampPixel(){
    this->setPix(this->pixX,this->pixY,1);
  }
DrawScreen::DrawScreen() {
  //this.vecPins = new VectorClass(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);

  dsl("");
}



void DrawScreen::setPantalla(MatrizLed& vPantalla) {
  this->pantalla = vPantalla;
}

int DrawScreen::GetPosArray(int x, int y ){

  
    return ((y-1)*7)+((x-1)%7);
  
  
}

void DrawScreen::setPix(int x, int y, bool status) {
  int posInArray=-1;
  this->setPixX(x);
  this->setPixY(y);
  posInArray=GetPosArray(x,y);
  vecScreens[posInArray]=status;  
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
    digitalWrite(vecPins[numPixel], ledState);
  #endif

  //this->pantalla.setLed(0, posX, posY, ledState);
}

void DrawScreen::Print(){
  int sizeArray=V_SCR_SIZE;

  for (int i = 0; i < sizeArray; i++) {

    PrintPixel(i,vecScreens[i]);
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
