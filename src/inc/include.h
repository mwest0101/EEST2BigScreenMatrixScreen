

#ifndef _INC_INCLUDES_H_
  #define _INC_INCLUDES_H_
  #include <Arduino.h>  
  #include <SoftwareSerial.h>

  #include "config/inc_config.h"
  #include "config/inc_config_debugSerial.h"
  #include "config/inc_config_tetris.h"  
  #include "config/inc_config_pacman.h"
  #include "config/inc_config_t2_build.h"
  #include "config/inc_config_effects.h"

  #include <stdlib.h>
  #include <stdio.h>
  #include <avr/pgmspace.h>
  #ifdef IS_LCDSCREEN
    #include <MatrizLed.h>
  #endif
  
  //#include <LibPrintf.h>
  #if DEBUG
    #include "avr8-stub.h"
    #include "app_api.h"
  #endif
 
  
  
  #include "inc/utils/VectorClass.cpp"
  #include "inc/utils/VectorClassString.cpp"
  #include "inc/utils/MatrixClass.cpp"
  #include "inc/utils/MatrixClassString.cpp"

  #include "inc_functions.h"   
  #include "inc/utils/str_functions.h"   
    
  #include "inc/class/inc_show_matrix.h"
  #include "inc/class/inc_drive_matrix.h"
  #include "inc/config/inc_config_letters.h"
  #include "inc/class/inc_animManager.h"   
  

  //#include "inc_show_matrix.h"
  //#include "inc_drive_matrix.h"
#endif /* _INC_INCLUDES_H_ */
