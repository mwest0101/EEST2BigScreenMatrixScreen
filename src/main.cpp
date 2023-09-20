#include <Arduino.h>
#include "inc_include.h"
int *aPins;
int nElements = 0;
int *aFrame;
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
//int **matrix;
int pinState = 0;
#ifdef IS_LCDSCREEN
MatrizLed pantalla;
#endif
DriveMatrix dm;
ShowMatrix sm;    //012345678901234567890123456789
String strToShow = "Mauricio Pablo West";
String lastStrToShow = "";
int *test;
int oldCodSumTo = 0;
int contChars = 0;
VectorClass aIntCharMatrix(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecChar(1, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass vecPins(1, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
MatrixClass matrix(BUILD_MATRIX_ROWS,BUILD_MATRIX_COLS, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE); 

int numOfcharacter = 0;
void setup(){

#ifdef DEBUG
    Serial.begin(9600);
#else
    debug_init();
#endif
#ifdef IS_LCDSCREEN
    pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.setIntensidad(1);
#endif
    sm = ShowMatrix();
    dm = DriveMatrix();

#ifdef IS_LCDSCREEN
    pantalla.borrar();
#endif
    
    convProgToArray(vecPins,C_Pins, (sizeof(C_Pins) / 2));
    vecPins.print();
    
    /*
    debugl("");
    debuge("getContChars:");
    debuge(dm.getContChars());*/
}
// Secuencia de la matriz
void loop(){

    dm.ResetInitPosMatrix();
    
    if (lastStrToShow != strToShow){
        
        VectorClass vecChar = dm.getArrayOfCharsOfString(strToShow);
        vecChar.print();
        debugl("______________________________________________________");
        debugl("---------Antes de  bucle de loop----------------------");
        
        //matrix.clear();
        
        for (int i = 0; i < 3; i++){ 
            debugl("------------------Inicio de for-----------------------");
            aIntCharMatrix.clear();
            getCharMatrix(aIntCharMatrix,vecChar.get(i));
            debug("aIntCharMatrix.getSize=");
            debugl(aIntCharMatrix.getSize());
            
             dm.AddConsToMatrix(matrix,aIntCharMatrix, vecChar.get(i));
        
        
        }
    }
    matrix.print();
    dm.moveMatrixToLeft(matrix);
        
        /*
        aFrame = dm.GetFrame(matrix);
        sm.PrintLedMatrix(aFrame);
        // dm.despIzq();
        // dm.moveMatrixToLeft();
        */
        /*
        matriz=convProgToMatrix(C_LET_A,(sizeof(C_LET_A)/2));
        printMatrix(matriz);
        sm.PrintLedMatrix(aT2);
        delay(500);
        sm.PrintLedMatrix(aPacman);
        delay(500);
        */
    
    lastStrToShow = strToShow;
    delay(500);
}