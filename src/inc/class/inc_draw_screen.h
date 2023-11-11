
#ifndef _INC_DRAW_SCREEN_H_
#define _INC_DRAW_SCREEN_H_

#define V_SCR_SIZE 35

class DrawScreen {
  private:
  

  int vecPins[V_SCR_SIZE]={2,7,12,17,22,27,32,3,8,13,18,23,28,33,4,9,14,19,24,29,34,5,10,15,20,25,30,35,6,11,16,21,26,31,36};

  int vecScreens[V_SCR_SIZE]={O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O};  

  static int pin;
  int pixX;
  int pixY;
  MatrizLed pantalla;
  int aLastFrameEmpty = 0;
  int* aPins;
  int maxWidth=7;
  int maxHeight=5;
  bool startDraw=false;


 


  

  public:
  int getPixX();
  void setPixX(int pixX);
  int getPixY();
  void setPixY(int pixY);

  int GetMaxWidth();
  void SetMaxWidth(int maxWidth);
  int GetMaxHeight();
  void SetMaxHeight(int maxHeight);
  
  bool GetStartDraw();
  void SetStartDraw(bool value);
  void incX();
  void decX();
  void incY();
  void decY();
  void stampPixel();
  
  DrawScreen();

  void setPantalla(MatrizLed& vPantalla);
  int GetPosArray();
  void setPix(int x, int y, bool status);
  void PrintPixel(int x,int y,int ledState);
  void PrintPixelByFrame(int numPixel,int ledState);
  void Print();

};


#endif /* _INC_DRAW_SCREEN_H_ */