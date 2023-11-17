
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
#ifndef INC_CONFIG_TETRIS_H
#define INC_CONFIG_TETRIS_H 
const PROGMEM int C_TETRIS_ANIM_01[]={O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,I,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,I,I,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,I,I,O,O,EA,O,O,O,I,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,I,I,O,O,EA,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,I,I,O,O,EA,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,I,I,O,O,EA,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,I,I,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,I,I,I,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,I,I,I,O,O,EA,O,I,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,I,I,I,O,O,EA,O,I,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,I,I,I,O,O,EA,O,O,I,O,O,O,O,EL,O,O,I,I,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,I,I,I,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,I,O,O,O,EL,O,O,O,I,I,O,O,EL,O,I,I,O,O,O,O,EL,O,I,I,I,I,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,I,O,O,EL,O,I,I,O,I,I,O,EL,O,I,I,I,I,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,I,O,EL,O,I,I,I,I,I,I,EA,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,I,O,EL,O,I,I,I,I,I,I,EA,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,I,O,EL,O,I,I,I,I,I,I,EA,I,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,O,I,I,O,O,I,O,EL,O,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,O,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EA,O,O,O,I,O,O,O,EL,O,O,O,I,I,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,O,O,O,O,EL,I,I,I,O,O,I,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,O,O,EL,I,I,I,I,I,I,O,EA,O,O,O,I,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,O,O,EL,I,I,I,I,I,I,O,EA,O,O,O,I,I,O,O,EL,O,O,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,O,O,EL,I,I,I,I,I,I,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,I,I,O,EL,O,O,O,O,O,I,O,EL,I,O,O,I,O,O,O,EL,I,I,I,I,I,I,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,I,EL,I,O,O,I,O,O,I,EL,I,I,I,I,I,I,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EA,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EA,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,O,O,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,I,O,O,O,O,EL,I,O,O,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,I,O,O,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,O,I,I,EA,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,I,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,I,O,O,EL,I,I,I,I,O,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,I,I,I,I,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
#endif /* INC_CONFIG_TETRIS_H */



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