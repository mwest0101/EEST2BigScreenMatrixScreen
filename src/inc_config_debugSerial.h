﻿
#ifndef _INC_DEBUG_SERIAL_H_
  #define _INC_DEBUG_SERIAL_H_ 

/*
  #define DEBUG_SERIAL_SEPARATOR true
  #define DEBUG_SERIAL_FUN_NAME true
  //#define DEBUG_SERIAL_L0 true
  #define DEBUG_SERIAL_L1 true
  //#define DEBUG_SERIAL_L2 true
  // #define DEBUG_SERIAL_L3 true
  //#define DEBUG_SERIAL_INF true
  #define DEBUG_SERIAL_ERR true
  */
  // 
// #ifdef DEBUG_SERIAL
    #ifdef DEBUG_SERIAL_SEPARATOR
      #define dss(x) Serial.println("----------------------------------------------------------------");        
      #define dsd(x) Serial.println("================================================================");
      #define dst(x)  do {Serial.println("_______________________________________________________________");Serial.println("================================================================");} while(0);
      
    #endif
    #ifdef DEBUG_SERIAL_FUN_NAME      
      #define dsf(x)  do {Serial.println("===============================================================");Serial.println(x);Serial.println("---------------------------------------------------------------");} while(0);
    #endif
    #ifdef DEBUG_SERIAL_L0
      #define ds(x)     Serial.print(x);
      #define dsl(x)    Serial.println(x)    
    #endif
    #ifdef DEBUG_SERIAL_L1
      #define ds1(x)     Serial.print(x);
      #define ds1l(x)    Serial.println(x)    
    #endif
    #ifdef DEBUG_SERIAL_L2
      #define ds2(x)     Serial.print(x);
      #define ds2l(x)    Serial.println(x)    
    #endif
    #ifdef DEBUG_SERIAL_L3
      #define ds3(x)     Serial.print(x);
      #define ds3l(x)    Serial.println(x)    
    #endif
    #ifdef DEBUG_SERIAL_INF
      #define dsi(x)     Serial.print(x);
      #define dsil(x)    Serial.println(x)   
      #define dsis(x)  do {Serial.println("_______________________________________________________________");Serial.println("================================================================");Serial.println(x);} while(0); 
    #endif
    #ifdef DEBUG_SERIAL_ERR
      #define dse(x)     Serial.print(x);
      #define dsel(x)    Serial.println(x)    
      #define dses(x)  do { Serial.println("_______________________________________________________________");Serial.println("==ERROR:=======================================================");Serial.println(x);} while(0); 
    #endif
  // #else
     #ifndef DEBUG_SERIAL_SEPARATOR
        #define dss(x)
        #define dsd(x)
        #define dst(x)
      #endif
      #ifndef DEBUG_SERIAL_FUN_NAME      
        #define dsf(x)
      #endif
    #ifndef DEBUG_SERIAL_L0
        #define ds(x);
        #define dsl(x);
      #endif
      #ifndef DEBUG_SERIAL_L1
        #define ds1(x);
        #define ds1l(x);
      #endif
      #ifndef DEBUG_SERIAL_L2
        #define ds2(x)
        #define ds2l(x)
      #endif
      #ifndef DEBUG_SERIAL_L3
        #define ds3(x)
        #define ds3l(x)
      #endif  
      #ifndef DEBUG_SERIAL_INF
        #define dsi(x)
        #define dsil(x)
        #define dsis(x)
      #endif
      #ifndef DEBUG_SERIAL_ERR
        #define dse(x)
        #define dsel(x)
        #define dses(x) 
      #endif
  //#endif

  #endif /* _INC_DEBUG_SERIAL_H_ */