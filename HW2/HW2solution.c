#include "HW2header.h"

int polynomial(int peremeters[])
{
    int answer = 0;
    for (int i = 1; i < sizeof(peremeters) / sizeof(peremeters[0]); i++)
    {
        answer += peremeters[i] * peremeters[0] ^ i; //a_i * x^power
    }
    return answer;
}


//this function consume an array of type char and return an array of type integer. 
int argvToInt(int argc, char* argv[])
{
    int result = new int[argc - 1];
    for (int i = 1; i < argc; i++) {
        result[i - 1] = argv[i] - '0';
    }
    return result;
}
