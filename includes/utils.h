#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>


double eval_expr(char *string);
double parse_primary(char **expression);
double parse_unary(char **expression);
double parse_factor(char **expression);
double parse_term(char **expression);


#endif // UTILS_H
