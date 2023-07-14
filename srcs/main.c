#include "eval.h"

#include <string.h>

#define BUFF_SIZE 126

int error;

int main(void)
{
    
    char buff[BUFF_SIZE];
    long long int output;


    printf("\nWelcome to eval, a simple arithmetic expression evaluator !\n");
    printf("If you want to quit, type exit.\n\n");
    while(1)
    {
        printf("> ");
        fgets(buff, BUFF_SIZE, stdin);
        if (strcmp(buff,"exit\n") == 0)
        {
            return 0;
        }
        error = 0;
        output = eval_expr(buff);
        if (error != 0)
        {
            switch(error)
            {
                case 1 :
                    printf("[Error] : division by zero.\n");
                    break;
                case 2 :
                    printf("[Error] : invalid format.\n");
            }
        }
        else printf("%lld\n",output);
    }
    return 0;
}
