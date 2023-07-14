#include "helpers.h"

int isnum(char c)
{
    return '0' <= c && c <= '9';
}

void advance(char **expression)
{
    if (*expression)
        (*expression)++;
}



int str_to_int(char *start, char *end)
{

    int result;

    result = 0;

    //234

    while(*start != *end)
    {
       result = result * 10 + (*start - 48); 
       start++;
    }
    return result;
}


