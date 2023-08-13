#include "inc_include.h"
/*
static const int PROGMEM t2[]={ 1,1,1,0,1,1,1,
                                0,1,0,0,0,0,1,
                                0,1,0,0,1,1,1,
                                0,1,0,0,1,0,0,
                                0,1,0,0,1,1,1,-1};
*/                            
static const int PROGMEM C_T2[]={ I,I,I,O,I,I,I,EL,
                                O,I,O,O,O,O,I,EL,
                                O,I,O,O,I,I,I,EL,
                                O,I,O,O,I,O,O,EL,
                                O,I,O,O,I,I,I,EA};                                

static int * aFrame;
static int * aPins;
int nFrameElements=0;
int pinState=0;

void setup() {
  Serial.begin(9600);
  ShowMatrix sm(10);
  
  
 
  aFrame=convProgToArray(C_T2,(sizeof(C_T2)/2));
  aPins=convProgToArray(C_Pins,(sizeof(C_Pins)/2));
  nFrameElements = sizeof(aPins) / sizeof(int);

  /*
  aPines=convProgToArray(C_PANEL_PIN,(sizeof(C_PANEL_PIN)/2));
  aEffect=convProgToArray(C_T2,(sizeof(C_T2)/2));
  
  nEffects = sizeof(aEffect) / sizeof(int);
  nPines = sizeof(aPines) / sizeof(int);
  for (int i = 0; i < nPines; i++) {
    pinMode(aEffect[i], OUTPUT);
  }*/

  for (int i = 0; i < nFrameElements; i++) {
    pinMode(aPins[i], OUTPUT);
  }
}
// Secuencia de la matriz
void loop() {
  
  for (int i = 0; i < nFrameElements; i++) {
    pinState = aFrame[i];
    if(pinState<2){
      digitalWrite(aPins[i], pinState);
      Serial.println(aPins[i]);
      Serial.println(pinState);
    }
  }
  delay(1000);
  
 
}
