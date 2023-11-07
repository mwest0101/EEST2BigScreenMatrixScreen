#include <Arduino.h>
#include "inc/include.h"


#ifndef _MATRIX_CLASS_STRING_
  #define _MATRIX_CLASS_STRING_
class MatrixClassString
{

private:
  String **matrix;
  int rows;
  int cols;
  int minValue;
  int maxValue;

public:
  MatrixClassString(int rows, int cols)
  {

    this->rows = rows;
    this->cols = cols;

    // Inicializar la matrix con valuees aleatorios dentro del rango especificado
    matrix = new String *[rows];
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = new String[cols];
      for (int j = 0; j < cols; j++)
      {
        matrix[i][j] = "";
      }
    }
  }
  ~MatrixClassString()
  {

    // Liberar la memoria de la matrix
    for (int i = 0; i < rows; i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
  // Metodo para agregar un valor al final del vector (push)

  //____________________________________________________________________
  //------------Function------------------------------------------------
  void print()
  {
    ds5l("============================================================");
    ds5("this->rows:");
    ds5(this->rows);
    ds5(" this->cols:");
    ds5l(this->cols);
    ds5l(" ");
    ds5("=====");
    for (int j = 0; j < this->cols; j++)
    {

      if (j < 10)
        ds5(" ");
      ds5(j);
      ds5("|");
    }
    ds5l("");
    for (int j = 0; j < this->cols; j++)
    {
      ds5("---");
    }
    ds5l("");
    for (int i = 0; i < this->rows; i++)
    {
      if (i < 10)
        ds5(" ");
      ds5(i);
      ds5(" = ");
      for (int j = 0; j < this->cols; j++)
      {

        ds5(matrix[i][j]);
        ds5("|");
        // ds5(this->get(i, j));
        // ds5(" ");
      }
      ds5l();
    }
  }
  //____________________________________________________________________
  //------------Function------------------------------------------------
  int getNumRows()
  {
    return this->rows;
  }

  //____________________________________________________________________
  //------------Function------------------------------------------------
  int getNumCols()
  {
    return this->cols;
  }

  //____________________________________________________________________
  //------------Function------------------------------------------------
  String get(int rows, int cols)
  {
    String value = "";
    // Obtener el value de la matrix en una posici�n espec�fica
    if (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols)
    {
      value = matrix[rows][cols];
      /*ds5("MatrixClassString.GET OK: ");
      ds5("row=:");
      ds5(rows);
      ds5(" col:");
      ds5l(cols);
      ds5(" value:");
      ds5l(value);*/
      // return matrix[rows][cols];
    }
    else
    {
      // Manejar un value fuera de rango
      ds5("MatrixClassString.GET Out of index: ");
      ds5("row=:");
      ds5(rows);
      ds5(" col:");
      ds5l(cols);
      value = -1;
    }
    return value;
  }
  //____________________________________________________________________
  //------------Function------------------------------------------------
  void set(int rows, int cols, String value)
  {

    // Establecer el value de la matrix en una posici�n espec�fica
    if (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols)
    {
      // matrix[rows][cols] = constrain(value, minValue, maxValue);

      matrix[rows][cols] = value;
    }
    else
    {
      ds5("MatrixClassString.SET Out of index: ");
      ds5("row=:");
      ds5(rows);
      ds5(" col:");
      ds5l(cols);
    }
  }
  //____________________________________________________________________
  //------------Function------------------------------------------------
  void clear()
  {

    // Liberar la memoria de la matrix
    for (int i = 0; i < rows; i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
    // Establecer la matriz a NULL para evitar problemas de doble liberación
    matrix = nullptr;
    matrix = new String *[rows];
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = new String[cols];
      for (int j = 0; j < cols; j++)
      {
        matrix[i][j] = "";
      }
    }
    // Restablecer las dimensiones de la matriz a 0
    /*rows = 0;
    cols = 0;*/
  }
  void push(String value1, String value2)
  {
    if (rows >= 0)
    {

      String **newMatrix = new String *[rows + 1];
      for (int i = 0; i < rows; i++)
      {
        newMatrix[i] = new String[cols];
        for (int j = 0; j < cols; j++)
        {
          newMatrix[i][j] = "";
        }
      }
      newMatrix[rows][0] = value1;
      newMatrix[rows][1] = value2;

      for (int i = 0; i < rows; i++)
      {
        delete[] matrix[i];
      }
      delete[] matrix;
      matrix = newMatrix;
    }
    else
    {
      set(0, 0, value1);
      set(0, 1, value2);
    }
  }
  /*
  void pushVec(String value){

    if (size >= 0){

      String *newData = new String[size + 1];
      for (int i = 0; i < size; i++){
        newData[i] = data[i];
      }



      newData[size] = value;
      delete[] data;
      data = newData;
      size++;
    } else{
      set(0, value);
    }
  }
  */
};
#endif //_VECTOR_CLASS_STRING_