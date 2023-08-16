#include "inc_include.h"

#ifndef _INC_CONFIG_LETTERS_CPP_
#define _INC_CONFIG_LETTERS_CPP_

int *getCharMatrix(char character){
  static int * aChar;
  if(character=='A'){aChar=convProgToArray(C_LET_A,(sizeof(C_LET_A)/2));}
  return aChar;
}

#endif /* _INC_CONFIG_LETTERS_CPP_ */
