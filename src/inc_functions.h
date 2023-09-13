/*conProgToArray
 * inc_functions.h
 *
 *  Created on: 26 may. 2023
 *      Author: Mauricio West
 */
//#include "inc_include.h"
 
#ifndef _INC_FUNCTIONS_H_
#define _INC_FUNCTIONS_H_
#include "inc_include.h"

VectorClass convProgToArray(const int *phrase, int size);

//Vector<Vector<int>> convProgToMatrix(const int *phrase,size_t size);
//void printMatrix(Vector<Vector<int>> matriz);

void printMatrix(int vMatrix[]);
//int **CreateMatrix(int cols, int rows);
int **CreateMatrix(int **matrix,int cols, int rows);
//int **createMatrix(int rows,int cols);

//int selectRandom(long[],int);
#endif /* _INC_FUNCTIONS_H_ */
