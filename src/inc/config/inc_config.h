
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

//#include "inc_include.h"
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
  
  //#define DEBUG           true
  #define DEBUG_SERIAL true
  //#define DEBUG_MATRIX    true
  //#define DEBUG_BY_VSCODE
  
  #define IS_LCDSCREEN    true
  //#define IS_BIGSCREEN    true
  #define MATRIX_WIDTH 7
  #define MATRIX_HEIGHT 5
  
  #define BUILD_MATRIX_COLS 21
  #define BUILD_MATRIX_ROWS 5
  #define VECTOR_SIZE 40
  #define VECTOR_MAX_VALUE 100
  #define VECTOR_MIN_VALUE 0
  
  #define PIN_BT_RXD 52
  #define PIN_BT_TXD 53
  #define VECTOR_MIN_VALUE 0


  //#define WAIT_TIME_LOOP 1000000;
  //#define WAIT_TIME_LOOP      25000;
  
  //#define WAIT_TIME_LOOP      2000000;
  //#define WAIT_TIME_LOOP      200000;
  #define WAIT_TIME_LOOP_MAX      2000000;
  #define WAIT_TIME_LOOP_MIN      50000;

  
  //#define WAIT_TIME_LOOP      20000;
  //#define WAIT_TIME_LOOP      400;
  //#define WAIT_TIME_LOOP      10;
  //#define WAIT_TIME_LOOP    50000;
  //#define WAIT_TIME_LOOP    500000;
  
  //#define WAIT_TIME_LOOP    40000
  #define TIME_TO_GET_BT    400000
  #define MARQUE_SEPARATOR " ";
  
  #define DEFAULT_VELOCITY 5;
  #define DEFAULT_REPEAT 1;
  
  
  static const int PROGMEM C_Pins[]={2,7,12,17,22,27,32,
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