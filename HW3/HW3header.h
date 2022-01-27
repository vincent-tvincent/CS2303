/*
    team members: 
    Yuancen Pu 
*/
#ifndef HW3;
#define HW3;
#include <stdio.h>;
#include <stdlib.h>;
int value = 1;

typedef struct{
    int row;
    int col;
    int value;
}block;

typedef struct{
    int maxRow;
    int maxCol;
    block** start; 
}board;

//homework3 questions 
void loading(int**);
void randomChoosing(int**);
void swapping(int**);
void selecting(int**);

//helper functions 
int* toInt(int, char*);
board boardInit(int, int);
block** anotherBlock(board,block*,int, int);
block** pointerInit(board,int,int);
block** randLocation(board);
void swap(board,block**, block**); 

#endif 
