
#ifndef _INC_FUNCTIONS_H_
#define _INC_FUNCTIONS_H_
void convProgToArray(VectorClass &aIntCharMatrix,const int *phrase, int size);
//Vector<Vector<int>> convProgToMatrix(const int *phrase,size_t size);
//void printMatrix(Vector<Vector<int>> matriz);
void printMatrix(int vMatrix[]);
//int **CreateMatrix(int cols, int rows);
int **CreateMatrix(int **matrix,int cols, int rows);
void strToVector(String strIng,String *aStrsParam,String *aStrsValor);
String concParamsOfString(char charReaded,String strOption,int &action);
//String getOneGroup(String InString, int& stateAction) ;
//void proccesAction(oneGroup,&effectOption,&text,&velocity,&repeat);
void proccesAction(String strOneGroup,String &effectOption,String &text,int &velocity,int &repeat);
void updateStateAndEffect(VectorClassString &vecStrOne, String &effectOption, String &text, int &velocity, int &repeat);


//int **createMatrix(int rows,int cols);
//int selectRandom(long[],int);
#endif /* _INC_FUNCTIONS_H_ */
