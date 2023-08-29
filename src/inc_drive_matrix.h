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
      String  *infMat; 
      int posInfMat=0;

    public:        
      DriveMatrix();
      
      void InitDriveMatrix(int rows,int cols);
      void CreateMatrix(int cols,int rows);
      void Print();
      void Clear();
      void AddConsToMatrix(int *aData,String caracter);
      int *GetFrame();
      void despIzq();
      void moveMatrixToLeft();
      int getMovMat();
      
  };

#endif /* _INC_DRIVE_MATRIX_H_ */
