#include"Board.h"
#include"tests.h"
//that's just for turn char to int, no relationship with the main content. 
int* toInt(int argc, char* argv){
    int* intArray = malloc(argc * sizeof(int));
    int* pointer = intArray;
    for(int i = 1; i < argc;  i++){
        int pointerValue = argv[i] -  '0';
        pointer = &pointerValue;
        pointer++; 
    }

    return intArray;
}

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

int main(int argc, char* argv[]){
    //set up
    int* coodinate = toInt(argc,*argv);
    int row = *coodinate;
    int col = *(coodinate++);
    int* board = (int*) malloc(10*10*sizeof(int));
    
    //1. do "loading"
    load(board,10,10);
    printBoard(board, 10,10);
    
    //2. do "Choose with pseudorandomness"
    pair* chooseResult = randChoose(10,10);
    printf("randome choosed pair is (%d, %d)", *chooseResult,*(chooseResult++));

    //3. do "swapping"
    puts("board before swapping: ");
    printBoard(board,10,10);
    swap(board,10,10,2,3);
    puts("board after swapping: ");
    printBoard(board,10,10);

    //4. do "selecting"
    printf("randomly selected result: %d",select(board,10,10));

}