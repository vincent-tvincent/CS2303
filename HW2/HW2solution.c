#include "HW2header.h"
int polynomial(int c, char* v[])
{
    int* parameters =(int*) malloc(c * sizeof(int));
    for (int i = 1; i < c; i++) {
        parameters[i - 1] = *(v[i]) - '0';
    }
    int answer = 0;

    for (int i = 1; i < c - 1; i++)
    {
        answer += parameters[i] * pow(parameters[0],i);
    }
    return answer;
}

