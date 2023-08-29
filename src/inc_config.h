

#ifndef _INC_CONFIG_H_
  #define _INC_CONFIG_H_ 
   
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
  #define MATRIX_WIDTH 7
  #define MATRIX_HEIGHT 5
  #define BUILD_MATRIX_WIDTH 21
  #define BUILD_MATRIX_HEIGHT 5

  #ifdef DEBUG
    // #define debug(x)   Serial.print(x)
    // #define debugl(x)   Serial.println(x)        
    
    // #define debuge(x)     do {Serial.print(" "); Serial.print(x); } while(0)
    // #define debugel(x)    do {Serial.print(" "); Serial.println(x); } while(0)
    // #define debug1(x)     do {Serial.print("1)->"); Serial.print(x); } while(0)
    // #define debug1l(x)    do {Serial.print("1)->"); Serial.println(x); } while(0)
    // #define debug2(x)     do {Serial.print("2)---->"); Serial.print(x); } while(0)
    // #define debug2l(x)    do {Serial.print("2)---->"); Serial.println(x); }  while(0)
    // #define debug3(x)     do {Serial.print("3)-------->"); Serial.print(x); } while(0)
    // #define debug3l(x)    do {Serial.print("3)-------->"); Serial.println(x); } while(0)

    #define debug(x)  
    #define debugl(x) 
    #define debuge(x) 
    #define debugel(x)
    #define debug1(x) 
    #define debug1l(x)
    #define debug2(x) 
    #define debug2l(x)
    #define debug3(x) 
    #define debug3l(x)
  #else
    #define debug(x)  
    #define debugl(x) 
    #define debuge(x) 
    #define debugel(x)
    #define debug1(x) 
    #define debug1l(x)
    #define debug2(x) 
    #define debug2l(x)
    #define debug3(x) 
    #define debug3l(x)
  #endif


  
  static const int PROGMEM C_Pins[]={ 2,7,12,17,22,27,32,
                                      3,8,13,18,23,28,33,
                                      4,9,14,19,24,29,34,
                                      5,10,15,20,25,30,35,
                                      6,11,16,21,26,31,36};

  static const int PROGMEM C_EMPTY[]={O,O,O,O,O,O,O,
                                      O,O,O,O,O,O,O,
                                      O,O,O,O,O,O,O,
                                      O,O,O,O,O,O,O,
                                      O,O,O,O,O,O,O};       

  static const int PROGMEM C_T2[]={ I,I,I,O,I,I,I,
                                    O,I,O,O,O,O,I,
                                    O,I,O,O,I,I,I,
                                    O,I,O,O,I,O,O,
                                    O,I,O,O,I,I,I};                                


  static const int PROGMEM C_MARCO[]={I,I,I,I,I,I,I,
                                      I,O,O,O,O,O,I,
                                      I,O,O,O,O,O,I,
                                      I,O,O,O,O,O,I,
                                      I,I,I,I,I,I,I};     


                            
#endif /* _INC_CONFIG_H_ */
