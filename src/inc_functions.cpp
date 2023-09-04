
#include "inc_include.h"


 
int *convProgToArray(const int *phrase,int starIn, int size){
  int* arrayReturn;
  arrayReturn=(int*)calloc((size+starIn),sizeof(int));
  arrayReturn[0]=size;
  for (int i=0; i < size; i++){
      arrayReturn[i+starIn]=pgm_read_word(phrase+i);
  }
  return arrayReturn;
}


void printMatrix(int *vMatrix){
  
  
  int tam=vMatrix[0];
  for (int i=0;i<tam; i++){
      if(vMatrix[i+1]!=EL && vMatrix[i+1]!=EA){      
        debug3l(vMatrix[i+1]);
      }else{
        debugl("");
      }
  }
  
}
int **CreateMatrix(int cols, int rows)
{

  int **tempMatrix = new int *[rows];
  for (int i = 0; i < rows; i++)
  {
    tempMatrix[i] = new int[cols];
    for (int j = 0; j < cols; j++)
    {
      tempMatrix[i][j] = 0;
    }
  }
  return tempMatrix;
}
/*
void printMatrix(Vector<Vector<int>> matriz){
  debugl("");
  debugl("-------------------------------");
  for (size_t i=0; i < 5; i++){
    for (size_t j=0; j < 7; j++){
      debug(matriz[j][i]);
      
    }
    debugl("");
  }
}*/

/*
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
}*/
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
