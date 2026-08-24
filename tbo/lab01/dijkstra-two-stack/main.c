#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "two-stack.h"
#include "utils.h"

int main(int argc, char **argv)
{ 
    char *expression;

    while ((expression = read_expression() != NULL))
    {
        Stack *operators = init(); // char vector
        Stack *operands = init();  // double vector
        
        execute_algorithm(operators, operands, expression);

        printf("RESULTADO:");
        print(operands, print_double);

        destroy(operands);
        destroy(operators);
        free(expression);
    }

    return 0;
}