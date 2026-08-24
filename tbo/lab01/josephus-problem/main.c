#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main(int argc, char **argv)
{
    int N, M;

    printf("DIGITE N E M:\n");
    scanf("%d %d", &N, &M);

    Vector *vector = init(N);
    
    destroy(vector);

    return 0;
}