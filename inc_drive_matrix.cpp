#include "inc_drive_matrix.h"
#include "inc_include.h"

DriveMatrix::DriveMatrix(int pinNumber) {
  pin = pinNumber;
  pinMode(pin, OUTPUT);
}

void DriveMatrix::Print() {
  digitalWrite(pin, HIGH);
}
