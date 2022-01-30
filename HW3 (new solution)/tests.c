/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"

void printBoard(int* board, int nrows, int ncols)
{   
    int* pointer = board;
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            printf("%d ",*pointer);
            if(*pointer < 10){printf(" ");}
            pointer++;
        }
        printf("\n");
    }
}

bool testLoad()
{
	bool ok = true; //so far
	puts("\nStarting test load"); fflush(stdout);
	//setup
	int* board = (int*) malloc (10*10*sizeof(int));
	int testRow = 6;
	int testCol =8;
	
	//trial
	load(board, 10,10);
	int* whichIsIt = board+ testRow*10 + testCol;
	int answer = *whichIsIt;
	int rightAnswer = 3*testRow + 5*testCol;
	ok = (answer == rightAnswer);
	

	//judgment
	if(ok)
	{
		puts("load passed its test");

	} else{
		puts("load did not pass its test");
	}

	return ok;;
}

bool testRandChoose()
{
	bool ok = true;
	puts("start testing randChoose");
	//setup 
	int* board = (int*) malloc(10*10*sizeof(int));

	//trial 
	pair* answer = randChoose(10,10);
	
	//judgement 
	ok = answer -> row < 10 && answer -> row > -1 && answer -> col < 10 && answer -> col > -1;
	if(ok){
		puts("randChoose passed its test");
	}else{
		puts("randChoose did not pass its test");
	}

	return ok;
}

bool testSwapHelper(int row, int col)
{
	bool ok = true;
	printf("start testing swap with value row = %d and col = %d \n",row,col);
	//setup 
	int* board = (int*) malloc(10*10*sizeof(int));
	int* p = board;
	int newRow = -1;
	int newCol = -1;

	if(col == 0){
		newCol = 10 - 1;
	}else{
		newCol = col - 1;
	}

	if(row + 1 < 10){
		newRow = row + 1;
	}else{
		newRow = 0;
	}

	int* pointer1 = board + row*10 + col;
	int* pointer2 = board + newRow*10 + newCol;
	*pointer1 = 1;
	*pointer2 = 2;
	
	//trial 
	swap(board,10,10,row,col);
	
	//judgement 
	ok = *pointer1 == 2 && *pointer2 == 1; 
	if(ok){
		puts(" swap passed the test");
	}else{
		puts(" swap did not pass the test");
	}

	return ok;
}

//sorry for still write it in two methods, I'm too lazy to type in same thing too much times 
bool testSwap(){
	puts("start testing swap");
	bool ok1 = testSwapHelper(2,3);
	bool ok2 = testSwapHelper(9,2);
	bool ok3 = testSwapHelper(2,0);
	bool ok4 = testSwapHelper(9,0);
	return ok1 && ok2 && ok3 && ok4;
}

bool testSelect(){
	bool ok = true;
	//setup 
	int* board = (int*) malloc(10*10*sizeof(int));
	int* pointer = board;
	//trial
	
	//judgement
	
	return ok;	
}

bool tests(){
	puts("start tests");
	bool ok = testLoad() && testRandChoose() && testSwap() && testSelect();
	if(ok){
		puts("all test passed");
	}else{
		puts("test did not pass"); 
	}
	return ok;
};

