#include "eval.h"
#include "helpers.h"

void check_form(char c)
{
    if(!(isnum(c) || c == '(' || c == ')' || c == '+'
    || c == '-' || c == '*' || c == '%' || c == '/' || c == '\n'))
    {
        
        fprintf(stderr, "Invalid expression format\n");
        exit(55);
    }
}

int parse_primary(char **expression)
{

    char *nb_start;
    char *nb_end;

    int e;



    while(**expression == ' ') advance(expression); // skip whitespaces

    nb_start = *expression;



    if (**expression == '(')
    {
        advance(expression);
        e = parse_term(expression);

        if (**expression != ')')
        {
            fprintf(stderr,"unmatching parenthesis\n");
            exit(77);
        }
        advance(expression);
        while(**expression == ' ') advance(expression); // skip whitespaces

        return e;
    }
    while (isnum(**expression))
        advance(expression);

    nb_end = *expression;

    // check if expression has a correct form

    while(**expression == ' ') advance(expression);

    check_form(**expression);
    return str_to_int(nb_start,nb_end);
}

int parse_unary(char **expression)
{
    int x;

    x = 1;

    while(**expression == ' ') advance(expression); // skip whitespaces
    while(**expression == '-')
    {
        x = x * (-1);
        advance(expression);
    }


    return x * parse_primary(expression);
}

int parse_factor(char **expression)
{
    int left;

    left = parse_unary(expression);


    while(**expression == ' ') advance(expression); // skip whitespaces
    while(**expression == '*' || **expression == '/' || **expression == '%')
    {
        char    op;
        int  right;

        op = **expression;
        advance(expression);
        right = parse_unary(expression);


        if(op == '*') left = left * right;
        else if(op == '%') left = left % right;
        else  {

            if (right == 0)
            {
                fprintf(stderr,"error, division by zero\n");
                exit(69);
            }
            left = left / right;
        }
    }
    return left;


}

int parse_term(char **expression)
{
    int  left;
    
    left = parse_factor(expression);


    while(**expression == ' ') advance(expression); // skip whitespaces
    while(**expression == '+' || **expression == '-')
    {
        char    op;
        int  right;

        op = **expression;

        advance(expression);
        right = parse_factor(expression);

        if(op == '+') left = left + right;
        else          left = left - right;
    }

    return left;
}



int eval_expr(char *expression)
{
    return parse_term(&expression);
}