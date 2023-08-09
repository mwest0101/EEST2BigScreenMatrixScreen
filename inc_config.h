#include "inc_include.h"

#ifndef INC_CONFIG_H
#define INC_CONFIG_H
   //int panel[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37};
   
   #define C_PIN_ENABLED  1
   #define C_PIN_DISABLED 0
   #define C_END_ARR      9   
   #define O              C_PIN_DISABLED
   #define I              C_PIN_ENABLED
   #define EA             C_END_ARR

/*
    static const int PROGMEM CPanel[]={ 
      2,7,12,17,22,27,32,
      3,8,13,18,23,28,33,
      4,9,14,19,24,29,34,
      5,10,15,20,25,30,35,
      6,11,16,21,26,31,36,EA}
*/

                              
static const int PROGMEM t3[]={ I,I,I,O,I,I,I,
                                O,I,O,O,O,O,I,
                                O,I,O,O,I,I,I,
                                O,I,O,O,I,O,O,
                                O,I,O,O,I,I,I,EA};

#endif /* INC_CONFIG_H */
