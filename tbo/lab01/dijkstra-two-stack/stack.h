#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct Stack Stack;

typedef void (*fptr_print)(void *data);

Stack *init();

void push(Stack *stack, void *data);

void *pop(Stack *stack);

int is_empty(Stack *stack);

int is_full(Stack *stack);

void destroy(Stack *stack);

void print(Stack *stack, fptr_print print_func);

#endif