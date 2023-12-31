﻿

// ╔══════════════════════════════════════════════════════════════════╗
// ║   ____    _             __  __           _            _          ║
// ║  |  _ \  (_)           |  \/  |         | |          (_)         ║
// ║  | |_) |  _    __ _    | \  / |   __ _  | |_   _ __   _  __  __  ║
// ║  |  _ <  | |  / _` |   | |\/| |  / _` | | __| | '__| | | \ \/ /  ║
// ║  | |_) | | | | (_| |   | |  | | | (_| | | |_  | |    | |  >  <   ║
// ║  |____/  |_|  \__, |   |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\  ║
// ║                __/ |                                             ║
// ║               |___/                                              ║
// ║                                                                  ║
// ║  _         _____   _____      _____                           _  ║
// ║ | |       / ____| |  __ \    |  __ \                         | | ║
// ║ | |      | |      | |  | |   | |__) |   __ _   _ __     ___  | | ║
// ║ | |      | |      | |  | |   |  ___/   / _` | | '_ \   / _ \ | | ║
// ║ | |____  | |____  | |__| |   | |      | (_| | | | | | |  __/ | | ║
// ║ |______|  \_____| |_____/    |_|       \__,_| |_| |_|  \___| |_| ║
// ║                                                                  ║
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝

#ifndef _INC_DEBUG_SERIAL_H_
  #define _INC_DEBUG_SERIAL_H_ 

#ifdef DEBUG_SERIAL
  #define DEBUG_SERIAL_SEPARATOR true
  #define DEBUG_SERIAL_FUN_NAME true
  #define DEBUG_SERIAL_L0 true
  #define DEBUG_SERIAL_L1 true
  #define DEBUG_SERIAL_L2 true
  #define DEBUG_SERIAL_L3 true
  #define DEBUG_SERIAL_L4 true
  #define DEBUG_SERIAL_L5 true
  #define DEBUG_SERIAL_INF true
  #define DEBUG_SERIAL_ERR true
#endif
  
  // 
 //#ifdef DEBUG_SERIAL
    #ifdef DEBUG_SERIAL_SEPARATOR
      #define dss() Serial.println("----------------------------------------------------------------");
      #define dsd() Serial.println("================================================================");
      #define dst(x)  do {Serial.println("_______________________________________________________________");Serial.println("================================================================");} while(0);
      
    #endif
    #ifdef DEBUG_SERIAL_FUN_NAME      
      #define dsf(x)  do {Serial.println("===============================================================");Serial.println(x);Serial.println("---------------------------------------------------------------");} while(0);
    #endif
    #ifdef DEBUG_SERIAL_L0
      #define ds(x)     do {Serial.print(x);}while(0);
      #define dsl(x)    do {Serial.println(x);}while(0);
    #endif
    
    #ifdef DEBUG_SERIAL_L1
      #define ds1(x)     do {Serial.print(x);}while(0);
      #define ds1l(x)    do {Serial.println(x);}while(0);
    #endif
    #ifdef DEBUG_SERIAL_L2
      #define ds2(x)     do {Serial.print(x);}while(0);
      #define ds2l(x)    do {Serial.println(x);}while(0);
    #endif
    #ifdef DEBUG_SERIAL_L3
      #define ds3(x)     do {Serial.print(x);}while(0);
      #define ds3l(x)    do {Serial.println(x);}while(0);
    #endif
    #ifdef DEBUG_SERIAL_L4
      #define ds4(x)     do {Serial.print(x);}while(0);
      #define ds4l(x)    do {Serial.println(x);}while(0);
    #endif
    #ifdef DEBUG_SERIAL_L5
      #define ds5(x)     do {Serial.print(x);}while(0);
      #define ds5l(x)    do {Serial.println(x);}while(0);
    #endif
    #ifdef DEBUG_SERIAL_INF
      #define dsi(x)     Serial.print(x);
      #define dsil(x)    Serial.println(x);
      #define dsis(x)  do {Serial.println("_______________________________________________________________");Serial.println("================================================================");Serial.println(x);} while(0);
    #endif
    #ifdef DEBUG_SERIAL_ERR
      #define dse(x)     Serial.print(x);
      #define dsel(x)    Serial.println(x);
      #define dses(x)  do { Serial.println("_______________________________________________________________");Serial.println("==ERROR:=======================================================");Serial.println(x);} while(0);
    #endif
  //#else
     #ifndef DEBUG_SERIAL_SEPARATOR
        #define dss(x);
        #define dsd(x);
        #define dst(x);
      #endif
      #ifndef DEBUG_SERIAL_FUN_NAME      
        #define dsf(x);
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
        #define ds2(x);
        #define ds2l(x);
      #endif
      #ifndef DEBUG_SERIAL_L3
        #define ds3(x);
        #define ds3l(x);
      #endif  
      #ifndef DEBUG_SERIAL_L4
        #define ds4(x);
        #define ds4l(x);
      #endif
      #ifndef DEBUG_SERIAL_L5
        #define ds5(x);
        #define ds5l(x);
      #endif
      #ifndef DEBUG_SERIAL_INF
        #define dsi(x);
        #define dsil(x);
        #define dsis(x);
      #endif
      #ifndef DEBUG_SERIAL_ERR
        #define dse(x);
        #define dsel(x);
        #define dses(x) ;
      #endif
  

  #endif /* _INC_DEBUG_SERIAL_H_ */


  
// ╔══════════════════════════════════════════════════════════════════╗
// ║   ____    _             __  __           _            _          ║
// ║  |  _ \  (_)           |  \/  |         | |          (_)         ║
// ║  | |_) |  _    __ _    | \  / |   __ _  | |_   _ __   _  __  __  ║
// ║  |  _ <  | |  / _` |   | |\/| |  / _` | | __| | '__| | | \ \/ /  ║
// ║  | |_) | | | | (_| |   | |  | | | (_| | | |_  | |    | |  >  <   ║
// ║  |____/  |_|  \__, |   |_|  |_|  \__,_|  \__| |_|    |_| /_/\_\  ║
// ║                __/ |                                             ║
// ║               |___/                                              ║
// ║                                                                  ║
// ║  _         _____   _____      _____                           _  ║
// ║ | |       / ____| |  __ \    |  __ \                         | | ║
// ║ | |      | |      | |  | |   | |__) |   __ _   _ __     ___  | | ║
// ║ | |      | |      | |  | |   |  ___/   / _` | | '_ \   / _ \ | | ║
// ║ | |____  | |____  | |__| |   | |      | (_| | | | | | |  __/ | | ║
// ║ |______|  \_____| |_____/    |_|       \__,_| |_| |_|  \___| |_| ║
// ║                                                                  ║
// ║  Software:                                                       ║
// ║      Desarrollo de Aplicaciones.                                 ║  
// ║      App para mobiles y sistema arduino desarrollado por:        ║
// ║      WTDev ( Prof: Mauricio West)                                ║
// ║      Email: mauriciowest@gmail.com                               ║
// ║      https://wtdevelopments.github.io/                           ║
// ║      https://github.com/mwest0101/EEST2BigScreenMatrixScreen     ║
// ║                                                                  ║
// ║  Hardware:                                                       ║
// ║      Desarrollado por:                                           ║
// ║          Escuela Tecnica 2 de Junin (Bs. As) Argentina           ║            
// ║          Alumnos de 7º Año de la tecnicatura informatica y       ║
// ║          programación .                                          ║
// ║          https://www.facebook.com/tecnica2junin                  ║
// ║                                                                  ║
// ║  Año:    2023                                                    ║
// ║                                                                  ║
// ╚══════════════════════════════════════════════════════════════════╝