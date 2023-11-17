
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

#ifndef _INC_ANIM_MANAGER_H_
  #define _INC_ANIM_MANAGER_H_
  class AnimManager{
    private:
      
      int matrixCols=0;
      int contFrame=0;
      bool isEndOfAnim=true;
  
    public:        
      AnimManager();      
      void convProgToArrayByFrame(VectorClass &aFrame, const int *phrase, int size);
      void setIfisEnd(bool value);
      void reset();
      bool getIfAnimIsEnd();
      int getAnim(VectorClass &aFrame,String strOption);
    
      
  };
#endif /* _INC_ANIM_MANAGER_H_ */



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