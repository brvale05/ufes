#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "josephus.h"

int main(int argc, char **argv)
{
    int N, M;

    printf("DIGITE N E M:\n");
    scanf("%d %d", &N, &M);

    Vector *vector = init(N);

    execute_algorithm(vector, M);
    
    destroy(vector);

    return 0;
}