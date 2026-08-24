#ifndef VECTOR_H
#define VECTOT_H

typedef struct Vector Vector;

Vector *init(int N);

void destroy(Vector *v);

void print(Vector *v);

int *pop(Vector *v, int i);

int vector_size(Vector *v);

#endif