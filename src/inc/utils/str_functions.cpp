#include <Arduino.h>
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
    

    strResult=inputString.substring(0, commaIndex);
    strResult.trim();
    

    if(strResult!=""){
      dataArray.push(strResult);
      //ds("strResult=");dsl(strResult);
    }
    

    inputString = inputString.substring(commaIndex + 1);
    commaIndex = inputString.indexOf(delimiter);
  }
  
  
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



