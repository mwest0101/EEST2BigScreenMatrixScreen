
#include <Arduino.h>
#include "inc_include.h"
void convProgToArray(VectorClass &aIntCharMatrix, const int *phrase, int size)
{
  int element = 0;
  for (int i = 0; i < size; i++)
  {
    element = ((int)pgm_read_word(phrase + i));
    aIntCharMatrix.push(element);
  }
  dsl(" ");
}
/*
void convProgToArrayByFrame(VectorClass &aIntCharMatrix,const int *phrase, int size){

  int element=0;
  static int i=0;
  while (i<size and element!=EA){
      element=((int)pgm_read_word(phrase + i));
      aIntCharMatrix.push(element);
      i++;
  }
  dsl(" ");
}*/
//____________________________________________________________________
//------------Function------------------------------------------------
void printMatrix(int *vMatrix)
{
  int tam = vMatrix[0];
  for (int i = 0; i < tam; i++)
  {
    if (vMatrix[i] != EL && vMatrix[i] != EA)
    {
      ds3(vMatrix[i]);
    }
    else
    {
      dsl("");
    }
  }
}
//____________________________________________________________________
//------------Function------------------------------------------------
int **CreateMatrix(int **matrix, int cols, int rows)
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

String concParamsOfString(char charReaded,String strOption,int &action)
{
  
  if (charReaded == '(')
  {
    dss();ds("se encuentra (");ds(" contCharAdded: ");dsl(contCharAdded);
    strOption = "";
    action = 10;
    //contCharAdded++;
  }
  else if (charReaded == ')')
  {
    dss();
    dsl("se encuentra )");
    ds(" contCharAdded: ");
    dsl(contCharAdded);
    //contCharAdded++;
    //--ver-->pm.setIfisEnd(false);
    action = 15;
  }
  else if (action == 10)
  {

    strOption = strOption + charReaded;
    dss();
    dsl("Concatena:");
    ds("strOption:");
    dsl(strOption);

    //contCharAdded++;
    ds("Entre a concatenacion de efectos ");
    ds(" contCharAdded: ");
    dsl(contCharAdded);
    ds(" strOption: ");
    dsl(strOption);
  }
  return strOption;
}