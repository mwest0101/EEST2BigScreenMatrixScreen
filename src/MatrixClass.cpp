#include <Arduino.h>
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
        Serial.print(matrix[i][j]);
        Serial.print("\t");
      }
      Serial.println();
    }
  }

  int get(int fila, int columna) {
    // Obtener el valor de la matrix en una posici�n espec�fica
    if (fila >= 0 && fila < this->row && columna >= 0 && columna < this->column) {
      return matrix[fila][columna];
    } else {
      // Manejar un valor fuera de rango
      Serial.print("Out of inde. row=");
      Serial.print(fila);
      Serial.print("Out of inde. col=");
      Serial.println(columna);
      return -1;
    }
  }

  void set(int fila, int columna, int valor) {
    // Establecer el valor de la matrix en una posici�n espec�fica
    if (fila >= 0 && fila < this->row && columna >= 0 && columna < this->column) {
      //matrix[fila][columna] = constrain(valor, minValue, maxValue);
      if (valor >= minValue && valor <= this->maxValue) {
        matrix[fila][columna] = valor;
      }else {
      // Manejar un valor fuera de rango
        Serial.println("Error: Value out of range");
      }
    } else {
      // Manejar un valor fuera de rango
      Serial.println("Error: Index Out range");
    }
  }
};

