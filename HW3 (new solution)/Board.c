/*
	group member: 
	Yuancen Pu
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
	int randRow = rand()%(nRow - 1);
	int randCol = rand()%(nCol - 1);
	pair* randPointer = (pair*) malloc(sizeof(pair));
	randPointer -> row = randRow;
	randPointer -> col = randCol;
	return randPointer;
}


void swap(int* theBoard, int nrows, int ncols,int row,int col){
	int* startingPlace = theBoard + row*ncols + col;
	int newCol = -1;
	int newRow = -1;
	//printBoard(theBoard,nrows,ncols);
	if(col == 0){
		newCol = ncols - 1;
	}else{
		newCol = col - 1;
	}

	if(row + 1 < nrows){
		newRow = row + 1;
	}else{
		newRow = 0;
	}
	int* endingPlace = theBoard + newRow*ncols + newCol;  
	int temp = *endingPlace;
	*endingPlace = *startingPlace;
	*startingPlace = temp;
	//printBoard(theBoard,nrows,ncols);
}

int select(int* theBoard, int nRow, int nCol){
	pair* coodinate = randChoose(nRow,nCol);
	int* pointer = theBoard + (coodinate -> row)*nCol + coodinate -> col;
	return *pointer;
}





