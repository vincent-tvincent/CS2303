#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    FILE* writeFile = fopen("file.txt","w");
    int test = 1;
    for(int i = 0; i < 3; i++){
        fprintf(writeFile, "%d", test);
    }
    fclose(writeFile);
    FILE* readFile = fopen("file.txt","r");
    int collect = -1;
    for (int i = 0; i < 2; i++){
        fscanf(readFile,"%d",&collect);
        printf("%d",collect);
    }
    fclose(readFile); 
}
