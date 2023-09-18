
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
int **matrix;
int pinState = 0;
#ifdef IS_LCDSCREEN
MatrizLed pantalla;
#endif
DriveMatrix dm;
ShowMatrix sm;    //012345678901234567890123456789
String strToShow = "Bienvenido a la EEST 2 Junin";
String lastStrToShow = "";
int *test;
int oldCodSumTo = 0;
int contChars = 0;

VectorClass vecChar(1, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
VectorClass aIntCharMatrix(1, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
// VectorClass vecChar(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
// int *aCharsBlock;
// VectorClass vecChars(VECTOR_SIZE, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
// VectorClass vecPins(VECTOR_SIZE, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
// VectorClass vecChars(VECTOR_SIZE, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
//  const int ELEMENT_COUNT_MAX = 30;
//  int storage_array[ELEMENT_COUNT_MAX];
// Vector<int> vecIntChar(storage_array); //No se puede usar, al usar foreach funciona mal al ejecutarlo varias veces.

//int *aIntCharMatrix;
int numOfcharacter = 0;

void setup()
{
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

// aCharsBlock=(int*)calloc((300),sizeof(int));
// for (int i = 0; i < 300; i++) aCharsBlock[i]=0;
/*
matrix=dm.InitDriveMatrix(matrix,BUILD_MATRIX_WIDTH, BUILD_MATRIX_HEIGHT);
dm.Clear(matrix);*/
// dm.CreateMatrix();
#ifdef IS_LCDSCREEN
    pantalla.borrar();
#endif
    // convProgToArray(vecPins,C_Pins, (sizeof(C_Pins) / 2));
    VectorClass vecPins = convProgToArray(C_Pins, (sizeof(C_Pins) / 2));
    vecPins.print();

    // convProgToArray2(C_Pins, (sizeof(C_Pins) / 2));

    // nElements = sizeof(C_Pins) / 2;

    // sm.InitShowMatrix(vecPins, vecPins.getSize(), pantalla);

    // aT2 = convProgToArray(C_T2, 0, (sizeof(C_T2) / 2));

    // aPacman = convProgToArray(C_PACMAN_01, 0, (sizeof(C_PACMAN_01) / 2));

    debugl("test");

    /*
    debugl("");
    debuge("getContChars:");
    debuge(dm.getContChars());*/
}
// Secuencia de la matriz
void loop()
{

    dm.ResetInitPosMatrix();
    /*
    if (lastStrToShow != strToShow)
    {*/
        VectorClass vecChar = dm.getArrayOfCharsOfString(strToShow);
        vecChar.print();

        for (int i = 0; i < dm.getContChars(); i++)
        {   debugl("_________________________________________________________________________");
            debugl("=========================================================================");
            debugl("---------Bucle de captura de caracteres y pasaje de letras---------------");
            // onLetterInInt=aCharsBlock[i];
            debug("i=");
            debuge(i);
            debug(" vecChar.get(i)=");
            debugel(vecChar.get(i));
            
            //VectorClass aIntCharMatrix=getCharMatrix(vecChar.get(i));

            debugl("---------Antes de pasar a AddConstMatrix---------------");
            //debug("aIntCharMatrix=");
            //aIntCharMatrix.print();
            //delay(200);

            //debugl(aIntCharMatrix[0]);

            

            // matrix=dm.AddConsToMatrix(matrix,aIntCharMatrix, onLetterInInt);
        //}
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
    }
    lastStrToShow = strToShow;
    delay(500);
}