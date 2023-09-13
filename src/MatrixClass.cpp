
#ifndef _MATRIX_CLASS_
  #define _MATRIX_CLASS_
  #include "inc_include.h"

class MatrixClass {
private:
  int **matrix;
  int row;
  int column;
  int minValue;
  int maxValue;

public:
  MatrixClass(int column, int row, int min, int max) {
    this->row = row;
    this->column = column;
    this->minValue = min;
    this->maxValue = max;

    // Inicializar la matrix con valores aleatorios dentro del rango especificado
    matrix = new int *[row];
    for (int i = 0; i < row; i++) {
      matrix[i] = new int[column];
      for (int j = 0; j < column; j++) {
        matrix[i][j] = 0;
      }
    }
  }

  ~MatrixClass() {
    // Liberar la memoria de la matrix
    for (int i = 0; i < row; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }

  void print() {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        debug(matrix[i][j]);
        debug("\t");
      }
      debugl();
    }
  }

  int get(int fila, int columna) {
    // Obtener el valor de la matrix en una posición específica
    if (fila >= 0 && fila < this->row && columna >= 0 && columna < this->column) {
      return matrix[fila][columna];
    } else {
      // Manejar un valor fuera de rango
      debug("Out of inde. row=");
      debug(fila);
      debug("Out of inde. col=");
      debugl(columna);
      return -1;
    }
  }

  void set(int fila, int columna, int valor) {
    // Establecer el valor de la matrix en una posición específica
    if (fila >= 0 && fila < this->row && columna >= 0 && columna < this->column) {
      //matrix[fila][columna] = constrain(valor, minValue, maxValue);
      if (valor >= minValue && valor <= this->maxValue) {
        matrix[fila][columna] = valor;
      }else {
      // Manejar un valor fuera de rango
        debugl("Error: Value out of range");
      }
    } else {
      // Manejar un valor fuera de rango
      debugl("Error: Index Out range");
    }
  }
};

#endif /* _MATRIX_CLASS_ */