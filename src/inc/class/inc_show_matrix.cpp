
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

#include <Arduino.h>
#include "inc/include.h"
ShowMatrix::ShowMatrix() {

  dsl("");
}
#ifdef IS_LCDSCREEN
void ShowMatrix::setPantalla(MatrizLed& vPantalla) {
  this->pantalla = vPantalla;
}
#endif
void ShowMatrix::InitShowMatrix(VectorClass& vecPins) {

  // aPins=vaPins;
  // nElements=nFrameElements;
  // VectorClass tempVectorLastFrame(35, 0, 10);
  dsl("Inicializacion de pines");
  for (int i = 0; i < vecPins.getSize(); i++) {

    pinMode(vecPins.get(i), OUTPUT);
    //digitalWrite(vecPins.get(i), O);
     ds(" vp=");
     ds(vecPins.get(i));
     
  }
  dsl("");
  // dsl("");
  // tempVectorLastFrame = convProgToArray(C_EMPTY, 0, (sizeof(C_EMPTY) / 2));
}
//____________________________________________________________________
//------------Function------------------------------------------------
void ShowMatrix::PrintData(int data) {

  ds(data);
  ds("text");
}
//____________________________________________________________________
//------------Function------------------------------------------------
void ShowMatrix::PrintLed(int ledNum, int pintToActive, int ledState) {



#ifdef IS_BIGSCREEN
  dsd();
  digitalWrite(pintToActive, ledState);
  ds("ShowMatrix::PrintLed:");
  ds(" pintToActive:");
  ds(pintToActive);ds(" ");
  ds(" ledState:");
  dsl(ledState);
  dss();

#endif

#ifdef IS_LCDSCREEN
  int posX = 0;
  int posY = 0;
  posX = (int)(ledNum / 7);
  posY = (int)(ledNum % 7);
  /*
   ds3l("IS_LCDSCREEN");
   ds3("posX:");
   ds3(posX);
   ds3("| posY:");
   ds3(posY);
   ds3("| ledState:");
   ds3l(ledState);*/



  this->pantalla.setLed(0, posX, posY, ledState);

#endif
}
//------------Function------------------------------------------------
void ShowMatrix::flipHorizontalFrame(VectorClass& aFrame) {
  VectorClass aFrameTemp(36, O,VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  int posCalc = 6;
  int contLine = 1;

  for (int i = 0; i < 35; i++) {
    contLine = (int)((i / 7) + 1);
    posCalc = (contLine * 7) - (i % 7) - 1;

    aFrameTemp.set(i, aFrame.get(posCalc));

  }
  for (int i = 0; i < 35; i++) {
    aFrame.set(i, aFrameTemp.get(i));

  }

}
//------------Function------------------------------------------------
void ShowMatrix::flipVerticalFrame(VectorClass& aFrame) {
  VectorClass aFrameTemp(36, O,VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  int posCalc = 0;
  int contLine = 1;

  for (int i = 0; i < 35; i++) {
    contLine=4-(int)(i/7);      
    posCalc = (contLine*7)+(i%7);
    aFrameTemp.set(i, aFrame.get(posCalc));
  }
  for (int i = 0; i < 35; i++) {
    aFrame.set(i, aFrameTemp.get(i));
  }

}

//____________________________________________________________________
//------------Function------------------------------------------------
void ShowMatrix::PrintLedMatrix(VectorClass& aFrame, VectorClass& aLastFrame, VectorClass& vecPins) {

  int pinState = 0;
  int pinNum = 0;
  int posX = 0;
  int lastPosX = 0;

  lastPosX = posX;
  for (int i = 0; i < 35; i++) {

    posX = (int)(i / MATRIX_WIDTH);
    pinState = aFrame.get(i);
    pinNum = vecPins.get(i);
    if (pinState < 2) {
      if (lastPosX != posX) {
        dsl(" ");
        lastPosX = posX;
      }
      //dsl("===>es igual");
      if (aFrame.get(i) != aLastFrame.get(i)) {
        //        dsl("===>es distinto");
        aLastFrame.set(i, aFrame.get(i)); // update the values of matriz temp to only update the changed values
        ShowMatrix::PrintLed(i, pinNum, pinState);
      }
    }
  }
}

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