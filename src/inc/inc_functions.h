
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
                    
void updateStateAndEffect(VectorClassString& vecStrOne, String& option, String& effectOption, String& text, 
                          int& velocity, int& repeat,int& globalVelocity,String& globalStatus);

void getAndSetParams(   String InString, 
                        int contParam,          String& option,
                        String& effectOption,   String& text, 
                        int& velocity,          int& repeat, 
                        int& globalVelocity,    String& globalStatus);
 

void getAndSetParamsOne(   String InString,     String& option,
                        String& effectOption,   String& text, 
                        int& velocity,          int& repeat, 
                        int& globalVelocity,    String& globalStatus);
void proccesActionOne(String InString, VectorClassString& vecStrOne);
 
String getBluetoot(SoftwareSerial &BTSerial,char &charBT);

//int **createMatrix(int rows,int cols);
//int selectRandom(long[],int);
#endif /* _INC_FUNCTIONS_H_ */