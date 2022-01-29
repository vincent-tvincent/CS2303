/*
 * Board.c
 *
 *  Created on: Nov 9, 2021
 *      Author: theresesmith
 */

#include "Board.h"

void load(int* theBoard, int nrows, int ncols)
{

	for(int row = 0; row<nrows; row++)
	{
		for(int col = 0; col<ncols; col++)
		{
			int* whereOnBoard = theBoard + row*ncols + col;
			*whereOnBoard = 3*row + 5*col;
			
		}
	}

}

pair* randChoose(int nRow, int nCol){
	int randRow = rand()%nRow;
	int randCol = rand()%nCol;
	pair* randPointer = (pair*) malloc(sizeof(pair));
	randPointer -> row = randRow;
	randPointer -> col = randCol;
	return randPointer;
}

void swap(int* theBoard, int nrows, int ncols,int row,int col){
	int* startingPlace = theBoard + row*ncols + col;
	int newCol = -1;
	if(col - 1 == 0){
		newCol = ncols - 1;
	}else{
		newCol = col - 1;
	}

	int* endingPlace = theBoard +((row+1)%nrows)*ncols + newCol;  
	int temp = *endingPlace;
	*endingPlace = *startingPlace;
	*startingPlace = temp;
}

int select(int* theBoard, int nRow, int nCol){
	int randRow = rand()%nRow;
	int randCol = rand()%nCol;
	int* pointer = theBoard + randRow*nCol + randCol;
	return *pointer;
}



