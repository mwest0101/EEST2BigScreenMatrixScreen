#include "inc_include.h"

#ifndef _INC_SHOW_MATRIX_H_
#define _INC_SHOW_MATRIX_H_
 


class ShowMatrix {
  private:
    int pin;
    int posX;
    int posY;
    int * aLastFrame;
    MatrizLed pantalla;
    
    int aLastFrameEmpty=0;
    

  public:
    ShowMatrix(int pinNumber);
    void InitMatrix(int * aPins,int nFrameElements, MatrizLed vPantalla);
    void PrintLed(int ledNum,int pintToActive,int ledState);
    void PrintData(int pinNumber);
    void PrintLedMatrix(int * aFrame,int * aPins,int nFrameElements);
    
     
};


#endif /* _INC_SHOW_MATRIX_H_ */
