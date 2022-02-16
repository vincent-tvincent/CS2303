#pragma once
#ifndef RM
#define RM
#include <cstdio>
#include <string.h>
#include "matrix.h"
class readMatrix
{
public:
	readMatrix(char*,char*	);
	virtual ~readMatrix();
	void printMatrix();
	matrix getMatrix();
private:
	void fillMatrix(char*);
	void fixMatrix();
	char* inputName;
	char* outputName;
	int endLength;
	matrix* Matrix;
};
#endif 


