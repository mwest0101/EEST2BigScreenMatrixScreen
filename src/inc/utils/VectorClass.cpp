
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
#ifndef _VECTOR_CLASS_
  #define _VECTOR_CLASS_
class VectorClass{
private:
  int size;       // Tama�o del vector
  int minRange;   // Valor m�nimo permitido
  int maxRange;   // Valor m�ximo permitido
  int posActual;
  int sizeFixed;
  int defValue;
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
	
  VectorClass(int size, int defValue,int minRange, int maxRange){
    this->size = size;
    this->minRange = minRange;
    this->maxRange = maxRange;
    this->defValue=defValue;
    this->posActual=0;
    this->sizeFixed = size;
    this->data = new int[size];
    //ds5("Size=");
    //ds5l(size);
    for(int i=0; i<size; i++){
      this->data[i] = this->defValue;
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
        data[i] = this->defValue;
      }
    }
    
  }
  void reset(){
    for(int i=0; i<size; i++){
      this->data[i] = this->defValue;
    }
  }
  // M�todo para establecer un valor en una posici�n del vector
  void set(int index, int value){
        
    if (index >= 0 && index < size){
      if (value >= minRange && value <= maxRange) {      
        this->data[index] = value;

      } else{
        ds5("Out of range, value=");
        ds5l(value); 
      }
    } else{
      ds5("Out of Index ");
      ds5l(index);
    }
  }
  // M�todo para obtener el valor en una posici�n del vector
  int get(int index){
    if (index >= 0 && index < size){
      return this->data[index];
    } else{
      ds5("Out of Index ");
      ds5l(index);
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
      ds5l("Vector is empty. Cannot pop.");
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
    ds5("i=");
    for(int i = 0; i < size; i++){      
      if(i<10) ds5(" ");
      ds5(i);ds5("|");
    }
    ds5l("");
    ds5("d=");
    for(int i = 0; i < size; i++){
      if(data[i]<10) ds5(" ");
      ds5(data[i]);ds5("|");
    }
    ds5l("");
  }
};
#endif //_VECTOR_CLASS_



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