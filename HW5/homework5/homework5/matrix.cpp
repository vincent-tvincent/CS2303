#include "matrix.h"
matrix::matrix(int row, int col) {
	board = (int*) malloc(row*col*sizeof(int));
	int rowLength = row;
}

void matrix::set(int row, int col,int value) {
	int* target = getPointer(row,col);
	target = &value;
}

int* matrix::getPointer(int row, int col) {
	int* target = board + row + col * rowLength;
	return target;
}