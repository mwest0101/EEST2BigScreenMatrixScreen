#include "inc_include.h"

static int * aFrame;
static int * aPins;
int nFrameElements=0;
static int * aFrame1;
static int * aPins1;
int nFrameElements1=0;

static int * aFrame2;
static int * aPins2;
int nFrameElements2=0;
int pinState=0;
MatrizLed pantalla;
ShowMatrix sm(10);
  

void setup() {
    Serial.begin(9600);
    pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
    
    
    pantalla.borrar();
    aFrame=convProgToArray(C_T2,(sizeof(C_T2)/2));
    aPins=convProgToArray(C_Pins,(sizeof(C_Pins)/2));
    nFrameElements = sizeof(C_Pins) / sizeof(int);
    sm.InitMatrix(aPins,nFrameElements,pantalla);

    aFrame1=convProgToArray(C_L1,(sizeof(C_L1)/2));
    aPins1=convProgToArray(C_Pins,(sizeof(C_Pins)/2));
    nFrameElements1 = sizeof(C_Pins) / sizeof(int);

    aFrame2=convProgToArray(C_MARCO,(sizeof(C_MARCO)/2));
    aPins2=convProgToArray(C_Pins,(sizeof(C_Pins)/2));
    nFrameElements2 = sizeof(C_Pins) / sizeof(int);

}
// Secuencia de la matriz
void loop() {
    
    
    sm.PrintLedMatrix(aFrame1,aPins1,nFrameElements1);
    delay(1000);
    

    
    sm.PrintLedMatrix(aFrame2,aPins2,nFrameElements2);
    delay(1000);
     
}
