#include <Arduino.h>
#include "inc_include.h"
int *aPins;
int nElements = 0;
// int *aFrame;
int *aT2;
int *busChars;
int *aPacman;
int *aPacman2;
int *aPacman3;
// static int * aChar;
int *AChar;
int *BChar;
int posLetDesp = 0;
// int * aFrame;
// int **matrix;
int pinState = 0;
#ifdef IS_LCDSCREEN
MatrizLed pantalla;
#endif
DriveMatrix dm;
ShowMatrix sm;
ProgmemManager pm;
AnimManager an;
// String strToShow = "Bienvenidos a la EEST Nº2  de Junin Buenos Aires 2023";
//String strToShow = "(a:efe1)(a:efe2)(a:efe3)(a:efe4)(a:efe5)(a:efe6)(a:efe7)(a:tec1)(a:tec2)(a:tec3)(a:tec4)(a:tec5)(a:tec6)(a:tec7)E.E.S.T. Nº2";
String strToShow = "(a:efe1:X4:T5)(a:efe2)(a:efe3)(a:efe4)(a:efe5)(a:efe6)(a:efe7)(a:tec1)(a:tec2)(a:tec3)(a:tec4)(a:tec5)(a:tec6)(a:tec7)E.E.S.T. Nº2";
// String strToShow = "abcdefghijklmnopqrstuvwxyz01234";
// String strToShow = "Mauricio Pablo West";
String lastStrToShow = "";
int *test;
int oldCodSumTo = 0;
int contChars = 0;
int firstPass = 0;
VectorClass vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecPins(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
MatrixClass matrix(BUILD_MATRIX_ROWS, BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aLastFrame(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
int numOfcharacter = 0;
int contCharAdded = 0;
unsigned long time = 0;
unsigned long lastTime = 0;
unsigned long difTime = 0;
unsigned long waitTime = 0;
char charReaded;
char lastCharReaded;
int action = 0;
String strOption = "";
bool getIfisEnd = false;
bool canAddChar = false;

