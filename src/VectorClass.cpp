
#include <Arduino.h>
#include "inc_include.h"
#ifndef _VECTOR_CLASS_
  #define _VECTOR_CLASS_
class VectorClass{
private:
  int size;       // Tama�o del vector
  int minRange;   // Valor m�nimo permitido
  int maxRange;   // Valor m�ximo permitido
  int posActual;
  int sizeFixed;
public:
  int *data;      // Puntero al vector de datos
  // Constructor: inicializa el vector y establece los l�mites
   //VectorClass() : data(nullptr), size(0) {}
    // Constructor de copia
  VectorClass(const VectorClass& other) : size(other.size){
        // Realizar una copia profunda de los datos
        data = new int[size];
        for (int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }
  VectorClass(int size, int minRange, int maxRange){
    this->size = size;
    this->minRange = minRange;
    this->maxRange = maxRange;
    this->posActual=0;
    this->sizeFixed = size;
    this->data = new int[size];
    //debug("Size=");
    //debugl(size);
    for(int i=0; i<size; i++){
      this->data[i] = 0;
    }
  }
  // Destructor: libera la memoria del vector
  ~VectorClass(){
    delete[] this->data;
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void clear(){
    if (size > 0){
      // Liberar la memoria del arreglo actual
      delete[] data;
      // Crear un nuevo arreglo vacío
      this->size = 0;
      data = new int[size];
      //size = sizeFixed;
      // Reinicializar todos los elementos a 0
      for (int i = 0; i < size; i++){
        data[i] = 0;
      }
    }
    
  }
  // M�todo para establecer un valor en una posici�n del vector
  void set(int index, int value){
        
    if (index >= 0 && index < size){
      if (value >= minRange && value <= maxRange) {      
        this->data[index] = value;
        debug("this->data[");
        debug(index);
        debug("] = ");
        debug(value);
        debug(" data[index]=");
        debugl(data[index]);
      } else{
        debug("Out of range, value=");
        debugl(value); 
      }
    } else{
      debug("Out of Index ");
      debugl(index);
    }
  }
  // M�todo para obtener el valor en una posici�n del vector
  int get(int index){
    if (index >= 0 && index < size){
      return this->data[index];
    } else{
      debug("Out of Index ");
      debugl(index);
    }
    return 0; // O podr�as lanzar una excepci�n o manejar el error de otra manera
  }
  // M�todo para agregar un valor al final del vector (push)
  void push(int value){
    if (size >= 0){
      // Crear un nuevo arreglo con un tama�o mayor
      int *newData = new int[size + 1];
      
      // Copiar los datos actuales al nuevo arreglo
      for (int i = 0; i < size; i++){
        newData[i] = data[i];
      }
      
      // Agregar el nuevo valor al final del nuevo arreglo
      newData[size] = value;
      
      // Liberar la memoria del arreglo antiguo
      delete[] data;
      
      // Actualizar el puntero y el tama�o
      data = newData;
      size++;
    } else{
      // Si el tama�o actual es 0, simplemente establece el valor en la posici�n 0
      set(0, value);
    }
  }
  // M�todo para eliminar el �ltimo valor del vector (pop)
  void pop(){
    if (size > 0){
      // Crear un nuevo arreglo con un tama�o menor
      int *newData = new int[size - 1];
      
      // Copiar los datos actuales excepto el �ltimo al nuevo arreglo
      for (int i = 0; i < size; i++){
        newData[i] = data[i];
      }
      
      // Liberar la memoria del arreglo antiguo
      delete[] data;
      
      // Actualizar el puntero y el tama�o
      data = newData;
      size--;
    } else{
      debugl("Vector is empty. Cannot pop.");
    }
  }
//____________________________________________________________________
//------------Function------------------------------------------------
int getSize(){
    return size;
  }
//____________________________________________________________________
//------------Function------------------------------------------------
void print(){
    for(int i = 0; i < size; i++){
      debug(i);
      debug("=");
      debug(data[i]);
      debug(" |");
    }
    debugl("");
  }
};
#endif //_VECTOR_CLASS_