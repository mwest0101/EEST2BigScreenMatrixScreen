
// ╔══════════════════════════════════════════════════════════════════╗
// ║   ____    _             __  __           _            _          ║
// ║  |  _ \  (_)           |  \/  |         | |          (_)         ║
// ║  | |_) |  _    __ _    | \  / |   __ _  | |_   _ __   _  __  __  ║
// ║  |  _ <  | |  / _` |   | |\/| |  / _` | | __| | '__| | | \ \/ /  ║
// ║  | |_) | | | | (_| |   | |  | | | (_| | | |_  | |    | |  >  <   ║
// ║  |____/  |_|  \__, |   |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\  ║
// ║                __/ |                                             ║
// ║               |___/                                              ║
// ║                                                                  ║
// ║  _         _____   _____      _____                           _  ║
// ║ | |       / ____| |  __ \    |  __ \                         | | ║
// ║ | |      | |      | |  | |   | |__) |   __ _   _ __     ___  | | ║
// ║ | |      | |      | |  | |   |  ___/   / _` | | '_ \   / _ \ | | ║
// ║ | |____  | |____  | |__| |   | |      | (_| | | | | | |  __/ | | ║
// ║ |______|  \_____| |_____/    |_|       \__,_| |_| |_|  \___| |_| ║
// ║                                                                  ║
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝

#include <Arduino.h>
#include "inc/include.h"
#ifndef _MATRIX_CLASS_
#define _MATRIX_CLASS_
class MatrixClass
{

private:
  int **matrix;
  int rows;
  int cols;
  int minValue;
  int maxValue;
  int defValue;

public:
  MatrixClass(int rows, int cols,int defValue, int min, int max)
  {
    this->defValue=defValue;
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
        matrix[i][j] = this->defValue;
      }
    }
  }
  ~MatrixClass()
  {

    // Liberar la memoria de la matrix
    for (int i = 0; i < rows; i++)
    {
      delete[] matrix[i];
    }
    delete[] matrix;
  }
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

        if (matrix[i][j] < 10)
          ds5(" ");
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
  int get(int rows, int cols)
  {
    int value = -1;
    // Obtener el value de la matrix en una posici�n espec�fica
    if (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols)
    {
      value = matrix[rows][cols];
      /*ds5("MatrixClass.GET OK: ");
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
      ds5("MatrixClass.GET Out of index: ");
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
  void set(int rows, int cols, int value)
  {

    // Establecer el value de la matrix en una posici�n espec�fica
    if (rows >= 0 && rows < this->rows && cols >= 0 && cols < this->cols)
    {
      // matrix[rows][cols] = constrain(value, minValue, maxValue);
      if (value >= minValue && value <= this->maxValue)
      {
        matrix[rows][cols] = value;
      }
      else
      {
        ds5("MatrixClass.SET: Value out of range");
        ds5("Value: ");
        ds5l(value);
      }
    }
    else
    {
      ds5("MatrixClass.SET Out of index: ");
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
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = new int[cols];
      for (int j = 0; j < cols; j++)
      {
        matrix[i][j] = this->defValue;
      }
    }
    // Restablecer las dimensiones de la matriz a 0
    /*rows = 0;
    cols = 0;*/
  }
};
#endif // _MATRIX_CLASS_



// ╔══════════════════════════════════════════════════════════════════╗
// ║   ____    _             __  __           _            _          ║
// ║  |  _ \  (_)           |  \/  |         | |          (_)         ║
// ║  | |_) |  _    __ _    | \  / |   __ _  | |_   _ __   _  __  __  ║
// ║  |  _ <  | |  / _` |   | |\/| |  / _` | | __| | '__| | | \ \/ /  ║
// ║  | |_) | | | | (_| |   | |  | | | (_| | | |_  | |    | |  >  <   ║
// ║  |____/  |_|  \__, |   |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\  ║
// ║                __/ |                                             ║
// ║               |___/                                              ║
// ║                                                                  ║
// ║  _         _____   _____      _____                           _  ║
// ║ | |       / ____| |  __ \    |  __ \                         | | ║
// ║ | |      | |      | |  | |   | |__) |   __ _   _ __     ___  | | ║
// ║ | |      | |      | |  | |   |  ___/   / _` | | '_ \   / _ \ | | ║
// ║ | |____  | |____  | |__| |   | |      | (_| | | | | | |  __/ | | ║
// ║ |______|  \_____| |_____/    |_|       \__,_| |_| |_|  \___| |_| ║
// ║                                                                  ║
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