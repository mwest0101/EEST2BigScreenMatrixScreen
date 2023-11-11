
#include <Arduino.h>
#include "inc/include.h"

int DrawScreen::getPixX() {
  return this->pixX;
}
void DrawScreen::setPixX(int pixX) {
  this->pixX = pixX;
  if(pixX<1 || pixX>this->GetMaxWidth()){
    ds("DrawScreen::X Out of range:: ");dsl(pixX);
    
    
  }else{

    this->pixX = (pixX-1);
    //ds("DrawScreen::X Setted to:");dsl(this->pixX);
  }
}

int DrawScreen::getPixY() {
  return this->pixY;
}
void DrawScreen::setPixY(int pixY) {
  
  if(pixY<1 || pixY>this->GetMaxHeight()){
    ds("DrawScreen::Y Out of range: ");dsl(pixY);    
  }else{
    this->pixY = (pixY-1);
    //ds("DrawScreen::Y Setted to:");dsl(this->pixY);
  }
}
  int DrawScreen::GetPixTempX(){
    return this->pixTempX;
  }

  void DrawScreen::SetPixTempX(int pixTempX) {
    if(pixTempX<1 || pixTempX>this->GetMaxHeight()){
      ds("DrawScreen::Y Out of range: ");dsl(pixY);    
    }else{
      this->pixTempX = (pixTempX-1);
    //ds("DrawScreen::Y Setted to:");dsl(this->pixY);
    }

    
  }

  int DrawScreen::GetPixTempY() {
    return this->pixTempY;
  }

  void DrawScreen::SetPixTempY(int pixTempY) {
    if(pixTempY<1 || pixTempY>this->GetMaxHeight()){
      ds("DrawScreen::Y Out of range: ");dsl(pixY);    
    }else{
      this->pixTempY = (pixTempY-1);
    
    }
    
  }
  int DrawScreen::getCursorState() {
    return this->cursorState;
  }

  void DrawScreen::setCursorState(int cursorState) {
    this->cursorState = cursorState;
  }

  int DrawScreen::getTimeCursorBlink() {
    return this->timeCursorBlink;
  }

  void DrawScreen::setTimeCursorBlink(int timeCursorBlink) {
    this->timeCursorBlink = timeCursorBlink;
  }

  int DrawScreen::getTimeLapse() {
    return this->timeLapse;
  }

  void DrawScreen::setTimeLapse(int timeLapse) {
    this->timeLapse = timeLapse;
  }

  int DrawScreen::getTime() {
    return this->time;
  }

  void DrawScreen::setTime(int time) {
    this->time = time;
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
  this->timeCursorBlink=TIME_CURSOR_BLINK;

  dsl("");
}



void DrawScreen::setPantalla(MatrizLed& vPantalla) {
  this->pantalla = vPantalla;
}

int DrawScreen::GetPosArray(){
    return (this->getPixY()*7)+(this->getPixX()%7);    
}

void DrawScreen::setPix(int x, int y, bool status) {
  int posInArray=0;
  this->setPixX(x);
  this->setPixY(y);  
  
  posInArray=GetPosArray();
  //ds("DrawScreen::setPix : GetPosArray():");dsl(GetPosArray());

  vecScreens[posInArray]=status;  
}

void DrawScreen::setCursor(int x, int y, int ledState) {
  
  this->SetPixTempX(x);
  this->SetPixTempY(y);  
  this->PrintDirect(this->GetPixTempX(),this->GetPixTempY(),ledState);
  //posInArray=GetPosArray();
  //ds("DrawScreen::setPix : GetPosArray():");dsl(GetPosArray());

  //vecScreens[posInArray]=status;  
}

void DrawScreen::Print(int x,int y,int ledState){
  
  
  if(x<1 || x>this->GetMaxWidth()){
    ds("DrawScreen::PrintPixel X Out of range:: ");dsl(x);    
  
  }else if(y<1 || y>this->GetMaxHeight()){
    ds("DrawScreen::PrintPixel Y Out of range:: ");dsl(y);    
  }else{
    x=x-1;
    y=y-1;
    
    ds("x:");ds(x);
    ds(" y:");dsl(y);
    this->PrintDirect(x,y,ledState);

  }
  
}
void DrawScreen::PrintDirect(int x, int y, int ledState){
  #ifdef IS_LCDSCREEN      
    pantalla.setLed(0, y, x, ledState);
  #endif

  #ifdef IS_BIGSCREEN
    int numPixel=0;
    numPixel=(y*7)+x;    
    digitalWrite(vecPins[numPixel], ledState);
  #endif
}

void DrawScreen::PrintPixelByFrame(int numPixel,int ledState){
  #ifdef IS_LCDSCREEN    
    int posY = 0;
    int posX = 0;
    posY = (int)(numPixel / 7);
    posX = (int)(numPixel % 7);    
    
    //ds("posY:");ds(posY);ds(" posX:");ds(posX);ds(" ledState:");dsl(ledState);

    pantalla.setLed(0, posY, posX, ledState);
  #endif

  #ifdef IS_BIGSCREEN
    digitalWrite(vecPins[numPixel], ledState);
  #endif

  //this->pantalla.setLed(0, posY, posX, ledState);
}


void DrawScreen::PrintFrame(){
  int sizeArray=V_SCR_SIZE;

  for (int i = 0; i < sizeArray; i++) {
    //ds("DrawScreen::Print : vecScreens[i]:");dsl(vecScreens[i]);
    PrintPixelByFrame(i,vecScreens[i]);
  }

    /*
    posY = (int)(i / MATRIX_WIDTH);
    pinState = aFrame.get(i);
    pinNum = vecPins.get(i);
    if (pinState < 2) {
      if (lastPosY != posY) {
        dsl(" ");
        lastPosY = posY;
      }
      //dsl("===>es igual");
      if (aFrame.get(i) != aLastFrame.get(i)) {
        //        dsl("===>es distinto");
        aLastFrame.set(i, aFrame.get(i)); // update the values of matriz temp to only update the changed values
        ShowMatrix::PrintLed(i, pinNum, pinState);
      }
    }*/
  
}
