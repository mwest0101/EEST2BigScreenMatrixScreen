#include "inc_include.h"

#ifndef _INC_DRIVE_MATRIX_H_
  #define _INC_DRIVE_MATRIX_H_


  class DriveMatrix {
    private:
      
      int matrixCols=0;
      int matrixRows=0;
      /*
      int relPosX;
      int relPosY;
      */
      int totPosX=0;
      int despMat=0;
      int movMat=0;
      //int totPosY;
      //int **matrix; 
      int *infMat; 
      int posInfMat=0;
      String lastStrToShow="";
       int numOfcharacter = 0;
       //int *aCharsBlock;
      int contChars=0;
       
    public:        
      DriveMatrix();
      
      //void InitDriveMatrix(int rows,int cols);
      int **InitDriveMatrix(int **matrix,int cols, int rows);
      //void CreateMatrix(int cols,int rows);
      void Print(int **matrix);
      int **Clear(int **matrix);
      void ResetInitPosMatrix();
      int **AddConsToMatrix(int **matrix,int *aData,int caracter);
      int *GetFrame(int **matrix);
      void despIzq();
      //void moveMatrixToLeft();
      int **moveMatrixToLeft(int **matrix);
      int getMovMat();
      VectorClass getArrayOfCharsOfString(String strData);
      int getContChars();
      //int getValueFromChar(int number);
      
  };

#endif /* _INC_DRIVE_MATRIX_H_ */
