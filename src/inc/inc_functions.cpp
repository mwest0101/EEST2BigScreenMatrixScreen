
#include <Arduino.h>
#include "inc/include.h"
void convProgToArray(VectorClass& aIntCharMatrix, const int* phrase, int size) {
  int element = 0;
  for (int i = 0; i < size; i++) {
    //element = ((int)pgm_read_word(phrase + i));
    element = ((int)pgm_read_word(&phrase[i]));
    aIntCharMatrix.push(element);
    //aIntCharMatrix.set(i, element);
   // ds(element);
    //ds("-");
  }
  dsl(" ");
  //aIntCharMatrix.print();

}
void convProgToArray2(int* aIntCharMatrix, const int* phrase, int size) {
  int element = 0;
  for (int i = 0; i < size; i++) {
    element = ((int)pgm_read_word(&phrase[i]));
    aIntCharMatrix[i] = element;
    ds("(");
    ds("i=");
    ds(i);
    ds("|");
    ds(element);
    ds("),");
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
void printMatrix(int* vMatrix) {
  int tam = vMatrix[0];
  for (int i = 0; i < tam; i++) {
    if (vMatrix[i] != EL && vMatrix[i] != EA) {
      ds3(vMatrix[i]);
    }
    else {
      dsl("");
    }
  }
}
//____________________________________________________________________
//------------Function------------------------------------------------
int** CreateMatrix(int** matrix, int cols, int rows) {

  matrix = new int* [rows];
  for (int i = 0; i < rows; i++) {

    matrix[i] = new int[cols];
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = 0;
    }
  }
  return matrix;
}

void strToVector(String strIng, String* aStrsParam, String* aStrsValor) {
  int size = strIng.length();
  String strtemp = "";
  String charTemp = "";
  String lastCharTemp = "";
  bool isParam = false;
  bool isText = false;
  int cont = 0;
  dsl("strToVector");

  for (int i = 0; i < size; i++) {
    charTemp = strIng[i];
    dsl("strToVector-->Entre for:");


    if (charTemp == "(" && isText == false) {
      isText = false;
      isParam = true;
    }
    else if (isParam) {
      if (charTemp == ":") {
        aStrsParam[cont] = lastCharTemp;

      }
      else if (charTemp == "|" || charTemp == ")") {
        aStrsValor[cont] = strtemp;
        strtemp = "";
        cont++;
      }
      if (charTemp == ")") {
        isParam = false;

      }
    }
    else {
      if (isText == false) {
        aStrsParam[cont] = "t";
        isText = true;
      }
      else {
        strtemp = strtemp + charTemp;

      }
      if ((charTemp == "(" && isText == true) || (i == size - 1)) {
        aStrsValor[cont] = strtemp;
        strtemp = "";
      }
    }


    lastCharTemp = charTemp;
    strtemp = strtemp + charTemp;
  }

}

String concParamsOfString(char charReaded, String strOption, int& action) {

  if (charReaded == '(') {
    dss();ds("se encuentra (");ds(" charReaded: ");dsl(charReaded);
    strOption = "";
    action = 10;
    //charReaded++;
  }
  else if (action == 10 || action == 11) {

    strOption = strOption + charReaded;
    dss();dsl("Concatena:");ds("strOption:");dsl(strOption);
    ds("Entre a concatenacion de efectos ");ds(" charReaded: ");dsl(charReaded);
    ds(" strOption: ");dsl(strOption);
    action = 11;

  }
  else if ((charReaded == ')' || charReaded == ':') && action == 11) {
    dss();dsl("se encuentra )");ds(" charReaded: ");dsl(charReaded);
    action = 19;
  }

  return strOption;

}

/*
void remove(char *str, char findChar, char replaceChar) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == findChar) {
      str[i] = replaceChar;
    }
  }
}


void splitStringWithVariosChar(VectorClassString& dataArray, String inputString, String delimiter) {
  replaceCharInString(delimiter,'(','')
  int commaIndex = inputString.indexOf(delimiter);

  while (commaIndex != -1) {
    dataArray.push(inputString.substring(0, commaIndex));
    inputString = inputString.substring(commaIndex + 1);
    commaIndex = inputString.indexOf(delimiter);
  }
  dataArray.push(inputString);
}*/

void stringTokeyAndValue(MatrixClassString& matStr, String inputString, String delimiter1, String delimiter2) {

  VectorClassString vecStr(0);
  VectorClassString vecTemp(0);
  VectorClassString keyValue(0);
  String strVal1 = "";
  String strVal2 = "";
  splitStringToArray(vecStr, inputString, delimiter1);
  // vecStr.print();
  for (int i = 0; i < vecStr.getSize(); i++) {
    vecTemp.clear();
    VectorClassString keyValue(0);
    splitStringToArray(vecTemp, vecStr.get(i), delimiter2);
    // vecTemp.print();
    strVal1 = vecTemp.get(0);
    strVal2 = vecTemp.get(1);
    ds5("matStr.getSizeRows=");ds5(" ");ds5l(matStr.getNumRows());

    ds5(strVal1);ds5(" ");ds5l(strVal2);

    matStr.push(strVal1, strVal2);
  }
  // Llamamos a la función para dividir el string
}
/*
String concParamsOfString(char charReaded,String param,int &action)
{

  if (charReaded == ':')
  {

    param = "";
    action = 10;
    //charReaded++;
  }else if (action == 10 || action ==11){

    param = param + charReaded;
    dss();dsl("Concatena:");ds("strOption:");dsl(strOption);
    ds("Entre a concatenacion de efectos ");ds(" charReaded: ");dsl(charReaded);
    ds(" strOption: ");dsl(strOption);
    action=11;

  }else if ((charReaded == ')' || charReaded == ':') && action==11){
    dss();dsl("se encuentra )");ds(" charReaded: ");dsl(charReaded);
    action = 19;
  }

  return param;

}*/