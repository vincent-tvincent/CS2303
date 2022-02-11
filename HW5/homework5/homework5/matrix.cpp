#include "matrix.h"
matrix::matrix(int row, int col) {
	board = (int*) malloc(row*col*sizeof(int));
	int rowLength = row;
	int colLength = col;
}

matrix::~matrix() {}

void matrix::set(int row, int col,int value) {
	int* target = getPointer(row,col);
	target = &value;
}

int* matrix::getPointer(int row, int col) {
	int* target = board + row + col * rowLength;
	return target;
}

void matrix::printBoard() {
	int endPoint = rowLength * colLength;
	for (int i = 0; i < endPoint; i++) {
		printf("%d ",*board);
		if (i / (colLength - 1) == 0) { puts("\n");}
		board++;
	}
}