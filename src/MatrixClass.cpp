#include <Arduino.h>
#include "inc_include.h"
#ifndef _MATRIX_CLASS_
  #define _MATRIX_CLASS_
class MatrixClass{

private:
  int **matrix;
  int row;
  int column;
  int minValue;
  int maxValue;
public:
  MatrixClass(int column, int row, int min, int max){

    this->column = column;
    this->row = row;
    this->minValue = min;
    this->maxValue = max;
    // Inicializar la matrix con valuees aleatorios dentro del rango especificado
    matrix = new int *[row];
    for (int i = 0; i < row; i++)
 {
      matrix[i] = new int[column];
      for (int j = 0; j < column; j++)
   {
        matrix[i][j] = 0;
        }
}
  }
  ~MatrixClass(){

    // Liberar la memoria de la matrix
    for (int i = 0; i < row; i++)
 {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void print(){

    for (int i = 0; i < row; i++)
 {
      for (int j = 0; j < column; j++){
        debug("|");
        debug(matrix[i][j]);
        //debug(" ");
      }
      debugl();
    }
  }
//____________________________________________________________________
//------------Function------------------------------------------------
int get(int row, int column){

    // Obtener el value de la matrix en una posici�n espec�fica
    if (row >= 0 && row < this->row && column >= 0 && column < this->column)
 {
      return matrix[row][column];
    }
    else
 {
      // Manejar un value fuera de rango
      debug("Row: Out of index =");
      debug(row);
      debug("Col: Out of index =");
      debugl(column);
      return -1;
    }
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void set(int row, int column, int value){

    // Establecer el value de la matrix en una posici�n espec�fica
    if (row >= 0 && row < this->row && column >= 0 && column < this->column)
 {
      // matrix[row][column] = constrain(value, minValue, maxValue);
      if (value >= minValue && value <= this->maxValue)
   {
        matrix[row][column] = value;
      }
      else
   {
        debugl(" SET:");
        debug("Error: Value fuera de rango:");
        debugl(value);
        
        }
}
    else
 {
      debugl(" SET:");
      debug("Error: Index fuera de rango:");      
      debug(" row:");
      debug(row);
      debug(" column:");
      debugl(column);
    }
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void clear(){

    // Liberar la memoria de la matrix
    for (int i = 0; i < row; i++)
 {
      delete[] matrix[i];
    }
    delete[] matrix;
    // Establecer la matriz a NULL para evitar problemas de doble liberación
    matrix = nullptr;
    matrix = new int *[row];
    for (int i = 0; i < row; i++)
 {
      matrix[i] = new int[column];
      for (int j = 0; j < column; j++)
   {
        matrix[i][j] = 0;
        }
}
    // Restablecer las dimensiones de la matriz a 0
    /*row = 0;
    column = 0;*/
  }
};
#endif // _MATRIX_CLASS_
