#ifndef TWO_STACK_H
#define TWO_STACK_H

#include "stack.h"
#include "utils.h"

void execute_algorithm(Stack *operators, Stack *operands, char *expression);

static double do_operation(double *num1, double *num2, char *op);

#endif