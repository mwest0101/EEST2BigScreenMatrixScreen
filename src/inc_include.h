

#ifndef _INC_INCLUDES_H_
  #define _INC_INCLUDES_H_
  #include <Arduino.h>  
  #include "inc_config.h"
  #include "inc_config_debugSerial.h"
  #include "inc_config_tetris.h"  
  #include "inc_config_pacman.h"
  #include "inc_config_t2_build.h"
  #include "inc_config_effects.h"

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
 
  
  
  #include "VectorClass.cpp"
  #include "MatrixClass.cpp"

  #include "inc_functions.h"   
  

  #include "inc_progmem_manager.h"   
  #include "inc_show_matrix.h"
  #include "inc_drive_matrix.h"
  #include "inc_config_letters.h"
  #include "inc_animManager.h"   
  #include "BigWallMatrix.h"
  //#include "inc_show_matrix.h"
  //#include "inc_drive_matrix.h"
#endif /* _INC_INCLUDES_H_ */
