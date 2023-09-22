#include <Arduino.h>
#include "inc_include.h"
#ifndef _MATRIX_CLASS_
  #define _MATRIX_CLASS_
class MatrixClass{

private:
  int **matrix;
  int rows;
  int cols;
  int minValue;
  int maxValue;
public:
  MatrixClass(int rows,int cols, int min, int max){

    this->rows = rows;
    this->cols = cols;
    
    this->minValue = min;
    this->maxValue = max;
    // Inicializar la matrix con valuees aleatorios dentro del rango especificado
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
  ~MatrixClass(){

    // Liberar la memoria de la matrix
    for (int i = 0; i < rows; i++)
 {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void print(){
  ds3l("============================================================");
  ds3("this->rows:");
  ds3(this->rows);
  ds3(" this->cols:");
  ds3l(this->cols);
    for (int i = 0; i < this->rows; i++)
    {
      for (int j = 0; j < this->cols; j++){
        ds3("|");
        ds3(matrix[i][j]);
        //ds(this->get(i, j));
        //ds(" ");
      }
      ds3l();
    }
  }
//____________________________________________________________________
//------------Function------------------------------------------------
int getNumRows(){
  return this->rows;
}

//____________________________________________________________________
//------------Function------------------------------------------------
int getNumCols(){
  return this->cols;
}

//____________________________________________________________________
//------------Function------------------------------------------------
int get(int rows,int cols){
    int value=-1;
    // Obtener el value de la matrix en una posici�n espec�fica
    if (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols){
      value=matrix[rows][cols];
      /*ds("MatrixClass.GET OK: ");
      ds("row=:");
      ds(rows);
      ds(" col:");
      dsl(cols);
      ds(" value:");
      dsl(value);*/
      //return matrix[rows][cols];
    }else{
      // Manejar un value fuera de rango
      ds("MatrixClass.GET Out of index: ");
      ds("row=:");
      ds(rows);
      ds(" col:");
      dsl(cols);
      value=-1;
    }
    return value;
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void set(int rows,int cols, int value){

    // Establecer el value de la matrix en una posici�n espec�fica
    if (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols){
      // matrix[rows][cols] = constrain(value, minValue, maxValue);
      if (value >= minValue && value <= this->maxValue){
        matrix[rows][cols] = value;
      }else{
        ds("MatrixClass.SET: Value out of range");
        ds("Value: ");
        dsl(value);
        
        }
    }else{      
      ds("MatrixClass.SET Out of index: ");
      ds("row=:");
      ds(rows);
      ds(" col:");
      dsl(cols);
    }
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void clear(){

    // Liberar la memoria de la matrix
    for (int i = 0; i < rows; i++)
 {
      delete[] matrix[i];
    }
    delete[] matrix;
    // Establecer la matriz a NULL para evitar problemas de doble liberación
    matrix = nullptr;
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
 {
      matrix[i] = new int[cols];
      for (int j = 0; j < cols; j++)
   {
        matrix[i][j] = 0;
        }
}
    // Restablecer las dimensiones de la matriz a 0
    /*rows = 0;
    cols = 0;*/
  }
};
#endif // _MATRIX_CLASS_
