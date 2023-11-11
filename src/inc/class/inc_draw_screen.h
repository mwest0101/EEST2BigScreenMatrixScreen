
#ifndef _INC_DRAW_SCREEN_H_
#define _INC_DRAW_SCREEN_H_

#define V_SCR_SIZE 35
#define TIME_CURSOR_BLINK 800000
//#define DEBUG_DRAW_SCREEN

#ifndef ds
  #ifdef DEBUG_DRAW_SCREEN
    #define ds(x)     Serial.print(x);
  #else
    #define ds(x)
  #endif
#endif
#ifndef dsl
  #ifdef DEBUG_DRAW_SCREEN
    #define dsl(x)     Serial.println(x);
  #else
    #define dsl(x)
  #endif
#endif


class DrawScreen {
  private:
  

  int vecPins[V_SCR_SIZE]={2,7,12,17,22,27,32,3,8,13,18,23,28,33,4,9,14,19,24,29,34,5,10,15,20,25,30,35,6,11,16,21,26,31,36};

  int vecScreens[V_SCR_SIZE]={O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O};  

  static int pin;
  int pixX;
  int pixY;
  int pixTempX;
  int pixTempY;
  bool cursorState;
  unsigned long timeCursorBlink;
  unsigned long timeLapse;
  unsigned long timeLast;
  unsigned long time;



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


  int GetPixTempX();
  void SetPixTempX(int pixTempX);
  int GetPixTempY();
  void SetPixTempY(int pixTempY);


  bool getCursorState();
  void setCursorState(bool cursorState);

  unsigned long getTimeCursorBlink();
  void setTimeCursorBlink(unsigned long timeCursorBlink);
  unsigned long getTimeLapse();
  void setTimeLapse(unsigned long timeLapse);
  unsigned long getTime();
  void setTime(unsigned long time);
  unsigned long getTimeLast();
  void setTimeLast(unsigned long timeLast);

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
  void setCursor(int x, int y, int ledState);
  void Print(int x,int y,int ledState);
  void PrintDirect(int x,int y,int ledState);
  void PrintPixelByFrame(int numPixel,int ledState);
  void PrintFrame();

};


#endif /* _INC_DRAW_SCREEN_H_ */