
#include <Arduino.h>
#include "inc_include.h"

ProgmemManager::ProgmemManager()
{
  this->contFrame = 0;
  this->setIfisEnd(false);
  // Serial.println("");
}

void ProgmemManager::convProgToArray(VectorClass &aIntCharMatrix, const int *phrase, int size)
{
  int element = 0;
  for (int i = 0; i < size; i++)
  {
    element = ((int)pgm_read_word(phrase + i));
    aIntCharMatrix.push(element);
  }
  dsl(" ");
}

void ProgmemManager::convProgToArrayByFrame(VectorClass &aFrame, const int *phrase, int size)
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
void ProgmemManager::setIfisEnd(bool value)
{
  this->isEndOfAnim = value;
}

void ProgmemManager::reset()
{
  ds4("Reset : contFrame=");
  ds4l(this->contFrame);
  this->setIfisEnd(false);
  this->contFrame = 0;
}
bool ProgmemManager::getIfisEnd()
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
