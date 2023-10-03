
#include <Arduino.h>
#include "inc_include.h"

AnimManager::AnimManager(){
 
  this->contFrame=0;
  this->isEndOfAnim=false;
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
    if (this->contFrame >= size) this->setIfisEnd(true);
    
  }

  dsl(" ");
}
void AnimManager::setIfisEnd(bool value)
{
  this->isEndOfAnim = value;
}

void AnimManager::reset()
{
  ds4("Reset : contFrame=");
  ds4l(this->contFrame);
  this->setIfisEnd(false);
  this->contFrame = 0;
}
bool AnimManager::getIfisEnd()
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
void AnimManager::getAnim(VectorClass &aFrame,String strOption)
{
  if (strOption == "a:pac1"){dsl("->a:pac1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_PACMAN_ANIM_01, (sizeof(C_PACMAN_ANIM_01) / 2));}
  if (strOption == "a:pac2"){dsl("->a:pac2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_PACMAN_ANIM_02, (sizeof(C_PACMAN_ANIM_02) / 2));}
  if (strOption == "a:tet1"){dsl("->a:tet1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_TETRIS_ANIM_01, (sizeof(C_TETRIS_ANIM_01) / 2));}  
}