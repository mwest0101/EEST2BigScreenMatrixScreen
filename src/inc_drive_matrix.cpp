#include "inc_include.h"

DriveMatrix::DriveMatrix()
{
  //Serial.println("");
}

int **DriveMatrix::InitDriveMatrix(int **matrix,int cols, int rows)
{
  matrixCols = cols;
  matrixRows = rows;
  matrix=CreateMatrix(matrix,matrixCols, matrixRows);
  return matrix;
}

// void DriveMatrix::CreateMatrix(int cols, int rows)
// {

//   matrix = new int *[rows];
//   for (int i = 0; i < rows; i++)
//   {
//     matrix[i] = new int[cols];
//     for (int j = 0; j < cols; j++)
//     {
//       matrix[i][j] = 0;
//     }
//   }
// }

void DriveMatrix::Print(int **matrix)
{
debugl("__________________________________");
debugl("----------Print Matrix------------");

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

int **DriveMatrix::Clear(int **matrix)
{
  for (int i = 0; i < matrixRows; i++)
  {
    for (int j = 0; j < matrixCols; j++)
    {
      matrix[i][j] = 0;
    }
  }
  ResetInitPosMatrix();
  return matrix;
}
void DriveMatrix::ResetInitPosMatrix(){
  totPosX=0;        
  posInfMat=0;
}
 
int **DriveMatrix::AddConsToMatrix(int **matrix,int *aData,int caracter)
{
  debugl(" ");
  debugl("=========AddConsToMatrix===============");
  //ResetInitPosMatrix(); //sacar esto una vez probado que funciona
  int value = 0;
  int relPosY = 0;
  int relPosX = 0;
  int maxPosX = 0;
  int cont = aData[0];
  infMat[posInfMat]=caracter;
  debug("caracter:");debugl(caracter);
  debug("cont:");debugl(cont);
  for (int i = 0; i < cont; i++) {
    value = aData[i + 1];

    if (value != EL && value != EA) {
      matrix[relPosY][totPosX + relPosX] = value;
      debug("|");
      debuge(value);
      if (relPosX > maxPosX) {
        maxPosX = relPosX;
      }
      /*
      debug("relPosY:");debug(relPosY);debug(" ");
      debug("relPosX:");debug(relPosX);debug(" ");
      */
      if(value<0 || value>1) { debug("ATENTION =============== ERROR---------------->");}
      //debug("value:");debug(value);debug(" (i+1)=");debugl(i+1);
      relPosX++;
    }else{
      debugl("");
      relPosY++;
      relPosX = 0;
    }
   
  }
  debug("totPosX:");debug(totPosX);debugl(" ");
  /*
  debugl("=========TOTALS===============");
  debug("totPosX:");debug(totPosX);debug(" ");debug("");
  debug("totPosX+relPosX:");debug(totPosX + relPosX);debug("");
  debug("posInfMat:");debug(posInfMat);debug(" ");debug(caracter);debugl("");
  */
  
  posInfMat+=(maxPosX+1);
  totPosX += (maxPosX+1);
  maxPosX = 0;
  debugl(" ");
   return matrix;
}

void DriveMatrix::despIzq(){
  if(despMat<BUILD_MATRIX_WIDTH){
    despMat++;
  }else{
    despMat=0;
  }
}
int *DriveMatrix::GetFrame(int **matrix)
{
  // 
  debugl("");
  debugl("Inicio GetFrame");
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
  return NULL;
}
int **DriveMatrix::moveMatrixToLeft(int **matrix){
  for (int i = 0; i < MATRIX_HEIGHT ; i++){
    for (int j = 0; j < ((MATRIX_WIDTH*2)-1); j++){
      matrix[i][j]=matrix[i][j+1];
    }
    movMat++;
  }
  return matrix;
}

int DriveMatrix::getMovMat(){
  return movMat;
}
int *DriveMatrix::getArrayOfCharsOfString(String strData){    
  int numOfcharacter = 0;
  contChars=0;
  for (unsigned int i = 0; i < strData.length(); i++) { 
    if (calcNumberOfChar(strData[i])!=0) contChars++;                      
  }   
  
  int *aCharsBlock = (int *)calloc((contChars), sizeof(int));
 
  contChars=0;
  for (unsigned int i = 0; i < strData.length(); i++) {                
    numOfcharacter = calcNumberOfChar(strData[i]);
 
    
    debuge("i=");                     debug(i);                      debuge(" | ");
    debuge("contChars=");             debuge(contChars);              debuge(" | ");
    debuge("numOfcharacter=");        debuge(numOfcharacter);         debuge(" | ");
    debug("aCharsBlock[");
    debug(contChars);
    debuge("]=");
    
    if (numOfcharacter!=0) {
      aCharsBlock[contChars]=numOfcharacter;
      debuge(aCharsBlock[contChars]);debugel(" ] ");  
      contChars++;                  
    }            
    
  }
   for (int i = 0; i < contChars; i++) {                
    debug3l("i=");
    debuge(i);
    debug("aCharsBlock[");
    debug(i);
    debuge("]=");
    debugl(aCharsBlock[i]);
   }

  return aCharsBlock;
}

int DriveMatrix::getContChars(){
  return contChars;
}
/*
int DriveMatrix::getValueFromChar(int number){
  return aCharsBlock[number];
}*/