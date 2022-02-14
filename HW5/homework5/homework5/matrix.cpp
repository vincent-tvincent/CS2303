#include "matrix.h"
#pragma warning(disable: 4996)
matrix::matrix(int row, int col) {
	board = (int*) malloc(row*col*sizeof(int));
	int rowLength = row;
	int colLength = col;
}

matrix::~matrix() {}

void matrix::initForTest() {
	for (int i = 0; i < rowLength * colLength; i++) {
		*(board + i) = i;
	}
	cout << "test board created: " << endl;
	onlyPrintBoard(); 
}

void matrix::set(int row, int col,int value) {
	printf("set value (%d,%d) to %d \n", row,col,value);
	int* target = getPointer(row,col);
	target = &value;
}

int* matrix::getPointer(int row, int col) {
	int* target = board + row + col * rowLength;
	return target;
}

void matrix::printBoard(char* fileName) {
	int endPoint = rowLength * colLength;
	FILE* output = fopen(fileName,"w");
	for (int i = 0; i < endPoint; i++) {
		printf("%d ",*board);
		int outNum = fprintf(output,"%d ", *board);
		if (i / (colLength - 1) == 0) { 
			puts("\n"); 
			fprintf(output,"\n");
		}
		board++;
	}
} 

void matrix::onlyPrintBoard() {
	cout << "start Print" << endl;
	int endPoint = rowLength * colLength;
	for (int i = 0; i < endPoint; i++) {
		printf("%d ", *board);
		if (i / (colLength - 1) == 0) {
			puts("\n");
		}
		board++;
	}
}

int* matrix::getBoard() {
	return board;
}
