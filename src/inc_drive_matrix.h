#ifndef _INC_DRIVE_MATRIX_H_
  #define _INC_DRIVE_MATRIX_H_
  #include "inc_include.h"

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
      int **matrix; 
      int *infMat; 
      int posInfMat=0;
      String lastStrToShow="";
       int numOfcharacter = 0;
       int *aCharsBlock;
       int contChars=0;
       
    public:        
      DriveMatrix();
      
      void InitDriveMatrix(int rows,int cols);
      //void CreateMatrix(int cols,int rows);
      void Print();
      void Clear();
      void ResetInitPosMatrix();
      void AddConsToMatrix(int *aData,int caracter);
      int *GetFrame();
      void despIzq();
      void moveMatrixToLeft();
      int getMovMat();
      void getArrayOfCharsOfString(String strData);
      int getContChars();
      int getValueFromChar(int number);
      
  };

#endif /* _INC_DRIVE_MATRIX_H_ */
