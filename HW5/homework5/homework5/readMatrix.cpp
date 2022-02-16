#include "readMatrix.h"
#pragma warning(disable: 4996)
readMatrix::readMatrix(char* input, char*output) {
	inputName = input;
	outputName = output;
	endLength = -1;
	fillMatrix(inputName);
	fixMatrix();
}

readMatrix:: ~readMatrix() {}

void readMatrix::fillMatrix(char* fileName) {
	FILE* target = fopen(fileName,"r");
	//set the end of the loop
	fscanf(target,"%d",endLength);
	//initialize loop elements
	int maxRead = 0;
	int counter = 0;
	int readValue = -1;
	while (counter < maxRead && maxRead < endLength) {
		
		fscanf(target,"%d",readValue);
		Matrix->set(counter,maxRead,readValue);
		if (counter < maxRead) {//judge if go to next column
			counter++;//not go to next column
		}
		else {//go to next column
			counter = 0;
			maxRead++;
		}
	} 
	fclose(target);
	fflush(target);
	fixMatrix(); 
}

void readMatrix::fixMatrix() {
	//initialize the loop 
	int rowStart = 1;
	int row = rowStart;
	int col = 0;
	//start of the loop  
	while (row < endLength && col < endLength) {
		int* adjValue = Matrix->getPointer(col,row);
		Matrix->set(row, col, *adjValue);
		if (row < endLength) {//judge if go to next column
			row++;//not go to next column
		}
		else {//go to next column 
			Matrix->set(rowStart,col,0);// set the connection to itself to 0 
			//move to next column's start point
			rowStart++;
			row = rowStart;
			col++;
		}
	}
}

void readMatrix::printMatrix() {
	Matrix->printBoard(outputName);
}

matrix readMatrix::getMatrix() {
	return *Matrix;
}
