#ifndef EVAL_H
#define EVAL_H

#include <stdlib.h>
#include <stdio.h>


int eval_expr(char *string);
int parse_primary(char **expression);
int parse_unary(char **expression);
int parse_factor(char **expression);
int parse_term(char **expression);



#endif // EVAL_H
