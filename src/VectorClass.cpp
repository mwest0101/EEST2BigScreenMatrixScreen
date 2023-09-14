#include <Arduino.h>

class VectorClass {
private:
  int *data;      // Puntero al vector de datos
  int size;       // Tamaño del vector
  int minRange;   // Valor mínimo permitido
  int maxRange;   // Valor máximo permitido

public:
  // Constructor: inicializa el vector y establece los límites
  VectorClass(int size, int minRange, int maxRange) {
    this->size = size;
    this->minRange = minRange;
    this->maxRange = maxRange;
    this->data = new int[size];
    for(int i=0; i<size; i++) {
      this->data[i] = 0;
    }
  }

  // Destructor: libera la memoria del vector
  ~VectorClass() {
    delete[] this->data;
  }

  // Método para establecer un valor en una posición del vector
  void set(int index, int value) {
    if (index >= 0 && index < size) {
      if (value >= minRange && value <= maxRange) {      
        this->data[index] = value;
      } else {
        Serial.print("Out of range, value=");
        Serial.println(value); 
      }
    } else {
      Serial.print("Out of Index ");
      Serial.println(index);
    }
  }

  // Método para obtener el valor en una posición del vector
  int get(int index) {
    if (index >= 0 && index < size) {
      return this->data[index];
    } else {
      Serial.print("Out of Index ");
      Serial.println(index);
    }
    return 0; // O podrías lanzar una excepción o manejar el error de otra manera
  }

  // Método para agregar un valor al final del vector (push)
  void push(int value) {
    if (size >= 1) {
      // Crear un nuevo arreglo con un tamaño mayor
      int *newData = new int[size + 1];
      
      // Copiar los datos actuales al nuevo arreglo
      for (int i = 0; i < size; i++) {
        newData[i] = data[i];
      }
      
      // Agregar el nuevo valor al final del nuevo arreglo
      newData[size] = value;
      
      // Liberar la memoria del arreglo antiguo
      delete[] data;
      
      // Actualizar el puntero y el tamaño
      data = newData;
      size++;
    } else {
      // Si el tamaño actual es 0, simplemente establece el valor en la posición 0
      set(0, value);
    }
  }

  // Método para eliminar el último valor del vector (pop)
  void pop() {
    if (size > 0) {
      // Crear un nuevo arreglo con un tamaño menor
      int *newData = new int[size - 1];
      
      // Copiar los datos actuales excepto el último al nuevo arreglo
      for (int i = 0; i < size - 1; i++) {
        newData[i] = data[i];
      }
      
      // Liberar la memoria del arreglo antiguo
      delete[] data;
      
      // Actualizar el puntero y el tamaño
      data = newData;
      size--;
    } else {
      Serial.println("Vector is empty. Cannot pop.");
    }
  }
  int getSize() {
    return size;
  }
  void print() {
    for(int i = 0; i < size; i++) {
      Serial.print(data[i]);
      Serial.print(" ");
    }
    Serial.println("");
  }
};
