
#include <Arduino.h>
#include "inc/include.h"
void convProgToArray(VectorClass& aIntCharMatrix, const int* phrase, int size) {
  int element = 0;
  for (int i = 0; i < size; i++) {
    // element = ((int)pgm_read_word(phrase + i));
    element = ((int)pgm_read_word(&phrase[i]));
    aIntCharMatrix.push(element);
    // aIntCharMatrix.set(i, element);
    // ds(element);
    // ds("-");
  }
  dsl(" ");
  // aIntCharMatrix.print();
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
/*
String concParamsOfString(char charReaded, String strOption, int& action) {

  if (charReaded == '(') {
    dss();
    ds("se encuentra (");
    ds(" charReaded: ");
    dsl(charReaded);
    strOption = "";
    action = 10;
    // charReaded++;
  }
  else if (action == 10 || action == 11) {

    strOption = strOption + charReaded;
    dss();
    dsl("Concatena:");
    ds("strOption:");
    dsl(strOption);
    ds("Entre a concatenacion de efectos ");
    ds(" charReaded: ");
    dsl(charReaded);
    ds(" strOption: ");
    dsl(strOption);
    action = 11;
  }
  else if ((charReaded == ')' || charReaded == ':') && action == 11) {
    dss();
    dsl("se encuentra )");
    ds(" charReaded: ");
    dsl(charReaded);
    action = 19;
  }

  return strOption;
}*/


//void proccesAction(String InString, String& option, String& effectOption, String& text, int& velocity, int& repeat) {
void proccesAction(String InString, VectorClassString &vecStrOne, int &sizeParams, int contParam) {

  VectorClassString vecStr(0);

  VectorClassString vecStrParam(0);

  String strParam = "";
  String strOneParam = "";
  splitStringToArrayNoEmpty(vecStr, InString, "|");

  sizeParams=vecStr.getSize();

  if (vecStr.getSize() > 0) {
    splitStringToArrayNoEmpty(vecStrParam, vecStr.get(contParam), ";");
    vecStrOne.clear();
    for (int i = 0; i < vecStrParam.getSize(); i++) {
      splitStringToArrayNoEmpty(vecStrOne, vecStrParam.get(i), ":");
    }

  }

}



void updateStateAndEffect(VectorClassString &vecStrOne, String &option, String &effectOption, String &text,int &velocity, int &repeat, int &globalVelocity, String &globalStatus) {
  String value = "";
  String lastStrValue = "";
  static int typeValue = 0;
  //vecStrOne.print();

  if (vecStrOne.get(0) != "iv" && vecStrOne.get(0) != "ip") {
    repeat = DEFAULT_REPEAT;
    velocity = DEFAULT_VELOCITY;
    option = "";
    effectOption = "";
    text = "";
    //dsl("entro aca");
  }
  else {
    //dsl("no entro aca");
  }

  for (int i = 0; i < vecStrOne.getSize(); i++) {
    value = vecStrOne.get(i);
    //dsl("paso por aca 0");

    if (value == "a" || value == "m" || value == "r" || value == "v" || value == "ip" || value == "iv") {
      if (value == "a" || value == "m" || value == "ip" || value == "iv") {
        option = value;
      }
      lastStrValue = value;
      typeValue = 1;
      //dsl("paso por aca 1");

    }
    else if (typeValue == 1) {
      //dsl("paso por aca 2");
      if (lastStrValue == "a") { effectOption = value; }
      if (lastStrValue == "m") { text = value; }
      if (lastStrValue == "v") { velocity = value.toInt(); }
      if (lastStrValue == "r") { repeat = value.toInt(); }
      if (lastStrValue == "ip") { globalStatus = value; }
      if (lastStrValue == "iv") { globalVelocity = value.toInt(); }
      typeValue = 0;
      lastStrValue = value;

    }

  }
  ds5l(" ");
  ds5("option=[");ds5(option);ds5("] ");ds5("effectOption=[");ds5(effectOption);ds5("] ");ds5("text=[");ds5(text);ds5("] ");
  ds5("velocity=[");ds5(velocity);ds5("] ");ds5("repeat=[");ds5(repeat);ds5("] ");
  ds5("globalVelocity=[");ds5(globalVelocity);ds5("] ");ds5("globalStatus=[");ds5(globalStatus);ds5l("] ");
}
void getAndSetParams(   String InString,        int &sizeParams, 
                        int contParam,          String& option,
                        String& effectOption,   String& text, 
                        int& velocity,          int& repeat, 
                        int& globalVelocity,    String& globalStatus){
//void getAndSetParams(String InString,int& sizeParams, int &contParam, String& option,String& effectOption,String& text, int& velocity, int& repeat,int& globalVelocity,    String& globalStatus){

  VectorClassString vecStrOne(0);
  proccesAction(InString, vecStrOne,sizeParams, contParam);
  //vecStrOne.print();

  updateStateAndEffect(vecStrOne, option, effectOption, text, velocity, repeat, globalVelocity, globalStatus);
}


String getBluetoot(SoftwareSerial& BTSerial,char &charBT) {


  static String strRetrun = "";
  static String tempStr = "";
  static bool onePass = false;
  //char charBT = '\0';
  strRetrun = "";
  charBT='\0';
  if (BTSerial.available()) {
    
    charBT = BTSerial.read();
    if (charBT!='$' && charBT!='@'){
      tempStr += charBT;
      //ds("Detect BT in: ");dsl(tempStr);
      //ds(charBT);
      onePass = true;
      strRetrun="-1";
      if (onePass && charBT=='#' ) {
        
        dsd();
        tempStr = tempStr.substring(0, tempStr.length() - 1);
        strRetrun = tempStr;
        ds("Nuevo String: ");dsl(strRetrun);
        onePass = false;
        tempStr = "";
      }
    }
  }
  //  else if (onePass && charBT=='\n' ) {
  //   tempStr = tempStr.substring(0, tempStr.length() - 1);
  //   strRetrun = tempStr;
  //   ds("Nuevo String");dsl(strRetrun);
  //   onePass = false;
  //   tempStr = "";
  // }
  return strRetrun;
}
