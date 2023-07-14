#ifndef EVAL_H
#define EVAL_H

#include <stdlib.h>
#include <stdio.h>



long long int eval_expr(char *string);
long long int parse_primary(char **expression);
long long int parse_unary(char **expression);
long long int parse_factor(char **expression);
long long int parse_term(char **expression);

extern int error;
#endif // EVAL_H
