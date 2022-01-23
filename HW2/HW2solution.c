#include "HW2header.h"

int polynomial(char* peremeters[])
{
    int answer = 0;
    for(int i = 1; i < sizeof(*peremeters)/sizeof(*peremeters[0]); i++) 
    {   
        answer += *peremeters[i] * *peremeters[0]^i; //a_i * x^power
    }
    return answer; 
}

int* argvToInt(int argc,char* argv[])
{
    int result[argc];
    for(int i = 1; i < argc; i++){
        
    }
    return result;
}