#pragma once
#ifndef RM
#define RM
#include <cstdio>
#include <string.h>
#include "matrix.h"
class readMatrix
{
public:
	readMatrix(char**);
	readMatrix();
	virtual ~readMatrix();
	void printMatrix();
	void fillMatrix(char*);
	void fixMatrix();
private:
	char* inputName;
	char* outputName;
	int endLength;
	matrix* Matrix;
};
#endif 


