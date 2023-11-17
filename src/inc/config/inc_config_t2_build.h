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

//#include "inc_include.h"
#ifndef INC_CONFIG_T2_BUILD
#define INC_CONFIG_T2_BUILD 


static const int PROGMEM C_ANIM_001_T2_BUILD[]={I,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,I,O,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,I,O,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,I,O,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,O,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,O,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,O,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
static const int PROGMEM C_ANIM_002_T2_UPDOWN[]={O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA};
static const int PROGMEM C_ANIM_003_T2_FADE[]={I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
static const int PROGMEM C_ANIM_004_T2_DESINTEGRATE[]={I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,O,I,EA,O,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,I,O,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,I,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
static const int PROGMEM C_ANIM_005_T2_BUILD[]={O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,I,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,O,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,I,I,O,O,EL,O,I,O,O,O,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA};
static const int PROGMEM C_ANIM_006_T2_BUILD[]={I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EA,O,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EA,O,I,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,O,I,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,O,I,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
static const int PROGMEM C_ANIM_007_T2_BUILD[]={I,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,I,O,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,I,O,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,I,O,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,O,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,O,EA,I,O,I,O,I,O,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,O,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,O,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,O,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,O,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
static const int PROGMEM C_ANIM_008_T2_DOWN[]={O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EL,O,O,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA};
static const int PROGMEM C_ANIM_009_T2_FADE_DOWN[]={I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,I,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
static const int PROGMEM C_ANIM_010_T2_DESINTEGRATE[]={I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,O,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,O,I,EA,O,I,I,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,I,O,O,I,I,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,I,O,O,I,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,I,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,I,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};
static const int PROGMEM C_ANIM_011_T2_BUILD[]={O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,I,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,O,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,O,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,O,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,O,O,O,O,O,EL,O,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,O,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,O,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,O,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,O,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,O,O,O,EL,O,I,O,O,O,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,I,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,O,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,I,I,O,O,EL,O,I,O,O,O,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA,I,I,I,O,I,I,O,EL,O,I,O,O,O,O,I,EL,O,I,O,O,O,I,O,EL,O,I,O,O,I,O,O,EL,O,I,O,O,I,I,I,EA};
static const int PROGMEM C_ANIM_012_T2_BUILD_INVERTED[]={I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,I,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EA,O,I,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EA,O,I,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,O,I,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,O,I,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,I,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EL,I,I,I,I,I,I,I,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,I,O,O,I,EL,I,O,I,I,I,I,O,EL,I,O,I,I,I,O,I,EL,I,O,I,I,O,I,I,EL,I,O,I,I,O,O,O,EA,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EL,O,O,O,O,O,O,O,EA};

#endif // INC_CONFIG_T2_BUILD





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