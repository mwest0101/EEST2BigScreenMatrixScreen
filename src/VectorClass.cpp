#include <Arduino.h>
#include "inc_include.h"

#ifndef _VECTOR_CLASS_
#define _VECTOR_CLASS_
class VectorClass
{
private:
  int size;     // Tama�o del vector
  int minRange; // Valor mnimo permitido
  int maxRange; // Valor maximo permitido
  int posActual;
  int sizeFixed;

public:
  char *data; // Puntero al vector de datos
  // Constructor: inicializa el vector y establece los l�mites
  // VectorClass() : data(nullptr), size(0) {}
  // Constructor de copia

  VectorClass(const VectorClass &other) : size(other.size)
  {
    // Realizar una copia profunda de los datos
    data = new char[size];
    for (int i = 0; i < size; i++)
    {
      data[i] = other.data[i];
    }
  }
  VectorClass(int vSize, int minRange, int maxRange)
  {
    size = vSize;
    this->minRange = minRange;
    this->maxRange = maxRange;
    this->posActual = 0;
    sizeFixed = size;
    data = new char[size];
    // ds5("Size=");
    // ds5l(size);
    for (int i = 0; i < size; i++)
    {
      data[i] = 0;
    }
  }
  // Destructor: libera la memoria del vector
  ~VectorClass()
  {
    delete[] data;
  }
  //____________________________________________________________________
  //------------Function------------------------------------------------
  void clear()
  {
    if (size > 0)
    {
      // Liberar la memoria del arreglo actual
      delete[] data;
      // Crear un nuevo arreglo vacío
      size = 0;
      data = new char[size];
      // size = sizeFixed;
      //  Reinicializar todos los elementos a 0
      for (int i = 0; i < size; i++)
      {
        data[i] = 0;
      }
    }
  }
  void reset()
  {
    for (int i = 0; i < size; i++)
    {
      data[i] = 0;
    }
  }
  // M�todo para establecer un valor en una posici�n del vector
  void set(int index, int value)
  {

    if (index >= 0 && index < size)
    {
      if (value >= minRange && value <= maxRange)
      {
        data[index] = value;
      }
      else
      {
        ds5("Out of range, value=");
        ds5l(value);
      }
    }
    else
    {
      ds5("Out of Index ");
      ds5l(index);
    }
  }
  // M�todo para obtener el valor en una posici�n del vector
  char get(int index)
  {
    if (index >= 0 && index < size)
    {
      return data[index];
    }
    else
    {
      ds5("Out of Index ");
      ds5l(index);
    }
    return 0; // O podr�as lanzar una excepci�n o manejar el error de otra manera
  }
  // M�todo para agregar un valor al final del vector (push)
  void push(int value)
  {
    if (size >= 0)
    {
      // Crear un nuevo arreglo con un tama�o mayor
      char *newData = new char[size + 1];

      // Copiar los datos actuales al nuevo arreglo
      for (int i = 0; i < size; i++)
      {
        newData[i] = data[i];
      }

      // Agregar el nuevo valor al final del nuevo arreglo
      newData[size] = value;

      // Liberar la memoria del arreglo antiguo
      delete[] data;

      // Actualizar el puntero y el tama�o
      data = newData;
      ds5("data(");
      ds5(size);
      ds5(")=");
      ds5l((int)data[size]);

      size++;
    }
    else
    {
      // Si el tama�o actual es 0, simplemente establece el valor en la posici�n 0
      set(0, value);
    }
  }
  // M�todo para eliminar el �ltimo valor del vector (pop)
  void pop()
  {
    if (size > 0)
    {
      // Crear un nuevo arreglo con un tama�o menor
      char *newData = new char[size - 1];

      // Copiar los datos actuales excepto el �ltimo al nuevo arreglo
      for (int i = 0; i < size; i++)
      {
        newData[i] = data[i];
      }

      // Liberar la memoria del arreglo antiguo
      delete[] data;

      // Actualizar el puntero y el tama�o
      data = newData;
      size--;
    }
    else
    {
      ds5l("Vector is empty. Cannot pop.");
    }
  }
  //____________________________________________________________________
  //------------Function------------------------------------------------
  int getSize()
  {
    return size;
  }
  //____________________________________________________________________
  //------------Function------------------------------------------------
  void print()
  {
    /* ds5("i=");
     for(int i = 0; i < size; i++){
       if(i<10){ ds5(" ");}
       ds5(i);ds5("|");
     }
     ds5l("");*/
    ds5("d=");
    for (int i = 0; i < size; i++)
    {
      // ds5("->");
      if (data[i] < 10)
      {
        ds5(" ");
      }
      ds5((int)data[i]);
      ds5("|");
    }
    ds5l("");
  }
};

#endif //_VECTOR_CLASS_