#include "inc_include.h"




static int * aPins;
int nElements=0;
static int * aFrame;
static int * aPacman;


int pinState=0;
MatrizLed pantalla;

static ShowMatrix sm;

void setup() {
    Serial.begin(9600);
    pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.setIntensidad(1); 
    sm=ShowMatrix();
    pantalla.borrar();
    aPins=convProgToArray(C_Pins,(sizeof(C_Pins)/2));
    nElements = sizeof(C_Pins) / sizeof(int);

    sm.InitMatrix(aPins,nElements,pantalla);     
    
    aFrame=convProgToArray(C_T2,(sizeof(C_T2)/2));
    aPacman=convProgToArray(C_PACMAN_01,(sizeof(C_PACMAN_01)/2));
    /*
    aFrame[1]=convProgToArray(C_PACMAN_01,(sizeof(C_PACMAN_01)/2));
    aFrame[2]=convProgToArray(C_PACMAN_02,(sizeof(C_PACMAN_02)/2));
    */
    



    

}
// Secuencia de la matriz
void loop() {
    
    
    sm.PrintLedMatrix(aFrame,aPins,nElements);
    delay(1000);
    sm.PrintLedMatrix(aPacman,aPins,nElements);
    delay(1000);
    /*
    sm.PrintLedMatrix(aFrame[1],aPins1,nFrameElements1);
    delay(1000);
    sm.PrintLedMatrix(aFrame[2],aPins1,nFrameElements1);
    delay(1000);*/


    

 
     
     
}
