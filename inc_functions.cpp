
#include "inc_include.h"



int *convProgToArray(const int *phrase,size_t size){
  int* arrayReturn;
  arrayReturn=(int*)calloc((size),sizeof(int));
  for (size_t i=0; i < size; i++){
      arrayReturn[i]=pgm_read_word(phrase+i);
  }
  return arrayReturn;
}

Vector<Vector<int>> convProgToMatrix(const int *phrase,size_t size){
  Vector<Vector<int>> matriz;
  int data=0;
  Vector<int> fila;
  for (size_t i=0; i < size; i++){
    data=pgm_read_word(phrase+i);
    if(data==EL){
        Vector<int> fila;
        matriz.push_back(fila);
    
     
    }else{
      fila.push_back(data);
    }
  }
  
  return matriz;
}

void printMatrix(Vector<Vector<int>> matriz){
  for (size_t i=0; i < matriz.size(); i++){
    for (size_t j=0; j < matriz[i].size(); j++){
      Serial.print(matriz[i][j]);
    }
  }
}


int **createMatrix(int rows,int cols){  
  int** matrix;   
  matrix = new int*[rows];
  
  for (int i = 0; i < rows; i++) {    
    matrix[i] = new int[cols];        
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = 0;
    }
  }
  return matrix;
}
/*
int selectRandom(long arrrayInt[],int cantElements){

	unsigned long sumTotal=0;
	unsigned long randomNumber=0;
	unsigned long acumNum=0;
	int contador=0;
	for(int i=0;i<cantElements;i++){
		sumTotal=sumTotal+(arrrayInt[i]*CONST_EFFECT_MULT);
	}
	randomNumber=random(sumTotal);
	acumNum=0;
	for (int i=0;i<cantElements;i++){
		if (randomNumber>acumNum){
			acumNum=acumNum+(arrrayInt[i]*CONST_EFFECT_MULT);
			contador++;

		}

	}

	return contador;

}*/
