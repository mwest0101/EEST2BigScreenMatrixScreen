
#include <Arduino.h>
#include "inc_include.h"
DriveMatrix::DriveMatrix(){

  // Serial.println("");
}
//____________________________________________________________________
//------------Function------------------------------------------------
int **DriveMatrix::InitDriveMatrix(int **matrix, int cols, int rows){

  matrixCols = cols;
  matrixRows = rows;
  matrix = CreateMatrix(matrix, matrixCols, matrixRows);
  return matrix;
}
// void DriveMatrix::CreateMatrix(int cols, int rows)
//{
//   matrix = new int *[rows];
//   for (int i = 0; i < rows; i++)
//{
//     matrix[i] = new int[cols];
//     for (int j = 0; j < cols; j++)
//  {
//       matrix[i][j] = 0;
//     }
//   }
// }
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::Print(int **matrix){

  debugl("__________________________________");
  debugl("----------Print Matrix------------");
  for (int i = 0; i < matrixRows; i++){

    for (int j = 0; j < matrixCols; j++)
 {
      debuge(matrix[i][j]);
    }
    debugl("");
  }
  debugl(" ");
  // digitalWrite(pin, HIGH);
}
//____________________________________________________________________
//------------Function------------------------------------------------
int **DriveMatrix::Clear(int **matrix){

  for (int i = 0; i < matrixRows; i++){

    for (int j = 0; j < matrixCols; j++)
 {
      matrix[i][j] = 0;
    }
  }
  ResetInitPosMatrix();
  return matrix;
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::ResetInitPosMatrix(){

  this->totPosX = 0;
  this->posInfMat = 0;
  this->codSumTot = 0;
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::AddConsToMatrix(MatrixClass &matrix, VectorClass &aIntCharMatrix, int caracter){

  debugl(" ");
  debugl("=========AddConsToMatrix===============");
  // ResetInitPosMatrix(); //sacar esto una vez probado que funciona
  int value = 0;
  int relPosRow = 0;
  int relPosCols = 0;
  int maxPosCol = 0;
  int cont = aIntCharMatrix.getSize();
  this->infMat[posInfMat] = caracter;
  debug("caracter:");
  debugl(caracter);
  debug("cont:");
  debugl(cont);
  for (int i = 0; i < cont; i++){

    value = aIntCharMatrix.get(i);
    if (value != EL && value != EA){
      
      matrix.set(relPosRow,(this->totPosX + relPosCols), value);
      debug(" |");
      /*
      debug("t:");
      debug(this->totPosX);
      debug(" Y:");
      debug(relPosRow);
      debug(" X:");
      debug(relPosCols);
      debug(" (");
      */
      debug(value);
      //debuge(")");
      if (relPosCols > maxPosCol) maxPosCol = relPosCols;
      /*
      debug("relPosRow:");debug(relPosRow);debug(" ");
      debug("relPosCols:");debug(relPosCols);debug(" ");
      */
      if (value < 0 || value > 1)
      {
        debugl("_______________________________________________");
        debugl("ATENTION =============== ERROR---------------->");
      }
      // debug("value:");debug(value);debug(" (i+1)=");debugl(i+1);
      relPosCols++;
    }else{  
      debug(" ||");
    /*  debug("t:");
      debug(this->totPosX);
      debug(" Y:");
      debug(relPosRow);
      debug(" X:");
      debug(relPosCols);
      debug(" (");*/
      debugl(value);
      //debugl(")");
      
      relPosRow++;
      relPosCols = 0;
    }
  }
  debug("this->totPosX:");
  debug(this->totPosX);
  debugl(" ");
  /*
  debugl("=========TOTALS===============");
  debug("this->totPosX:");debug(this->totPosX);debug(" ");debug("");
  debug("this->totPosX+relPosCols:");debug(this->totPosX + relPosCols);debug("");
  this->debug("posInfMat:");debug(posInfMat);debug(" ");debug(caracter);debugl("");
  */
  this->posInfMat += (maxPosCol + 1);
  this->totPosX += (maxPosCol + 1);
  maxPosCol = 0;
  debugl(" ");
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::despIzq(){

  if (despMat < BUILD_MATRIX_COLS){

    despMat++;
  }else{

    despMat = 0;
  }
}
//____________________________________________________________________
//------------Function------------------------------------------------
int *DriveMatrix::GetFrame(int **matrix){

  //
  debugl("");
  debugl("Inicio GetFrame");
  int size = MATRIX_WIDTH * MATRIX_HEIGHT;
  int *frame = (int *)calloc((size + 1), sizeof(int));
  int contPos = 0;
  for (int i = 0; i < MATRIX_HEIGHT; i++){

    for (int j = 0; j < MATRIX_WIDTH; j++)
 {
      frame[contPos] = matrix[i][j + despMat];
      // debuge(i);
      // debuge(j);
      // debuge(frame[contPos]);
      // debuge("|");
      contPos++;
    }
    // debugl(" ");
  }
  debug1l("Fin GetFrame");
  return frame;
  return NULL;
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::moveMatrixToLeft(MatrixClass &matrix){

  for (int i = 0; i < MATRIX_HEIGHT; i++){

    for (int j = 0; j < ((MATRIX_WIDTH*2) - 1); j++){
      matrix.set(j,i,matrix.get(j,(i+1)));
    }
    movMat++;
  }
  
}
//____________________________________________________________________
//------------Function------------------------------------------------
int DriveMatrix::getMovMat(){

  return movMat;
}
VectorClass DriveMatrix::getArrayOfCharsOfString(String strData){

  VectorClass vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  int numOfcharacter = 0;
  this->contChars = 0;
  for (unsigned int i = 0; i < strData.length(); i++){

    numOfcharacter = calcNumberOfChar(strData[i]);
    if (numOfcharacter != 0)
 {
      vecTemp.push(numOfcharacter);
      this->codSumTot = this->codSumTot + ((i * 10) + numOfcharacter);
      this->contChars++;
    }
  }
  // debugl("");
  // vecTemp.print();
  return vecTemp;
}
unsigned long DriveMatrix::getCodSumTo(){

  return this->codSumTot;
}
//____________________________________________________________________
//------------Function------------------------------------------------
int DriveMatrix::getContChars(){

  return contChars;
}
/*
int DriveMatrix::getValueFromChar(int number){
  return aCharsBlock[number];
}*/