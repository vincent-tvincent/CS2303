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
	int* getPointer(int, int);
private:
	int* board;
	int rowLength;
	int colLength;
};
#endif


