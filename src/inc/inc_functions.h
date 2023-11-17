
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

#ifndef _INC_FUNCTIONS_H_
#define _INC_FUNCTIONS_H_
void convProgToArray(VectorClass &aIntCharMatrix,const int *phrase, int size);
//Vector<Vector<int>> convProgToMatrix(const int *phrase,size_t size);
//void printMatrix(Vector<Vector<int>> matriz);
void printMatrix(int vMatrix[]);
//int **CreateMatrix(int cols, int rows);
int **CreateMatrix(int **matrix,int cols, int rows);
void strToVector(String strIng,String *aStrsParam,String *aStrsValor);
//String concParamsOfString(char charReaded,String strOption,int &action);
//String getOneGroup(String InString, int& stateAction) ;
//void proccesAction(oneGroup,&effectOption,&text,&velocity,&repeat);
//void proccesAction(String InString,String &option,String &effectOption,String &text,int &velocity,int &repeat);

void proccesAction(String InString, VectorClassString& vecStrOne,  int contParam);
void proccesActionFull(String InString, VectorClassString &vecStr);
                    
void updateStateAndEffect(
                    VectorClassString& vecStrOne,   String& option, 
                    String& effectOption,           String& text, 
                    int& velocity,                  int& repeat,
                    int &invert, 
                    int& globalControl,     int& globalInvert,  
                    int& globalVelocity,    String& globalStatus,
                    String& globalMode);

void getAndSetParams(  String InString, int contParam, String& option,
                        String& effectOption,   String& text, 
                        int& velocity,          int& repeat,    int &invert, 
                        int& globalControl,     int& globalInvert,  
                        int& globalVelocity,    String& globalStatus,
                        String& globalMode);
 

void getAndSetParamsOne(String InString,     String& option,
                        String& effectOption,   String& text, 
                        int& velocity,          int& repeat,   int &invert,
                        int& globalControl,     int& globalInvert,  
                        int& globalVelocity,    String& globalStatus,
                        String& globalMode);

void proccesActionOne(String InString, VectorClassString& vecStrOne);
 
String getBluetoot(SoftwareSerial &BTSerial,char &charBT);
long calcLoopTime(long velocity,long globalVelocity);

void InvertFrame(VectorClass& aFrame,ShowMatrix& sm, int invert,int globalInvert);


//int **createMatrix(int rows,int cols);
//int selectRandom(long[],int);
#endif /* _INC_FUNCTIONS_H_ */





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