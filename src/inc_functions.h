
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
void splitStringToArray(VectorClassString& dataArray, String inputString, String delimiter);
void stringTokeyAndValue(MatrixClassString& matStr, String inputString, String delimiter1, String delimiter2);
void charReplace(char *str, char findChar, char replaceChar);
void strReplace(String &str, const String &find, const String &replace);

//int **createMatrix(int rows,int cols);
//int selectRandom(long[],int);
#endif /* _INC_FUNCTIONS_H_ */
