#include "inc_include.h"
/*
static const int PROGMEM t2[]={ 1,1,1,0,1,1,1,
                                0,1,0,0,0,0,1,
                                0,1,0,0,1,1,1,
                                0,1,0,0,1,0,0,
                                0,1,0,0,1,1,1,-1};
*/                            
static const int PROGMEM t2[]={ I,I,I,O,I,I,I,EL,
                                O,I,O,O,O,O,I,EL,
                                O,I,O,O,I,I,I,EL,
                                O,I,O,O,I,O,O,EL,
                                O,I,O,O,I,I,I,EA};                                
                              
void setup() {
  Serial.begin(9600);
  ShowMatrix sm(10);
  
  static int * aEffect;
 
  aEffect=convProgToArray(t2,(sizeof(t2)/2));

  /*
  aPines=convProgToArray(C_PANEL_PIN,(sizeof(C_PANEL_PIN)/2));
  aEffect=convProgToArray(C_T2,(sizeof(C_T2)/2));
  
  nEffects = sizeof(aEffect) / sizeof(int);
  nPines = sizeof(aPines) / sizeof(int);
  for (int i = 0; i < nPines; i++) {
    pinMode(aEffect[i], OUTPUT);
  }*/
}
// Secuencia de la matriz
void loop() {
  /*
  for (int i = 0; i < nEffects; i++) {
    elemento = aPines[i];
    digitalWrite(aEffect[i], elemento);
  }
  delay(1000);
  */
 
}
