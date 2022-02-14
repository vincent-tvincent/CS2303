#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE* readFile = fopen("file.txt","r");
    int collect = -1;
    for (int i = 0; i < 2; i++){
        fscanf(readFile,"%d",&collect);
        printf("%d",collect);
    }
    fclose(readFile);
}
