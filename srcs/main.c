#include "utils.h"


int main(int ac, char **av)
{
    
    if (ac > 1)
        printf("%.f\n",eval_expr(av[1]));

    return 0;
}
