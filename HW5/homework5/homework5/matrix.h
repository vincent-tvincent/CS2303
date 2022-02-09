#pragma once
#ifndef MA
#define MA
#include "io.h"

class matrix
{
public:
	matrix(int,int);
	virtual ~matrix();
	void set(int, int, int);
	void printBoard();
private:
	int* board;
	int rowLength;
	int* getPointer(int, int);
};
#endif


