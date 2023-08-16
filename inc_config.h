#include "inc_include.h"

#ifndef INC_CONFIG_H
#define INC_CONFIG_H 
   
#define C_PIN_ENABLED  1
#define C_PIN_DISABLED 0
#define C_END_ARR      9  
#define C_END_LIN      8
      
#define O               C_PIN_DISABLED
#define I               C_PIN_ENABLED
#define EA              C_END_ARR
#define EL              C_END_LIN
#define DEBUG           false
#define DEBUG_MATRIX    false
#define IS_BIGSCREEN    false


  
  static const int PROGMEM C_Pins[]={ 2,7,12,17,22,27,32,
                                      3,8,13,18,23,28,33,
                                      4,9,14,19,24,29,34,
                                      5,10,15,20,25,30,35,
                                      6,11,16,21,26,31,36,EA};

  static const int PROGMEM C_EMPTY[]={  O,O,O,O,O,O,O,
                                        O,O,O,O,O,O,O,
                                        O,O,O,O,O,O,O,
                                        O,O,O,O,O,O,O,
                                        O,O,O,O,O,O,O,EA};       

  static const int PROGMEM C_T2[]={ I,I,I,O,I,I,I,
                                    O,I,O,O,O,O,I,
                                    O,I,O,O,I,I,I,
                                    O,I,O,O,I,O,O,
                                    O,I,O,O,I,I,I,EA};                                


  static const int PROGMEM C_MARCO[]={  I,I,I,I,I,I,I,
                                        I,O,O,O,O,O,I,
                                        I,O,O,O,O,O,I,
                                        I,O,O,O,O,O,I,
                                        I,I,I,I,I,I,I,EA};     


  static const int PROGMEM C_L1[]={ O,O,O,O,O,O,O,
                                    O,O,O,O,O,I,O,
                                    O,O,O,O,O,I,O,
                                    O,O,O,O,O,I,I,
                                    O,O,O,O,O,I,I,EA};                                


  static const int PROGMEM C_L2[]={ O,I,O,O,O,O,O,
                                    O,I,I,I,I,O,O,
                                    O,I,O,O,O,O,O,
                                    O,I,O,O,O,O,O,
                                    O,I,O,O,O,O,O,EA};                                
#endif /* INC_CONFIG_H */
