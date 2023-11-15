
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
/*
void setConsToArray(VectorClass &aFrame){

}*/
int AnimManager::getAnim(VectorClass &aFrame,String strOption)
{
  int               found=-1;
  //if(strOption != lastStrOption)
  
   


  if (strOption == "ark1"){dsl("->ark1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_004_ARKANOID,           (sizeof(C_ANIM_004_ARKANOID) / 2));             found=1;}
  if (strOption == "pon1"){dsl("->pon1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_005_PONG,               (sizeof(C_ANIM_005_PONG) / 2));                 found=1;}
  if (strOption == "sna1"){dsl("->sna1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_006_SNAKE,              (sizeof(C_ANIM_006_SNAKE) / 2));                found=1;}
  if (strOption == "tet1"){dsl("->tet1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_001_TETRIS,             (sizeof(C_ANIM_001_TETRIS) / 2));               found=1;}
  if (strOption == "tet2"){dsl("->tet2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_002_TETRIS,             (sizeof(C_ANIM_002_TETRIS) / 2));               found=1;}
  if (strOption == "tet3"){dsl("->tet3");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_003_TETRIS,             (sizeof(C_ANIM_003_TETRIS) / 2));               found=1;}
  if (strOption == "pac1"){dsl("->pac1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_001_PACMAN,             (sizeof(C_ANIM_001_PACMAN) / 2));               found=1;}
  if (strOption == "pac2"){dsl("->pac2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_002_PACMAN,             (sizeof(C_ANIM_002_PACMAN) / 2));               found=1;}
  if (strOption == "pac3"){dsl("->pac3");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_003_PACMAN_PHANTOM,     (sizeof(C_ANIM_003_PACMAN_PHANTOM) / 2));       found=1;}

  if (strOption == "efe1"){dsl("->efe1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_001_EFFECT_EXPLODE_RECT,(sizeof(C_ANIM_001_EFFECT_EXPLODE_RECT) / 2));  found=1;}
  if (strOption == "efe2"){dsl("->efe2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_002_EFFECT_CRUX_ROTATE, (sizeof(C_ANIM_002_EFFECT_CRUX_ROTATE) / 2));   found=1;}
  if (strOption == "efe3"){dsl("->efe3");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_003_EFFECT_RECT_ZOOM,   (sizeof(C_ANIM_003_EFFECT_RECT_ZOOM) / 2));     found=1;}
  if (strOption == "efe4"){dsl("->efe4");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_010_EFFECT_BALL_BOUNCE, (sizeof(C_ANIM_010_EFFECT_BALL_BOUNCE) / 2));   found=1;}
  if (strOption == "efe5"){dsl("->efe5");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_012_EFFECT_RAIN,        (sizeof(C_ANIM_012_EFFECT_RAIN) / 2));          found=1;}

  if (strOption == "t2n1" ){dsl("->t2b1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_001_T2_BUILD,           (sizeof(C_ANIM_001_T2_BUILD) / 2));           found=1;}
  if (strOption == "t2n2" ){dsl("->t2u1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_002_T2_UPDOWN,          (sizeof(C_ANIM_002_T2_UPDOWN) / 2));          found=1;}
  if (strOption == "t2n3" ){dsl("->t2f1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_003_T2_FADE,            (sizeof(C_ANIM_003_T2_FADE) / 2));            found=1;}
  if (strOption == "t2n4" ){dsl("->t2d1");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_004_T2_DESINTEGRATE,    (sizeof(C_ANIM_004_T2_DESINTEGRATE) / 2));    found=1;}
  if (strOption == "t2n5" ){dsl("->t2b2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_005_T2_BUILD,           (sizeof(C_ANIM_005_T2_BUILD) / 2));           found=1;}
  if (strOption == "t2n6" ){dsl("->t2b3");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_006_T2_BUILD,           (sizeof(C_ANIM_006_T2_BUILD) / 2));           found=1;}
  if (strOption == "t2n7" ){dsl("->t2b4");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_007_T2_BUILD,           (sizeof(C_ANIM_007_T2_BUILD) / 2));           found=1;}
  if (strOption == "t2n8" ){dsl("->t2d2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_008_T2_DOWN,            (sizeof(C_ANIM_008_T2_DOWN) / 2));            found=1;}
  if (strOption == "t2n9" ){dsl("->t2f2");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_009_T2_FADE_DOWN,       (sizeof(C_ANIM_009_T2_FADE_DOWN) / 2));       found=1;}
  if (strOption == "t2n10"){ dsl("->t2d3");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_010_T2_DESINTEGRATE,    (sizeof(C_ANIM_010_T2_DESINTEGRATE) / 2));    found=1;}
  if (strOption == "t2n11"){ dsl("->t2b5");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_011_T2_BUILD,           (sizeof(C_ANIM_011_T2_BUILD) / 2));           found=1;}
  if (strOption == "t2n12"){ dsl("->t2b6");aFrame.clear();this->convProgToArrayByFrame(aFrame, C_ANIM_012_T2_BUILD_INVERTED,  (sizeof(C_ANIM_012_T2_BUILD_INVERTED) / 2));  found=1;}

  
  
  return              found;

  
}