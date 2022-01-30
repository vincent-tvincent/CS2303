#include"Board.h"
//that's just for turn char to int, no relationship with the main content. 

int main(int argc, char *argv[]){
    printf("%d\n", argc);
    //set up
    int row = *(argv[1]) - '0';
    int col = *(argv[2]) - '0';
    int* board = (int*) malloc(row*col*sizeof(int));

    //0. apply test
    if(tests()){
        printf("\n current value: row: %d, col: %d\n\n",row,col);
        //1. do "loading"
        load(board,row,col);
        printBoard(board,row,col);
    
        //2. do "Choose with pseudorandomness"
        pair* chooseResult = randChoose(row,col);
        printf("\nrandome choosed pair is (%d, %d)", chooseResult -> row,chooseResult -> col);

        //3. do "swapping"
        puts("\nboard before swapping: ");
        printBoard(board,row,col);
        swap(board,row,col,2,3);
        puts("\nboard after swapping: ");
        printBoard(board,row,col);

        //4. do "selecting"
        printf("\n randomly selected result: %d",select(board,row,col));

    }
}