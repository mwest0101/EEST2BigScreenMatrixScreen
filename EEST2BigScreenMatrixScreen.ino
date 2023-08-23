
#include "inc_include.h"

int * aPins;
int nElements=0;
int * aFrame;
int * aPacman;

int * aPacman2;
int * aPacman3;
//static int * aChar;


int * AChar;
int * BChar;
//static int** matrix; 
int pinState=0;
MatrizLed pantalla;
DriveMatrix dm;
ShowMatrix sm;


void setup() {
    Serial.begin(9600);
    //printf("I'm alive!\n");
    pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.setIntensidad(1); 
    
    sm=ShowMatrix();
    dm=DriveMatrix();

    dm.InitDriveMatrix(21,5);
    
    
    //dm.CreateMatrix();
    pantalla.borrar();
    aPins=convProgToArray(C_Pins,(sizeof(C_Pins)/2));
    nElements = sizeof(C_Pins) / sizeof(int);
    
    sm.InitShowMatrix(aPins,nElements,pantalla);     
    
    aFrame=convProgToArray(C_T2,(sizeof(C_T2)/2));
    aPacman=convProgToArray(C_PACMAN_01,(sizeof(C_PACMAN_01)/2));
    aPacman2=convProgToArray(C_PACMAN_02,(sizeof(C_PACMAN_01)/2));
    aPacman3=convProgToArray(C_PACMAN_03,(sizeof(C_PACMAN_01)/2));

    AChar=getCharMatrix("A");
    BChar=getCharMatrix("B");
    
    //printMatrix(AChar);
    
    dm.AddConsToMatrix(getCharMatrix("m"));
    dm.AddConsToMatrix(getCharMatrix("a"));
    dm.AddConsToMatrix(getCharMatrix("u"));
    dm.AddConsToMatrix(getCharMatrix("r"));
    dm.AddConsToMatrix(getCharMatrix("i"));
    dm.Print();

    
    
    
    /*
    aFrame[1]=convProgToArray(C_PACMAN_01,(sizeof(C_PACMAN_01)/2));
    aFrame[2]=convProgToArray(C_PACMAN_02,(sizeof(C_PACMAN_02)/2));
    */
    



    

}
// Secuencia de la matriz
void loop() {
    
    
    /*sm.PrintLedMatrix(aFrame,aPins,nElements);
    delay(1000);
    */
    /*
    matriz=convProgToMatrix(C_LET_A,(sizeof(C_LET_A)/2));
    printMatrix(matriz);*/
    /*
    sm.PrintLedMatrix(aPacman,aPins,nElements);
    delay(500);
    */

    /*    
    sm.PrintLedMatrix(aPacman2,aPins,nElements);
    delay(500);
    /*
    sm.PrintLedMatrix(aPacman3,aPins,nElements);
    delay(500);*/
    

    /*
    sm.PrintLedMatrix(aPacman2,aPins,nElements);
    delay(500);
    */
    /*
    sm.PrintLedMatrix(aChar,aPins,nElements);
    delay(1000);*/

    /*
    sm.PrintLedMatrix(AChar,aPins,nElements);
    delay(1000);
    */
    /*
    sm.PrintLedMatrix(aFrame[1],aPins1,nFrameElements1);
    delay(1000);
    sm.PrintLedMatrix(aFrame[2],aPins1,nFrameElements1);
    delay(1000);*/


    

 
     
     
}
