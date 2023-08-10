
#include "inc_include.h"

int *convProgToArray(const int *phrase,size_t size){
  int* arrayReturn;
  arrayReturn=(int*)calloc((size),sizeof(int));
  for (size_t i=0; i < size; i++){
      arrayReturn[i]=pgm_read_word(phrase+i);
  }
  return arrayReturn;
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
