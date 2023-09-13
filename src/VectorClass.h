#include "inc_include.h"

#ifndef _VECTOR_CLASS_
  #define _VECTOR_CLASS_
  

class VectorClass {
private:
  int *data;      // Puntero al vector de datos
  int size;       // Tamaño actual del vector
  int capacity;   // Capacidad máxima del vector
  int minRange;   // Valor mínimo permitido
  int maxRange;   // Valor máximo permitido

public:  
  VectorClass(int capacity, int minRange, int maxRange);  
  ~VectorClass();
  void pushBack(int value); 
  void popBack();
  int getSize();
  // Método para obtener el valor en una posición del vector
  int get(int index) ;
  void set(int index, int value);
  void print();


#endif /*_VECTOR_CLASS_*/
  