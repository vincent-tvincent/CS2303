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
	char** cmdArguments;
	matrix* Matrix;
	int* fixMatrix();
	bool checkInput(int, char**);
	void fillMatrix(char*);
};
#endif 


