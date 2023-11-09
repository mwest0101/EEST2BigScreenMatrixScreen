
#ifndef _INC_DRAW_SCREEN_H_
#define _INC_DRAW_SCREEN_H_


class DrawScreen {
  private:
  VectorClass vecPins = VectorClass(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  VectorClass vecScreens = VectorClass(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  static int pin;
  int pixX;
  int pixY;
  MatrizLed pantalla;
  int aLastFrameEmpty = 0;
  int* aPins;
  int maxWidth=7;
  int maxHeight=5;
 


  

  public:
  int getPixX();
  void setPixX(int pixX);
  int getPixY();
  void setPixY(int pixY);

  int GetMaxWidth();
  void SetMaxWidth(int maxWidth);
  int GetMaxHeight();
  void SetMaxHeight(int maxHeight);

  DrawScreen();

  void setPantalla(MatrizLed& vPantalla);
  int DrawScreen::GetPosArray(int x, int y );
  void setPix(int x, int y, bool status);


};
#endif /* _INC_DRAW_SCREEN_H_ */
