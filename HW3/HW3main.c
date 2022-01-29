#include "HW3header.h"
int main(int argc, char* argv[]){
    board Board1 = boardInit(5,5);
    block** pointer1 = Board1.start;
    block* drfPointer1 = *pointer1; 
    printf("%s",drfPointer1->value);
    
    return 0;
}