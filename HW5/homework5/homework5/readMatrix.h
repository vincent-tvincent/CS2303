#pragma once
#ifndef RM
#define RM
#include <cstdio>
#include <string.h>
#include "matrix.h"
#define FILENAMELENGTHALLOWANCE (100)
class readMatrix
{
public:
	readMatrix(char**);
	void printMatrix();
private:
	char* outputName;
	char** cmdArguments;
	matrix* Matrix;
	void fixMatrix(int);
	bool checkInput(char**);
	void fillMatrix(char*);
};
#endif 


