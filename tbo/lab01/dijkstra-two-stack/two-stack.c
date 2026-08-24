#include "two-stack.h"

#include <stdlib.h>
#include <stdio.h>

void execute_algorithm(Stack *operators, Stack *operands, char *expression)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char car = expression[i];

        if (is_operand(car))
        {
            double *num = malloc(sizeof(double));

            *num = atof(&car);

            push(operands, num);
        }
        else if (is_operator(car))
        {
            char *c = malloc(sizeof(char));

            *c = car;

            push(operators, c);
        }
        else if (car == ')')
        {
            double *num1 = (double *)pop(operands);
            double *num2 = (double *)pop(operands);

            char *op = (char *)pop(operators);

            double *result = malloc(sizeof(double));
            *result = do_operation(num1, num2, op);

            // printf("%lf %c %lf = %lf\n", *num1, *op, *num2, *result);

            free(num1);
            free(num2);
            free(op);

            push(operands, result);
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