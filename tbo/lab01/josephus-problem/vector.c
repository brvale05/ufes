#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct Vector
{
    int **array;
    int size;
};

Vector *init(int N)
{
    Vector *v = malloc(sizeof(Vector));

    v->size = N;
    v->array = malloc(sizeof(int*) * v->size);

    for (int i = 0; i < v->size; i++)
    {
        v->array[i] = calloc(1, sizeof(int));
        *v->array[i] = i + 1;
    }
    

    return v;
}

int *pop(Vector *v, int i)
{
    int *ptr = v->array[i];

    for (int j = i; j < v->size - 1; j++)
    {
        v->array[j] = v->array[j + 1];
    }

    v->size--;

    return ptr;
    
}

void destroy(Vector *v)
{
    if (v)
    {
        if(v->array)
        {
            for (int i = 0; i < v->size; i++)
            {
                if(v->array[i])
                {
                    free(v->array[i]);
                }
            }

            free(v->array);
            
        }

        free(v);

    }
    
}

void print(Vector *v)
{
    for (int i = 0; i < v->size; i++)
    {
        int *num = v->array[i];

        printf("%d ", *num);
    }
    
}

int vector_size(Vector *v)
{
    return v->size;
}


