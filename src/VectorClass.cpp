#include "inc_include.h"



class VectorClass {

  VectorClass::VectorClass(int capacity, int minRange, int maxRange) {
    this->capacity = capacity;
    this->minRange = minRange;
    this->maxRange = maxRange;
    this->size = 0; // El vector comienza vacío
    this->data = new int[capacity];
    for (int i = 0; i < capacity; i++) {
      this->data[i] = 0;
    }
  }

  // Destructor: libera la memoria del vector
  ~VectorClass::VectorClass() {
    delete[] this->data;
  }

  // Método para agregar un valor al final del vector
  void VectorClass::pushBack(int value) {
    if ((this->size < this->capacity) && (value >= this->minRange) && (value <= this->maxRange)) {
      this->data[this->size] = value;
      this->size++;
    } else {
      debug("Unable to push value, out of range or vector is full, value=");
      debugl(value);
    }
  }

  // Método para eliminar el último elemento del vector
  void VectorClass::popBack() {
    if (this->size > 0) {
      this->size--;
    } else {
      debugl("Vector is empty, cannot pop.");
    }
  }

  // Método para obtener el tamaño actual del vector
  int VectorClass::getSize() {
    return this->size;
  }

  // Método para obtener el valor en una posición del vector
  int VectorClass::get(int index) {
    if (index >= 0 && index < this->size) {
      return this->data[index];
    } else {
      debug("Out of Index ");
      debugl(index);
    }
    return 0; // O podrías lanzar una excepción o manejar el error de otra manera
  }
  void VectorClass::set(int index, int value) {
    if (index >= 0 && index < this->size) {
      if (value >= this->minRange && value <= this->maxRange) {      
        this->data[index] = (int)value;
      }else{
       debug("Out of range ,value=");
       debugl(value); 
      }
    }else{
       debug("Out of Index ");
       debugl(index);
    }
  }
  void VectorClass::print() {
    for (int i = 0; i < this->size; i++) {
      debug(this->data[i]);
      debug(" ");
    }
    debugl("");
  }
};


  