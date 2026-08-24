#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void execute_algorithm(Vector *v, int M)
{
    int next_index = 0;

    while (vector_size(v) > 1)
    {
        next_index = (next_index + M - 1) % vector_size(v);

        int *person = pop(v, next_index);

        printf("A pessoa com ID {%d} foi removida\n", *person);
        free(person);
    }

    int *leader = pop(v, (next_index + M - 1) % vector_size(v));

    printf("A pessoa com ID {%d} é o Líder\n", *leader);

    free(leader);
    
}