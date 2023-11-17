
// ╔══════════════════════════════════════════════════════════════════╗
// ║   ____    _             __  __           _            _          ║
// ║  |  _ \  (_)           |  \/  |         | |          (_)         ║
// ║  | |_) |  _    __ _    | \  / |   __ _  | |_   _ __   _  __  __  ║
// ║  |  _ <  | |  / _` |   | |\/| |  / _` | | __| | '__| | | \ \/ /  ║
// ║  | |_) | | | | (_| |   | |  | | | (_| | | |_  | |    | |  >  <   ║
// ║  |____/  |_|  \__, |   |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\  ║
// ║                __/ |                                             ║
// ║               |___/                                              ║
// ║                                                                  ║
// ║  _         _____   _____      _____                           _  ║
// ║ | |       / ____| |  __ \    |  __ \                         | | ║
// ║ | |      | |      | |  | |   | |__) |   __ _   _ __     ___  | | ║
// ║ | |      | |      | |  | |   |  ___/   / _` | | '_ \   / _ \ | | ║
// ║ | |____  | |____  | |__| |   | |      | (_| | | | | | |  __/ | | ║
// ║ |______|  \_____| |_____/    |_|       \__,_| |_| |_|  \___| |_| ║
// ║                                                                  ║
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝

#include <Arduino.h>
#include "inc/include.h"

int DrawScreen::getPixX() {
  return this->pixX;
}
void DrawScreen::setPixX(int vPixX) {

  if(vPixX>=0 && vPixX<this->GetMaxWidth()){
    this->pixX = vPixX;
  }else{
    ds("DrawScreen::Y Out of range: ");dsl(vPixX);       
  }
}

int DrawScreen::getPixY() {
  return this->pixY;
}
void DrawScreen::setPixY(int vPixY) {  
  if(vPixY>=0 && vPixY<this->GetMaxHeight()){
    this->pixY = vPixY;
  }else{
    ds("DrawScreen::Y Out of range: ");dsl(vPixY);       
  }    
}
  int DrawScreen::GetPixTempX(){
    //ds("this->pixTempX=");dsl(this->pixTempX);
    return this->pixTempX;
  }

  void DrawScreen::SetPixTempX(int vPixTempX) {
    
    if(vPixTempX>=0 && vPixTempX<this->GetMaxWidth()){
      this->pixTempX = vPixTempX;
    }else{
      ds("DrawScreen::Y Out of range: ");dsl(vPixTempX);       
    }        
  }

  int DrawScreen::GetPixTempY() {
    //ds("this->pixTempY=");dsl(this->pixTempY);
    return this->pixTempY;
  }

  void DrawScreen::SetPixTempY(int vPixTempY) {
    if(vPixTempY>=0 && vPixTempY<this->GetMaxHeight()){
      this->pixTempY = vPixTempY;
    }else{
      ds("DrawScreen::Y Out of range: ");dsl(vPixTempY);       
    }     
    
  }

  bool DrawScreen::getCursorState() {
    return this->cursorState;
  }

  void DrawScreen::setCursorState(bool vCursorState) {
    this->cursorState = vCursorState;
  }

  unsigned long DrawScreen::getTimeCursorBlink() {
    return this->timeCursorBlink;
  }

  void DrawScreen::setTimeCursorBlink(unsigned long vTimeCursorBlink) {
    this->timeCursorBlink = vTimeCursorBlink;
  }

  
  // unsigned long DrawScreen::getTimeCursorFinal() {
  //   return this->timeCursorFinal;
  // }

  // void DrawScreen::setTimeCursorFinal(unsigned long vTimeCursorFinal) {
  //   this->timeCursorFinal = vTimeCursorFinal;
  // }

  unsigned long DrawScreen::getTimeLapse() {
    return this->timeLapse;
  }

  void DrawScreen::setTimeLapse(unsigned long vTimeLapse) {
    this->timeLapse = vTimeLapse;
  }

  unsigned long DrawScreen::getTime() {
    return this->time;
  }

  void DrawScreen::setTime(unsigned long vTime) {
    this->time = vTime;
  }
  unsigned long DrawScreen::getTimeLast() {
    return this->timeLast;
  }

  void DrawScreen::setTimeLast(unsigned long vTimeLast) {
    this->timeLast = vTimeLast;
  }
 int DrawScreen::GetMaxWidth(){
    return this->maxWidth;
  }

  void DrawScreen::SetMaxWidth(int vMaxWidth) {
    this->maxWidth = vMaxWidth;
  }

  int DrawScreen::GetMaxHeight(){
    return this->maxHeight;
  }

  void DrawScreen::SetMaxHeight(int vMaxHeight) {
    this->maxHeight = vMaxHeight;
  }
  bool DrawScreen::GetStartDraw(){
    return this->startDraw;
  }

  void DrawScreen::SetStartDraw(bool value) {
    this->startDraw=value;
  }


  void DrawScreen::incX(){

    this->PrintDirect(this->GetPixTempX(),this->GetPixTempY(),0);
    this->setCursorState(true);

    this->SetPixTempX(this->GetPixTempX()+1);
    //this->pixTempX=this->pixTempX+1;
  }
  void DrawScreen::decX(){
    this->PrintDirect(this->GetPixTempX(),this->GetPixTempY(),0);
    this->setCursorState(true);

    this->SetPixTempX(this->GetPixTempX()-1);
    
  }

  void DrawScreen::incY(){
    
    this->PrintDirect(this->GetPixTempX(),this->GetPixTempY(),0);
    this->setCursorState(true);

    //this->pixTempY=this->pixTempY+1;
    this->SetPixTempY(this->GetPixTempY()+1);

    
  }
  void DrawScreen::decY(){
    this->PrintDirect(this->GetPixTempX(),this->GetPixTempY(),0);
    this->setCursorState(true);

    this->SetPixTempY(this->GetPixTempY()-1);
  } 
  


