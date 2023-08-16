#include "inc_include.h"

#ifndef INC_CONFIG_PACMAN_H
#define INC_CONFIG_PACMAN_H 
   
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



 static const int PROGMEM C_PACMAN_01[]={ O,O,I,I,I,O,O,
                                          O,I,O,I,I,I,O,
                                          O,I,I,I,I,I,O,
                                          O,I,I,I,I,I,O,
                                          O,O,I,I,I,O,O};    

 static const int PROGMEM C_PACMAN_02[]={ O,O,I,I,I,O,O,
                                          O,I,O,I,I,I,O,
                                          O,I,I,O,O,O,O,
                                          O,I,I,I,I,I,O,
                                          O,O,I,I,I,O,O};  

static const int PROGMEM C_PACMAN_03[]={  O,O,I,I,I,O,O,
                                          O,I,O,I,I,I,O,
                                          O,I,I,O,O,O,O,
                                          O,I,I,I,O,O,O,
                                          O,O,I,I,I,O,O};                                              
/*

static const int PROGMEM C_PACMAN_01[]={ O,O,I,I,I,O,O,
                                          O,I,O,I,I,I,O,
                                          O,I,I,I,I,I,O,
                                          O,I,I,I,I,I,O,
                                          O,O,I,I,I,O,O};       

 static const int PROGMEM C_PACMAN_02[]={ O,O,I,I,I,O,O,
                                          O,I,O,I,I,I,O,
                                          O,I,I,O,O,O,O,
                                          O,I,I,I,I,O,O,
                                          O,O,I,I,I,I,O};       
*/
#endif /* INC_CONFIG_PACMAN_H */
