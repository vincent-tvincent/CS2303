#include "HW2header.h"

int polynomial(char* peremeters[])
{
    int answer = 0;
    for(int i = 1; i < sizeof(*peremeters)/sizeof(*peremeters[0]); i++) 
    {   

        printf("peremeters[i]%d",peremeters[i]); 
        printf("peremeters[0]%d",peremeters[0]); 
        answer += *peremeters[i] * *peremeters[0]^i; //a_i * x^power
    }
    return answer; 
}