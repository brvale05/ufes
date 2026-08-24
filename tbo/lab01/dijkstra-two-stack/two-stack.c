#include "two-stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void execute_algorithm(Stack *operators, Stack *operands, char *expression)
{
    char *ptr = expression;

    while (*ptr != '\0')
    {
        if (is_operand(*ptr))
        {
            char *endptr;
            double *num = malloc(sizeof(double));

            *num = strtod(ptr, &endptr);

            push(operands, num);

            ptr = endptr;
        }
        else if (is_operator(*ptr))
        {
            char *c = malloc(sizeof(char));
            *c = *ptr;
            push(operators, c);

            ptr++; 
        }
        else if (*ptr == ')')
        {
            double *num1 = (double *)pop(operands);
            double *num2 = (double *)pop(operands);

            char *op = (char *)pop(operators);

            double *result = malloc(sizeof(double));
            *result = do_operation(num1, num2, op);

            free(num1);
            free(num2);
            free(op);

            push(operands, result);

            ptr++; 
        }
        else
        {
            ptr++;
        }
    }
}

static double do_operation(double *num1, double *num2, char *op)
{
    switch (*op)
    {
    case '+':
        return *num1 + *num2;
        break;
    case '-':
        return *num1 - *num2;
        break;
    case '/':
        return *num1 / *num2;
        break;
    case '*':
        return *num1 * *num2;
        break;

    default:

        break;
    }
}