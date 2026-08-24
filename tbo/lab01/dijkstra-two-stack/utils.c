#include "utils.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int is_operand(char caracter)
{
    if (caracter >= '0' && caracter <= '9')
        return 1;

    return 0;
}

int is_operator(char caracter)
{
    switch (caracter)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '%':
        return 1;
        break;
    case '*':
        return 1;
        break;

    default:

        break;
    }

    return 0;
}

void print_double(void *data)
{
    double *num= (double*)data;

    printf("%lf ", *num);
}

void print_char(void *data)
{
    char *c = (char*)data;
    
    printf("%c ", *c);
}

char *read_expression()
{
    char *expression = malloc(sizeof(char) * MAX_SIZE);

    scanf("%[^\n]", expression);

    return expression;
}