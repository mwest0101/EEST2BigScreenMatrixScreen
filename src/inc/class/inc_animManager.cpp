
#include <Arduino.h>
#include "inc/include.h"

AnimManager::AnimManager(){
 
  this->contFrame=0;
  this->isEndOfAnim=true;

  // Serial.println("");
}


void AnimManager::convProgToArrayByFrame(VectorClass &aFrame, const int *phrase, int size)
{

  int element = 0;
  // this->contFrame=0;
  ds("this->contFrame=");
  dsl(this->contFrame);
  while (this->contFrame < size and element != EA)
  {
    element = ((int)pgm_read_word(phrase + this->contFrame));

    if (element == EL || element == EA)
    {
      dsl("");
    }
    else
    {
      ds(element);
      ds(" ");
      aFrame.push(element);
    }

    this->contFrame++;
    
    
  }

  if (this->contFrame >= size) 
    this->setIfisEnd(true);
  dsl(" ");
}
void AnimManager::setIfisEnd(bool value)
{
  this->isEndOfAnim = value;
  this->contFrame = 0;
}

void AnimManager::reset()
{
  ds4("Reset : contFrame=");
  ds4l(this->contFrame);
  //this->setIfisEnd(false);
  this->contFrame = 0;
}
bool AnimManager::getIfAnimIsEnd()
{
  /*if (this->isEndOfAnim)
  {
    dsl("getIfisEnd=True");
  }
  else
  {
    dsl("getIfisEnd=False");
  }*/

  return this->isEndOfAnim;
}
int AnimManager::getAnim(VectorClass &aFrame,String strOption)
{
  int found=-1;
  //if(strOption != lastStrOption)
  if (strOption == "pac1"){dsl("->pac1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_PACMAN_ANIM_01, (sizeof(C_PACMAN_ANIM_01) / 2));found=1;}
  if (strOption == "pac2"){dsl("->pac2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_PACMAN_ANIM_02, (sizeof(C_PACMAN_ANIM_02) / 2));found=1;}

  if (strOption == "tet1"){dsl("->tet1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_TETRIS_ANIM_01, (sizeof(C_TETRIS_ANIM_01) / 2));found=1;}  
  
  if (strOption == "efe1"){dsl("->efe1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_EFECTOS_ANIM_01, (sizeof(C_EFECTOS_ANIM_01) / 2));found=1;}  
  if (strOption == "efe2"){dsl("->efe2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_EFECTOS_ANIM_02, (sizeof(C_EFECTOS_ANIM_02) / 2));found=1;}  
  if (strOption == "efe3"){dsl("->efe3");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_EFECTOS_ANIM_03, (sizeof(C_EFECTOS_ANIM_03) / 2));found=1;}  
  if (strOption == "efe4"){dsl("->efe4");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_EFECTOS_ANIM_04, (sizeof(C_EFECTOS_ANIM_04) / 2));found=1;}  
  if (strOption == "efe5"){dsl("->efe5");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_EFECTOS_ANIM_05, (sizeof(C_EFECTOS_ANIM_05) / 2));found=1;}  
  if (strOption == "efe6"){dsl("->efe6");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_EFECTOS_ANIM_06, (sizeof(C_EFECTOS_ANIM_06) / 2));found=1;}  
  if (strOption == "efe7"){dsl("->efe7");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_EFECTOS_ANIM_07, (sizeof(C_EFECTOS_ANIM_07) / 2));found=1;}  
  
  if (strOption == "tec1"){dsl("->tec1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_T2_BUILD_01, (sizeof(C_T2_BUILD_01) / 2));found=1;}  
  if (strOption == "tec2"){dsl("->tec2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_T2_BUILD_02, (sizeof(C_T2_BUILD_02) / 2));found=1;}  
  if (strOption == "tec3"){dsl("->tec3");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_T2_BUILD_03, (sizeof(C_T2_BUILD_03) / 2));found=1;}  
  if (strOption == "tec4"){dsl("->tec4");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_T2_BUILD_04, (sizeof(C_T2_BUILD_04) / 2));found=1;}  
  if (strOption == "tec5"){dsl("->tec5");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_T2_BUILD_05, (sizeof(C_T2_BUILD_05) / 2));found=1;}  
  if (strOption == "tec6"){dsl("->tec6");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_T2_BUILD_06, (sizeof(C_T2_BUILD_06) / 2));found=1;}  
  return found;

  
}