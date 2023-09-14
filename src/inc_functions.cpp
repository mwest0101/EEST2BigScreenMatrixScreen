
#include "inc_include.h"
//#include "VectorClass.cpp"


 
void convProgToArray(VectorClass &vecTemp,const int *phrase, int size){
  //int* arrayReturn;
  
  //arrayReturn=(int*)calloc((size+starIn),sizeof(int));
  //arrayReturn[0]=size;
  for (int i=0; i < size; i++){
      //vecTemp.push(((int)pgm_read_word(phrase+i)));
      vecTemp.set(i,((int)pgm_read_word(phrase+i)));
      
      //arrayReturn[i+starIn]=pgm_read_word(phrase+i); //uint16_t
  }
  
  //return vecTemp;
}
 
VectorClass convProgToArray2(const int *phrase, int size){
  //int* arrayReturn;
  VectorClass vecTemp(36, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);   
  //arrayReturn=(int*)calloc((size+starIn),sizeof(int));
  //arrayReturn[0]=size;
  int element=0;
  for (int i=0; i < size; i++){
      //vecTemp.push(((int)pgm_read_word(phrase+i)));
      element=((int)pgm_read_word(phrase + i));
      debug3("element=");
      debug(element);
      debugl("");
      vecTemp.set(i,element);
      //arrayReturn[i+starIn]=pgm_read_word(phrase+i); //uint16_t
  }
  return vecTemp;
  //return vecTemp;
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
int **CreateMatrix(int **matrix,int cols, int rows)
{

  matrix = new int *[rows];
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new int[cols];
    for (int j = 0; j < cols; j++)
    {
      matrix[i][j] = 0;
    }
  }
  return matrix;
}
