
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
// #include "inc_include.h"
#ifndef _VECTOR_CLASS_STRING_
  #define _VECTOR_CLASS_STRING_

class VectorClassString{
private:
  int size;       // Tamaao del vector

  int posActual;
  int sizeFixed;
public:
  String *data;      // Puntero al vector de datos
  // Constructor: inicializa el vector y establece los lamites
   //VectorClass() : data(nullptr), size(0) {}
    // Constructor de copia
  VectorClassString(const VectorClassString& other) : size(other.size){
        // Realizar una copia profunda de los datos
        data = new String[size];
        for (int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }
	
  VectorClassString(int size){
    this->size = size;
    
    this->posActual=0;
    this->sizeFixed = size;
    this->data = new String[size];
    //ds5("Size=");
    //ds5l(size);
    for(int i=0; i<size; i++){
      this->data[i] = "";
    }
  }
  // Destructor: libera la memoria del vector
  ~VectorClassString(){
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
      
      this->posActual=0;
      this->sizeFixed = size;
      data = new String[size];
      //size = sizeFixed;
      // Reinicializar todos los elementos a 0
      for (int i = 0; i < size; i++){
        data[i] = "";
      }
    }
    
  }
  void reset(){
    for(int i=0; i<size; i++){
      this->data[i] = "";
    }
  }
  // Metodo para establecer un valor en una posician del vector
  void set(int index, String value){
        
    if (index >= 0 && index < size){
      
        this->data[index] = value;

    } else{
      ds5("Out of Index ");
      ds5l(index);
    }
  }
  // Metodo para obtener el valor en una posician del vector
  String get(int index){
    if (index >= 0 && index < size){
      return this->data[index];
    } else{
      ds5("Out of Index ");
      ds5l(index);
    }
    return ""; // O podraas lanzar una excepcian o manejar el error de otra manera
  }
  // Metodo para agregar un valor al final del vector (push)
  void push(String value){
    if (size >= 0){
      // Crear un nuevo arreglo con un tamaao mayor
      String *newData = new String[size + 1];
      
      // Copiar los datos actuales al nuevo arreglo
      for (int i = 0; i < size; i++){
        newData[i] = data[i];
      }
      
      // Agregar el nuevo valor al final del nuevo arreglo
      newData[size] = value;

      // Liberar la memoria del arreglo antiguo
      delete[] data;
      
      // Actualizar el puntero y el tamaao
      data = newData;
      size++;
    } else{
      // Si el tamaao actual es 0, simplemente establece el valor en la posician 0
      set(0, value);
    }
  }
  // Metodo para eliminar el altimo valor del vector (pop)
  void pop(){
    if (size > 0){
      // Crear un nuevo arreglo con un tamaao menor
      String *newData = new String[size - 1];
      
      // Copiar los datos actuales excepto el altimo al nuevo arreglo
      for (int i = 0; i < size; i++){
        newData[i] = data[i];
      }
      
      // Liberar la memoria del arreglo antiguo
      delete[] data;
      
      // Actualizar el puntero y el tamaao
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
    
    for(int i = 0; i < size; i++){
      ds5("[")
      ds5(i);
      ds5("]=")
      ds5(data[i]);
      ds5l(" ");
    }
    ds5l("");
  }
};
#endif //_VECTOR_CLASS_STRING_




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