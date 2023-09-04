

#ifndef _INC_SHOW_MATRIX_H_
  #define _INC_SHOW_MATRIX_H_
  #include "inc_include.h"  
 

  class ShowMatrix {
    private:
      int pin;
      //int posX;
      //int posY;
      int * aLastFrame;
      MatrizLed pantalla;
      int aLastFrameEmpty=0;
      int *aPins;
      int nElements=0;
      
    public:
      ShowMatrix();
      void InitShowMatrix(int * aPins,int nFrameElements, MatrizLed vPantalla);
      void PrintLed(int ledNum,int pintToActive,int ledState);
      void PrintData(int pinNumber);
      void PrintLedMatrix(int * aFrame);
      
      
  };


#endif /* _INC_SHOW_MATRIX_H_ */
