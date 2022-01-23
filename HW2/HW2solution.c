#include "HW2header.h"

int polynomial(int argc, char* argv[])
{
    int parameters[argc - 1];
    for (int i = 1; i < argc; i++) {
        parameters[i - 1] = *(argv[i]) - '0';
    }
    int answer = 0;
    for (int i = 1; i < sizeof(*(parameters)) / sizeof(parameters[0]); i++)
    {
        answer += parameters[i] * parameters[0] ^ i; //a_i * x^power
    }
    return answer;
}


