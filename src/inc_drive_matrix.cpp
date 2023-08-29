#include "inc_include.h"

DriveMatrix::DriveMatrix()
{
  //Serial.println("");
}

void DriveMatrix::InitDriveMatrix(int cols, int rows)
{
  matrixCols = cols;
  matrixRows = rows;
  CreateMatrix(matrixCols, matrixRows);
}

void DriveMatrix::CreateMatrix(int cols, int rows)
{

  matrix = new int *[rows];
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new int[cols];
    for (int j = 0; j < cols; j++)
    {
      matrix[i][j] = 0;
    }
  }
}

void DriveMatrix::Print()
{

  for (int i = 0; i < matrixRows; i++)
  {
    for (int j = 0; j < matrixCols; j++)
    {
      debuge(matrix[i][j]);
    }
    debugl("");
  }
  debugl(" ");
  // digitalWrite(pin, HIGH);
}

void DriveMatrix::Clear()
{
  for (int i = 0; i < matrixRows; i++)
  {
    for (int j = 0; j < matrixCols; j++)
    {
      matrix[i][j] = 0;
    }
  }
}
void DriveMatrix::AddConsToMatrix(int *aData,String caracter)
{
  int value = 0;
  int relPosY = 0;
  int relPosX = 0;
  int maxPosX = 0;
  int cont = aData[0];
  infMat[posInfMat]=caracter;
  debug(caracter);
  posInfMat++;
  for (int i = 0; i < cont; i++)
  {
    value = aData[i + 1];
    if (value != EL && value != EA)
    {
      matrix[relPosY][totPosX + relPosX] = value;

      relPosX++;
      if (relPosX > maxPosX)
      {
        maxPosX = relPosX;
      }
    }
    else
    {
      // debugl("");
      relPosY++;
      relPosX = 0;
    }
  }
  totPosX += maxPosX;
  maxPosX = 0;
  debugl(" ");
}
void DriveMatrix::despIzq(){
  if(despMat<BUILD_MATRIX_WIDTH){
    despMat++;
  }else{
    despMat=0;
  }
}
int *DriveMatrix::GetFrame()
{
  // 
  debugl("");
  debug1l("Inicio GetFrame");
  int size = MATRIX_WIDTH * MATRIX_HEIGHT;
  int *frame = (int *)calloc((size + 1), sizeof(int));
  int contPos = 0;
  for (int i = 0; i < MATRIX_HEIGHT ; i++)
  {
    for (int j = 0; j < MATRIX_WIDTH; j++)
    {
      frame[contPos] = matrix[i][j+despMat];
      //debuge(i);
      //debuge(j);
      //debuge(frame[contPos]);
      //debuge("|");
      contPos++;
    }
    //debugl(" ");
  }

  debug1l("Fin GetFrame");
  return frame;
}
void DriveMatrix::moveMatrixToLeft(){
  for (int i = 0; i < MATRIX_HEIGHT ; i++){
    for (int j = 0; j < ((MATRIX_WIDTH*2)-1); j++){
      matrix[i][j]=matrix[i][j+1];
    }
    movMat++;
  }
}
int DriveMatrix::getMovMat(){
  return movMat;
}
