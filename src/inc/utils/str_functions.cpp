﻿#include <Arduino.h>
#include "inc/include.h"

void splitStringToArray(VectorClassString& dataArray, String inputString, String delimiter) {

  int commaIndex = inputString.indexOf(delimiter);

  while (commaIndex != -1) {
    ds("------------->");ds("commaIndex=");dsl(commaIndex);
    dataArray.push(inputString.substring(0, commaIndex));
    inputString = inputString.substring(commaIndex + 1);
    commaIndex = inputString.indexOf(delimiter);
  }
  dataArray.push(inputString);
}

void splitStringToArrayNoEmpty(VectorClassString& dataArray, String inputString, String delimiter) {

  int commaIndex = inputString.indexOf(delimiter);
  String strResult="";
  while (commaIndex != -1) {
    
   // dataArray.push(inputString.substring(0, commaIndex));
    ds5l("splitStringToArrayNoEmpty=1");

    strResult=inputString.substring(0, commaIndex);
    strResult.trim();
    ds5l("splitStringToArrayNoEmpty=2");

    if(strResult!=""){
      dataArray.push(strResult);
      //ds("strResult=");dsl(strResult);
    }
    ds5l("splitStringToArrayNoEmpty=3");

    inputString = inputString.substring(commaIndex + 1);
    commaIndex = inputString.indexOf(delimiter);
  }
  ds5l("splitStringToArrayNoEmpty=4");
  
  inputString.trim();
  dataArray.push(inputString);


}

void charReplace(char *str, char findChar, char replaceChar) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == findChar) {
      str[i] = replaceChar;
    }
  }
}

void strReplace(String &str, const String &find, const String &replace) {
  int index = str.indexOf(find);
  while (index != -1) {
    str.replace(find, replace);
    index = str.indexOf(find);
  }
}



