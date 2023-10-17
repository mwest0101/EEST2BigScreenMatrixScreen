
#ifndef _INC_DRIVE_MATRIX_H_
#define _INC_DRIVE_MATRIX_H_
class DriveMatrix {
  private:

  int matrixCols = 0;
  int matrixRows = 0;
  /*
  int relPosX;
  int relPosY;
  */
  int totPosX = 0;
  int despMat = 0;
  int movMat = 0;
  //int totPosY;
  //int **matrix; 
  int* infMat;
  int posInfMat = 0;
  //String lastStrToShow="";
  int numOfcharacter = 0;
  //int *aCharsBlock;
  int contChars = 0;
  bool vCanAddChar = true;
  bool vIsInTheEnd = true;
  unsigned long codSumTot = 0;
  String lastStrToShow = "";
  bool IsStringEnd =false;
  public:
  DriveMatrix();

  //void InitDriveMatrix(int rows,int cols);
  int** InitDriveMatrix(int** matrix, int cols, int rows);
  //void CreateMatrix(int cols,int rows);
  void Print(int** matrix);
  int** Clear(int** matrix);
  void ResetInitPosMatrix();
  void AddConsToMatrix(MatrixClass& matrix, VectorClass& IntCharMatrix, int caracter);
  void GetFrame(MatrixClass& matrix, VectorClass& aFrame);
  void despIzq();
  //void moveMatrixToLeft();
  void moveMatrixToLeft(MatrixClass& matrix);
  int getPosLastChar();
  bool getIfIsStringEnd();
  bool setIfIsStringEnd(bool status);
  bool canAddChar();
  bool isAtTheEnd();
  void setCanAddChar(bool value);
  int getMovMat();
  void getArrayOfCharsOfString(VectorClass& vecTemp, String strData);
  int getContChars();
  unsigned long getCodSumTo();
  void fillArrrayOfChars(VectorClass& vecChar, String strToShow);
  void getValuesOfCharMatrixAndAddToMatrix(MatrixClass& matrix, VectorClass& aIntCharMatrix, VectorClass& vecChar, int contCharAdded);
  //int getValueFromChar(int number);

};
#endif /* _INC_DRIVE_MATRIX_H_ */
