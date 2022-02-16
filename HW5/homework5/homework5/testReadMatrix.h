#pragma once
#ifndef TRM
#define TRM
#include "readMatrix.h"
class testReadMatrix
{
public: 
	testReadMatrix(char*,char*);
	bool test();
private:
	char* inputFile;
	char* outputFile; 
	bool testFillMatrix();
	bool testFixMatrix();
	bool testPrintMatrix(); 
};
#endif

