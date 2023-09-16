#include <Arduino.h>
#include "inc_include.h"
#ifndef _VECTOR_CLASS_
  #define _VECTOR_CLASS_

class VectorClass {
private:
   int size;       // Tamaño del vector
  int minRange;   // Valor mínimo permitido
  int maxRange;   // Valor máximo permitido
  int posActual;
  int sizeFixed;
public:
  int *data;      // Puntero al vector de datos

  // Constructor: inicializa el vector y establece los límites
   //VectorClass() : data(nullptr), size(0) {}

    // Constructor de copia
  VectorClass(const VectorClass& other) : size(other.size) {
        // Realizar una copia profunda de los datos
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

  VectorClass(int size, int minRange, int maxRange) {
    this->size = size;
    this->minRange = minRange;
    this->maxRange = maxRange;
    this->posActual=0;
    this->sizeFixed = size;
    this->data = new int[size];
    debug("Size=");
    debugl(size);
    for(int i=0; i<size; i++) {
      this->data[i] = 100+i;
    }
  }

  // Destructor: libera la memoria del vector
  ~VectorClass() {
    delete[] this->data;
  }

  // Método para establecer un valor en una posición del vector
  void set(int index, int value) {
        
    /*if (index >= 0 && index < size) {
      if (value >= minRange && value <= maxRange) {      */
        this->data[index] = value;
        debug("this->data[");
        debug(index);
        debug("] = ");
        debug(value);
        debug(" data[index]=");
        debugl(data[index]);
      /*} else {
        debug("Out of range, value=");
        debugl(value); 
      }
    } else {
      debug("Out of Index ");
      debugl(index);
    }*/
  }

  // Método para obtener el valor en una posición del vector
  int get(int index) {
    if (index >= 0 && index < size) {
      return this->data[index];
    } else {
      debug("Out of Index ");
      debugl(index);
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
      for (int i = 0; i < size; i++) {
        newData[i] = data[i];
      }
      
      // Liberar la memoria del arreglo antiguo
      delete[] data;
      
      // Actualizar el puntero y el tamaño
      data = newData;
      size--;
    } else {
      debugl("Vector is empty. Cannot pop.");
    }
  }
  int getSize() {
    return size;
  }
  void print() {
    for(int i = 0; i < size; i++) {
      debug(i);
      debug("=");
      debug(data[i]);
      debug(" |");
    }
    debugl("");
  }
};

#endif //_VECTOR_CLASS_