DrawScreen::DrawScreen() {
  //this.vecPins = new VectorClass(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  this->setTimeCursorBlink(TIME_CURSOR_BLINK);
  

  this->setTime(micros());
  this->setTimeLast(this->getTime());

  dsl("");
}



void DrawScreen::setPantalla(MatrizLed& vPantalla) {
  this->pantalla = vPantalla;
}
int DrawScreen::GetPosArray(int x,int y){
    //return (this->getPixY()*7)+(this->getPixX()%7);    
    return (y*7)+(x%7);    
}
/*
int DrawScreen::GetPosArray(){
    return (this->getPixY()*7)+(this->getPixX()%7);    
}*/

void DrawScreen::setPix(int x, int y, bool status) {
  int posInArray=0;
  this->setPixX(x);
  this->setPixY(y);  
  
  posInArray=this->GetPosArray(x,y);
  //ds("DrawScreen::setPix : GetPosArray():");dsl(GetPosArray());

  vecScreens[posInArray]=status;  
}

void DrawScreen::setCursor(int x, int y, int ledState) {
  

  this->SetPixTempX(x);
  this->SetPixTempY(y);  
  this->setCursorState(ledState);
  //this->UpdateCursor();
}
void DrawScreen::setPosCursor(int x, int y) {
  

  this->SetPixTempX(x-1);
  this->SetPixTempY(y-1);  
  
  //this->UpdateCursor();
}

void DrawScreen::UpdateCursor(){
  this->setTime(micros());
    

  
  //ds("DrawScreen::setCursor this->getTimeLapse():");dsl(this->getTimeLapse())
  //ds("DrawScreen::setCursor this->getTimeCursorBlink():");dsl(this->getTimeCursorBlink())

  if(this->getTimeLapse()>this->getTimeCursorBlink()){
    if(this->getCursorState()){
      this->PrintDirect(this->GetPixTempX(),this->GetPixTempY(),1);
      this->setCursorState(false);
      //dsl("DrawScreen::setCursor Cursor state true");
    }else{
      this->PrintDirect(this->GetPixTempX(),this->GetPixTempY(),0);
      this->setCursorState(true);
      //dsl("DrawScreen::setCursor Cursor state false");
    }
    //posInArray=GetPosArray();
    //ds("DrawScreen::setPix : GetPosArray():");dsl(GetPosArray());
    this->setTimeLast(this->getTime());
  }
  
  //Si el lugar donde esta el cursor paradoesta en marcado cambia la velocidad

  if (vecScreens[this->GetPosArray(this->GetPixTempX(),this->GetPixTempY())]==1){
    this->setTimeCursorBlink(TIME_CURSOR_BLINK_FAST);
  }else{
     this->setTimeCursorBlink(TIME_CURSOR_BLINK);
  }
  //vecScreens[posInArray]=status; 
  this->setTimeLapse(this->getTime()- this->getTimeLast());
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

void DrawScreen::StampCursorInFrame(){
  this->setPix(this->GetPixTempX(),this->GetPixTempY(), 1);
}

void DrawScreen::PrintFrame(){
  int sizeArray=V_SCR_SIZE;

  for (int i = 0; i < sizeArray; i++) {
    //ds("DrawScreen::Print : vecScreens[i]:");dsl(vecScreens[i]);
    if (i!=this->GetPosArray(this->GetPixTempX(),this->GetPixTempY())){
      PrintPixelByFrame(i,vecScreens[i]);
    }
  }
  
}

void DrawScreen::ResetFrame(){
  int sizeArray=V_SCR_SIZE;
  for (int i = 0; i < sizeArray; i++) {
    this->vecScreens[i]=0;        
  }
  this->PrintFrame();
}


// ╔══════════════════════════════════════════════════════════════════╗
// ║   ____    _             __  __           _            _          ║
// ║  |  _ \  (_)           |  \/  |         | |          (_)         ║
// ║  | |_) |  _    __ _    | \  / |   __ _  | |_   _ __   _  __  __  ║
// ║  |  _ <  | |  / _` |   | |\/| |  / _` | | __| | '__| | | \ \/ /  ║
// ║  | |_) | | | | (_| |   | |  | | | (_| | | |_  | |    | |  >  <   ║
// ║  |____/  |_|  \__, |   |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\  ║
// ║                __/ |                                             ║
// ║               |___/                                              ║
// ║                                                                  ║
// ║  _         _____   _____      _____                           _  ║
// ║ | |       / ____| |  __ \    |  __ \                         | | ║
// ║ | |      | |      | |  | |   | |__) |   __ _   _ __     ___  | | ║
// ║ | |      | |      | |  | |   |  ___/   / _` | | '_ \   / _ \ | | ║
// ║ | |____  | |____  | |__| |   | |      | (_| | | | | | |  __/ | | ║
// ║ |______|  \_____| |_____/    |_|       \__,_| |_| |_|  \___| |_| ║
// ║                                                                  ║
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝
