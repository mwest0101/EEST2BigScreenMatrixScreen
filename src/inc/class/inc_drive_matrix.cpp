
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
DriveMatrix::DriveMatrix() {
  this->totPosX = MATRIX_WIDTH;
  // Serial.println("");
}
//____________________________________________________________________
//------------Function------------------------------------------------
int** DriveMatrix::InitDriveMatrix(int** matrix, int cols, int rows) {

  matrixCols = cols;
  matrixRows = rows;
  matrix = CreateMatrix(matrix, matrixCols, matrixRows);
  return matrix;
}

void DriveMatrix::Print(int** matrix) {

  dsl("__________________________________");
  dsl("----------Print Matrix------------");
  for (int i = 0; i < matrixRows; i++) {

    for (int j = 0; j < matrixCols; j++) {
      ds(matrix[i][j]);ds(" ");
    }
    dsl("");
  }
  dsl(" ");
  // digitalWrite(pin, HIGH);
}
//____________________________________________________________________
//------------Function------------------------------------------------
int** DriveMatrix::Clear(int** matrix) {

  for (int i = 0; i < matrixRows; i++) {

    for (int j = 0; j < matrixCols; j++) {
      matrix[i][j] = O;
    }
  }
  ResetInitPosMatrix();
  return matrix;
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::ResetInitPosMatrix() {

  this->totPosX = MATRIX_WIDTH;
  this->posInfMat = 0;
  this->codSumTot = 0;
  this->vCanAddChar = true;
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::AddConsToMatrix(MatrixClass& matrix, VectorClass& aIntCharMatrix, int caracter) {

  dss();
  dsl("AddConsToMatrix");
  // ResetInitPosMatrix(); //sacar esto una vez probado que funciona

  int value = 0;
  int relPosRow = 0;
  int relPosCols = 0;
  int maxPosCol = 0;
  int cont = aIntCharMatrix.getSize();
  this->infMat[posInfMat] = caracter;
  for (int i = 0; i < cont; i++) {

    value = aIntCharMatrix.get(i);
    if (value != EL && value != EA) {

      matrix.set(relPosRow, (this->totPosX + relPosCols), value);
      ds(value);
      ds("|");
      //dse(")");
      if (relPosCols > maxPosCol) maxPosCol = relPosCols;

      if (value < 0 || value > 1) {

        dses(value);
      }

      relPosCols++;
    }
    else {
      ds("||");

      dsl(value);

      relPosRow++;
      relPosCols = 0;
    }
  }
  ds("this->totPosX:");
  ds(this->totPosX);
  dsl(" ");

  this->posInfMat = this->posInfMat + (maxPosCol + 1);
  this->totPosX = this->totPosX + (maxPosCol + 1);
  maxPosCol = 0;
  dsl(" ");
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::despIzq() {

  if (despMat < BUILD_MATRIX_COLS) {

    despMat++;
  }
  else {

    despMat = 0;
  }
}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::GetFrame(MatrixClass& matrix, VectorClass& aFrame) {

  //

  //dsis("Inicio GetFrame");
  //int size = MATRIX_WIDTH * MATRIX_HEIGHT;
  //int *frame = (int *)calloc((size + 1), sizeof(int));
  int contPos = 0;
  for (int i = 0; i < MATRIX_HEIGHT; i++) {

    for (int j = 0; j < MATRIX_WIDTH; j++) {
      aFrame.set(contPos, matrix.get(i, j));
      contPos++;
    }
    // dsl(" ");
  }
  //ds1("Fin GetFrame");

}
//____________________________________________________________________
//------------Function------------------------------------------------
void DriveMatrix::moveMatrixToLeft(MatrixClass& matrix) {

  for (int i = 0; i < BUILD_MATRIX_ROWS; i++) {

    for (int j = 0; j < ((BUILD_MATRIX_COLS)-1); j++) {
      matrix.set(i, j, matrix.get(i, (j + 1)));
    }
    //movMat++;
  }
  this->totPosX--;
  if (this->totPosX < MATRIX_WIDTH) {
    setCanAddChar(true);
    //this->vCanAddChar = true;
  }
  /*
  if (this->totPosX <(MATRIX_WIDTH-(MATRIX_WIDTH/2))) {
    setIfIsStringEnd(true);
    //this->IsStringEnd = true;
  }*/
  
}

int DriveMatrix::getPosLastChar() {
  return this->totPosX;
}

bool DriveMatrix::getIfIsStringEnd() {

  return IsStringEnd;


}
void DriveMatrix::setIfIsStringEnd(bool status) {  
 this->IsStringEnd=status;
 ds("setIfIsStringEnd=");dsl(IsStringEnd);
}

void DriveMatrix::setCanAddChar(bool value) {
  
  this->vCanAddChar = value;
  ds("setCanAddChar=");dsl(vCanAddChar);
}
bool DriveMatrix::canAddChar() {
  return this->vCanAddChar;
}
bool DriveMatrix::isAtTheEnd() {
  return this->vIsInTheEnd;
}
//____________________________________________________________________
//------------Function------------------------------------------------
int DriveMatrix::getMovMat() {

  return movMat;
}
void DriveMatrix::getArrayOfCharsOfString(VectorClass& vecTemp, String strData) {

  //VectorClass vecTemp(0, VECTOR_MIN_VALUE, VECTOR_MAX_VALUE);
  int numOfcharacter = 0;
  this->contChars = 0;
  for (unsigned int i = 0; i < strData.length(); i++) {

    numOfcharacter = calcNumberOfChar(strData[i]);
    if (numOfcharacter != 0) {
      vecTemp.push(numOfcharacter);
      this->codSumTot = this->codSumTot + ((i * 10) + numOfcharacter);
      this->contChars++;
      //ds1("numOfcharacter:");
      //ds1l(numOfcharacter);
    }
  }


}
unsigned long DriveMatrix::getCodSumTo() {

  return this->codSumTot;
}
//____________________________________________________________________
//------------Function------------------------------------------------
int DriveMatrix::getContChars() {

  return contChars;
}
void DriveMatrix::fillArrrayOfChars(VectorClass& vecChar, String strToShow) {
  //static String lastStrToShow="";
  String tempStr = "";
  //if (this->lastStrToShow != strToShow) {
  dsil("Cambio el string");
  tempStr = strToShow + MARQUE_SEPARATOR;
  this->ResetInitPosMatrix();
  vecChar.clear();
  this->getArrayOfCharsOfString(vecChar, tempStr);
  //vecChar.print();
  //this->lastStrToShow = strToShow;
//}

}
// void DriveMatrix::getValuesOfCharMatrixAndAddToMatrix(MatrixClass& matrix, VectorClass& aIntCharMatrix, VectorClass& vecChar, int contCharAdded) {
//   aIntCharMatrix.clear();
//   getCharMatrix(aIntCharMatrix, vecChar.get(contCharAdded));
//   // ds("aIntCharMatrix.getSize=");
//   // dsl(aIntCharMatrix.getSize());
//   this->AddConsToMatrix(matrix, aIntCharMatrix, vecChar.get(contCharAdded));

// }


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