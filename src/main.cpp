
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
// static int** matrix;
int pinState = 0;
MatrizLed pantalla;
DriveMatrix dm;
ShowMatrix sm;
String strToShow = "Mauri";
String lastStrToShow="";
 int *test;
int contChars=0;
int *aCharsBlock;

const int ELEMENT_COUNT_MAX = 30;
int storage_array[ELEMENT_COUNT_MAX];
//Vector<int> vecIntChar(storage_array); //No se puede usar, al usar foreach funciona mal al ejecutarlo varias veces.


int *aIntCharMatrix;
    int numOfcharacter = 0;

void setup()
{
    #ifdef DEBUG
        Serial.begin(9600);
    #else
        debug_init();
    #endif

    pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
    pantalla.setIntensidad(1);

    sm = ShowMatrix();
    dm = DriveMatrix();
    aCharsBlock=(int*)calloc((300),sizeof(int));
    for (int i = 0; i < 300; i++) aCharsBlock[i]=0;

    dm.InitDriveMatrix(BUILD_MATRIX_WIDTH, BUILD_MATRIX_HEIGHT);
    dm.Clear();
    // dm.CreateMatrix();
    pantalla.borrar();
    aPins = convProgToArray(C_Pins, 0, (sizeof(C_Pins) / 2));
    nElements = sizeof(C_Pins) / 2;

    sm.InitShowMatrix(aPins, nElements, pantalla);

    //aT2 = convProgToArray(C_T2, 0, (sizeof(C_T2) / 2));

    //aPacman = convProgToArray(C_PACMAN_01, 0, (sizeof(C_PACMAN_01) / 2));


    debugl("test");
    
    dm.ResetInitPosMatrix();       
    if(lastStrToShow!=strToShow){
        
        dm.getArrayOfCharsOfString(strToShow);
        lastStrToShow=strToShow;
    }
    /*
    debugl("");
    debuge("getContChars:");
    debuge(dm.getContChars());*/
}
// Secuencia de la matriz
void loop()
{

  
    //int elements=0;
   
    //dm.ResetInitPosMatrix();
    /*
    for (int i=0;i<dm.getContChars();i++){    
        elements=dm.getValueFromChar(i);        
        aIntCharMatrix=getCharMatrix(elements);
        dm.AddConsToMatrix(aIntCharMatrix, elements);        
    }
    
    aFrame = dm.GetFrame();
    sm.PrintLedMatrix(aFrame);
    */
    // dm.despIzq();
    // dm.moveMatrixToLeft();
    

    /*
    matriz=convProgToMatrix(C_LET_A,(sizeof(C_LET_A)/2));
    printMatrix(matriz);

    sm.PrintLedMatrix(aT2);
    delay(500);
    sm.PrintLedMatrix(aPacman);
    delay(500);
    */

    
    delay(500);
}