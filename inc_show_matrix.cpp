#include "inc_show_matrix.h"
#include "inc_include.h"
ShowMatrix::ShowMatrix(int pinNumber) {
  pin = pinNumber;
  pinMode(pin, OUTPUT);
}


void ShowMatrix::PrintData(int data){
    Serial.print("text");
}
