#include "utils.h"


int isnum(char c)
{
    return '0' <= c && c <= '9';
}

void advance(char **expression)
{
   (*expression)++;
}


double parse_primary(char **expression)
{

    char *nb_start;
    char *nb_end;



    while(**expression == ' ') advance(expression); // skip whitespaces

    nb_start = *expression;

    while (isnum(**expression))
        advance(expression);

    nb_end = *expression;


    while(**expression == ' ') advance(expression);

    return strtod(nb_start,&nb_end);
}

double parse_unary(char **expression)
{
    double x;

    x = 1;

    while(**expression == ' ') advance(expression); // skip whitespaces
    while(**expression == '-')
    {
        x = x * (-1);
        advance(expression);
    }


    return x * parse_primary(expression);
}

double parse_factor(char **expression)
{
    double left;

    left = parse_unary(expression);


    while(**expression == '*' || **expression == '/')
    {
        char    op;
        double  right;

        op = **expression;
        advance(expression);
        right = parse_unary(expression);


        if(op == '*') left = left * right;
        else          left = left / right;
    }
    return left;


}

double parse_term(char **expression)
{
    double  left;
    
    left = parse_factor(expression);


    while(**expression == '+' || **expression == '-')
    {
        char    op;
        double  right;

        op = **expression;

        advance(expression);
        right = parse_factor(expression);

        if(op == '+') left = left + right;
        else          left = left - right;
    }

    return left;
}



double eval_expr(char *expression)
{
    return parse_term(&expression);
}