#include "inc_include.h"


DriveMatrix::DriveMatrix() 
{  
  Serial.println("");

}

void DriveMatrix::InitDriveMatrix(int cols,int rows) {  
  matrixCols=cols;
  matrixRows=rows;
  CreateMatrix();

}

void DriveMatrix::CreateMatrix(){  
      
  matrix = new int*[matrixRows];  
  for (unsigned int i = 0; i < matrixRows; i++) {    
    matrix[i] = new int[matrixCols];        
    for (unsigned int j = 0; j < matrixCols; j++) {
      matrix[i][j] = 0;
    }
  }
  
}

void DriveMatrix::Print() {
  
  for (int i=0; i < matrixRows; i++){
    for (int j=0; j < matrixCols; j++){
      debuge(matrix[i][j]);
    }
    debugl("");
  }
  //digitalWrite(pin, HIGH);
}

void DriveMatrix::Clear() {
  for (int i=0; i < matrixRows; i++){
    for (int j=0; j < matrixCols; j++){
      matrix[i][j]=0;
    }
  }
}
void DriveMatrix::AddConsToMatrix(int *aData){  
  int value=0;
  int relPosY=0;
  int relPosX=0;
  int maxPosX=0;
  int cont=aData[0];
  
  for (int i=0; i < cont; i++){      
      
    value=aData[i+1];
    

    if(value!=EL && value!=EA) {
      /*
      debuge("totPosX");
      debuge(totPosX);
      debuge("y");
      debuge(relPosY);
      debuge("x");
      debuge(relPosX);
      debuge("=");
      debuge(value);
      debuge(" | ");
      */
      matrix[relPosY][totPosX+relPosX]=value;
      
      /*
      debuge(matrix[relPosY][totPosX+relPosX]);
      debuge(" | ");
      */
      
      relPosX++;
      if(relPosX>maxPosX){
        maxPosX=relPosX;
      
      }
      
    }else{
      debugl("");
      relPosY++;
      relPosX=0;
    }
    

    
  }
  
  totPosX+=maxPosX;
  maxPosX=0;
  /*
  matrix = new int*[matrixRows];  
  for (unsigned int i = 0; i < matrixRows; i++) {    
    matrix[i] = new int[matrixCols];        
    for (unsigned int j = 0; j < matrixCols; j++) {
      matrix[i][j] = 0;
    }
  }*/
  
}

