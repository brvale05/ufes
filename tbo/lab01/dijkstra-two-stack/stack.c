#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    void **vector;
};

Stack *init()
{
    Stack *stack = malloc(sizeof(Stack));

    stack->vector = calloc(MAX_SIZE, sizeof(void *));
    stack->size = 0;

    return stack;
}

void push(Stack *stack, void *data)
{
    int size = stack->size;

    if (is_full(stack))
    {
        printf("Limite da pilha estourado.");
    }
    else
    {
        stack->vector[size] = data;
        stack->size++;
    }
}

void *pop(Stack *stack)
{
    int size = stack->size;

    if (is_empty(stack))
    {
        printf("Pilha está vazia, não há nada para eliminar");
    }
    else
    {
        int last_index = size - 1;
        stack->size--;

        return stack->vector[last_index];
    }
}

int is_empty(Stack *stack)
{
    if (!stack->size)
        return 1;

    return 0;
}

int is_full(Stack *stack)
{
    if (stack->size == MAX_SIZE)
        return 1;

    return 0;
}

void destroy(Stack *stack)
{
    if (stack)
    {
        if (stack->vector)
        {
            for (int i = 0; i < stack->size; i++)
            {
                if (stack->vector[i])
                {
                    free(stack->vector[i]);
                }
            }

            free(stack->vector);
        }

        free(stack);
    }
}

void print(Stack *stack, fptr_print print_func)
{
    for (int i = 0; i < stack->size; i++)
    {
        print_func(stack->vector[i]);
    }

    printf("\n");
}