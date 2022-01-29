/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"

bool testLoad()
{
	bool ok = true; //so far
	puts("Starting test load"); fflush(stdout);
	//setup
	int* board = (int*) malloc (11*12*sizeof(int));
	int testRow = 6;
	int testCol =4;

	//trial
	load(board, 11,12);
	int* whichIsIt = board+ testRow + testCol;
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
	ok = answer -> row < 10 && answer -> row > 10 && answer -> col < 10 && answer -> col < 10;
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
	printf("start testing swap with value row = %d and col = %d",row,col);
	//setup 
	int* board = (int*) malloc(10*10*sizeof(int));
	int* pointer1 = board + row*10 + col;
	int* pointer2 = board + (row + 1)*10 + col - 1;
	*pointer1 = 1;
	*pointer2 = 2;
	
	//trial 
	swap(board,10,10,row,col);
	
	//judgement 
	ok = *pointer1 == 2 && *pointer2 == 1; 
	if(ok){
		puts("swap passed the test");
	}else{
		puts("swap did not pass the test");
	}

	return ok;
}

//sorry for still write it in two methods, I'm too lazy to type in same thing too much times 
bool testSwap(){
	puts("start testing swap");
	bool ok1 = testSwapHelper(2,3);
	bool ok2 = testSwapHelper(10,2);
	bool ok3 = testSwapHelper(2,1);
	bool ok4 = testSwapHelper(10,1);
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

void tests(){
	puts("start tests");
	bool ok = testLoad() && testRandChoose() && testSwap() && testSelect();
	if(ok){
		puts("all test passed");
	}else{
		puts("test did not pass"); 
	}
};

