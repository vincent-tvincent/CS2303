#include "HW2header.h"

int polynomial(int c, char* v[])
{
    int parameters[c - 1];
    for (int i = 1; i < c; i++) {
        parameters[i - 1] = *(v[i]) - '0';
    }
    int answer = 0;
    for (int i = 1; i < sizeof(*(parameters)) / sizeof(parameters[0]); i++)
    {
        answer += parameters[i] * parameters[0] ^ i; //a_i * x^power
    }
    return answer;
}

