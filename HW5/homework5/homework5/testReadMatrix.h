#pragma once
#ifndef TRM
#define TRM
#include "readMatrix.h"
class testReadMatrix
{
public: 
	testReadMatrix();
	bool test();
private:
	char* inputFile;
	char* outputFile;
	int testLength;
	int* testMatrix;
	bool testFillMatrix();
	bool testFixMatrix();
	bool testPrintMatrix(); 
};
#endif

