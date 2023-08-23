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
      //int totPosY;
      int **matrix; 

    public:        
      DriveMatrix();
      
      void InitDriveMatrix(int rows,int cols);
      void CreateMatrix();
      void Print();
      void Clear();
      void AddConsToMatrix(int *aData);
      
  };

#endif /* _INC_DRIVE_MATRIX_H_ */
