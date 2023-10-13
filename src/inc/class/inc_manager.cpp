
#include <Arduino.h>
#include "inc/include.h"


Manager::Manager(){
 
  //vecStr VectorClassString(0);
  Serial.println("test");
  //vecStrOne= VectorClassString(0);
}


void Manager::getAction(String InString){
  
  //VectorClassString vecStrParam(0);
  ds("stateAction1=");dsl(stateAction);
  
  if (stateAction==0){
    ds("stateAction2=");dsl(stateAction);
    splitStringToArrayNoEmpty(vecStr, InString, "|");
    ds("stateAction2a=");dsl(stateAction);
    stateAction++;
  }
  
  //vecStrParam.clear();
  ds("stateAction3=");dsl(stateAction);
  if (stateAction<=1){
    ds("stateAction4=");dsl(stateAction);
    splitStringToArrayNoEmpty(vecStrParam, vecStr.get(contParam), ";");
    //vecStrParam.print();
  }

  contParam++;

  if(contParam==vecStr.getSize()) contParam=0;
  //ds5("contParam=");ds5l(contParam);
  //vecStrParam.print();
}
/*
void Manager::proccesAction(VectorClassString &vecStrParam,VectorClassString &vecStrOne){
  //VectorClassString vecStrOne(0);
  //vecStrParam.clear();
  vecStrOne.clear();
  for(int i=0;i<vecStrParam.getSize();i++){
    splitStringToArrayNoEmpty(vecStrOne, vecStrParam.get(i), ":");
    
  }
  //vecStrOne.print();
}
*/
/*
void Manager::setProccesAndParameters(VectorClassString &vecStrOne){
vecStrOne.print();
int action=0;

for(int i=0;i<vecStrOne.getSize();i++){
  if(vecStrOne.get(i)=="a"){
    action=2; //Is animation
  }else if(vecStrOne.get(i)=="x"){
    action=4; //Repite animation
  }else if(vecStrOne.get(i)=="v"){
    action=6; //Velocity animation
  }else if(action==2){
    an.getAnim(aFrame, vecStrOne.get(i));
  }
}*/

