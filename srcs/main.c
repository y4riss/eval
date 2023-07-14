#include "eval.h"

#include <string.h>

#define BUFF_SIZE 126

int main(void)
{
    
    char buff[BUFF_SIZE];

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
        printf("%d\n",eval_expr(buff));
    }
    return 0;
}
