
#include "inc_include.h"

int * aPins;
int nElements=0;
int * aFrame;
int * aT2;

int * aPacman;

int * aPacman2;
int * aPacman3;
//static int * aChar;


int * AChar;
int * BChar;
int posLetDesp=0;
//int * aFrame;
//static int** matrix; 
int pinState=0;
MatrizLed pantalla;
DriveMatrix dm;
ShowMatrix sm;
String strToShow="BIENVENIDOS A LA EEST N 2";

void setup() {
    Serial.begin(9600);
    //printf("I'm alive!\n");
    pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.setIntensidad(1); 
    
    sm=ShowMatrix();
    dm=DriveMatrix();
    

    dm.InitDriveMatrix(BUILD_MATRIX_WIDTH,BUILD_MATRIX_HEIGHT);
    
    
    //dm.CreateMatrix();
    pantalla.borrar();
    aPins=convProgToArray(C_Pins,0,(sizeof(C_Pins)/2));
    nElements = sizeof(C_Pins) / 2;
    
    sm.InitShowMatrix(aPins,nElements,pantalla);     
    
    aT2=convProgToArray(C_T2,0,(sizeof(C_T2)/2));
    
    aPacman=convProgToArray(C_PACMAN_01,0,(sizeof(C_PACMAN_01)/2));
    /*
    aPacman2=convProgToArray(C_PACMAN_02,(sizeof(C_PACMAN_01)/2));
    aPacman3=convProgToArray(C_PACMAN_03,(sizeof(C_PACMAN_01)/2));
    */
    
    
    //printMatrix(AChar);
    
    //dm.AddConsToMatrix(getCharMatrix("E"));
    // dm.AddConsToMatrix(getCharMatrix("E"));
    // dm.AddConsToMatrix(getCharMatrix("S"));
    // dm.AddConsToMatrix(getCharMatrix("T"));
    // dm.AddConsToMatrix(getCharMatrix("2"));
    //dm.Print();
    
    //aFrame=dm.GetFrame();
    
    
    
    
    /*
    aFrame[1]=convProgToArray(C_PACMAN_01,(sizeof(C_PACMAN_01)/2));
    aFrame[2]=convProgToArray(C_PACMAN_02,(sizeof(C_PACMAN_02)/2));
    */
    
    
    for (unsigned int i = 0; i < 2; i++) {
        char caracter = strToShow[i];
        /*String caracterString = String(caracter); // Convierte el carácter en un objeto String
        Serial.println(caracterString);*/
        dm.AddConsToMatrix(getCharMatrix(String(caracter)),caracter);
    }

    

}
// Secuencia de la matriz
void loop() {
     
    
    aFrame=dm.GetFrame();
    //dm.despIzq();
    dm.moveMatrixToLeft();
    sm.PrintLedMatrix(aFrame);
    
    delay(500);
    //int *aChars;
     /*
    for (unsigned int i = 0; i < strToShow.length(); i++) {
        char caracter = strToShow[i];
        String caracterString = String(caracter); // Convierte el carácter en un objeto String
        Serial.println(caracterString);
    }*/
    //    dm.AddConsToMatrix(aChars);
        //    Serial.println(caracter);
    
    /*
    matriz=convProgToMatrix(C_LET_A,(sizeof(C_LET_A)/2));
    printMatrix(matriz);
    
    sm.PrintLedMatrix(aT2);
    delay(500);
    sm.PrintLedMatrix(aPacman);
    delay(500);
    */

    /*    
    sm.PrintLedMatrix(aPacman2,aPins,nElements);
    delay(500);
    
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
