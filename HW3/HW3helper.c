#include "HW3header.h";
// just for convert argv
int* toInt(int argc, char* argv){
    int* intArray = malloc(argc * sizeof(int));
    int* pointer = intArray;
    for(int i = 1; i < argc;  i++){
        pointer = argv[i] -  '0';
    }
    return intArray;
}

//for get modulus number
int modulus(int value, int peroid){
    if(value > peroid){
        value -= peroid;
    }else if(value < 0){
        value += peroid;
    }

    return value;
}

/*
return value: board
thsi function will comsume two int type virable as the row and colomulum 
*/
board boardInit(int maxRow, int maxCol){
    block firstBlock = {0,0,0};
    block* firstBlockPointer = &firstBlock;
    board Board = {maxRow - 1,maxCol - 1,(block**) malloc(maxRow*maxCol*sizeof(block*))};
    *(Board.start) = &firstBlock;
    return Board;
}

/*
return value: block**
this function will consume two int type value as the coodinate of the new pointer and one board type value as the board, 
then return a pointer of this block pointer. 
*/
block** pointerInit(board Board,int row, int col){
    block** newPointer = Board.start + row*Board.maxCol + col;
    return newPointer;
}
/*
return value: block**
this function will consume two int type value as the movement on row and colomulum and one board type value as the board,
and return the pointer of the block pointer at the location after movement
*/
block** anotherBlock(board Board,block* currentBlock,int rowMove, int colMove){    
    int maxRow = Board.maxRow;
    int maxCol = Board.maxCol;
    int currentRow = currentBlock->row;
    int currentCol = currentBlock->col;

    int newRow = modulus(currentRow + rowMove,maxRow);
    int newCol = modulus(currentCol + colMove,maxCol);
    return pointerInit(Board,newRow,newCol);
}

/*
return value: block**
this function will consume a board type value as the board and return a pointer of block type pointer
as a random location on this board 
*/
block** randLocation(board Board){
    int maxRow = Board.maxRow;
    int maxCol = Board.maxCol;
    
    int randRow = rand()%maxRow;
    int randCol = rand()%maxCol;
    return pointerInit(Board,randRow,randCol);
}

/*
return value: no return 
this function consume two pointers of block pointers, then swap the value of this two pointers
*/
void swap(board Board, block** pointer1, block** pointer2){
    block* block1 = *pointer1;
    block* block2 = *pointer2;
    int temp = block1->value;
    block1->value = &(block2->value);
    block2->value = &temp;
}



