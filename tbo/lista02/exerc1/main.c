#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000000

//Tempo de execução de 0.993 segundos com 100 milhões de valores.

int compare_int(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

int main(int argc, char **argv)
{
    int *vet_1 = malloc(sizeof(int) * MAX_SIZE);
    int *vet_2 = malloc(sizeof(int) * MAX_SIZE);

    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++)
    {
        vet_1[i] = (rand() % MAX_SIZE) + 1;
        vet_2[i] = (rand() % MAX_SIZE) + 1;
    }

    qsort(vet_1, MAX_SIZE, sizeof(int), compare_int);
    qsort(vet_2, MAX_SIZE, sizeof(int), compare_int);

    int last_index = 0;
    int i = 0;

    clock_t start, stop;
    start = clock();
    while (i < MAX_SIZE)
    {
        if (vet_1[i] < vet_2[last_index])
        {
            i++;
        }
        else if (vet_1[i] == vet_2[last_index])
        {
            // printf("%d ", vet_1[i]);
            last_index++;
            i++;
        }
        else
        {
            last_index++;
        }
    }
    stop = clock();

    double time_taken = ((double)stop - start) / CLOCKS_PER_SEC;

    printf("Elapsed time: %.3f\n", time_taken);

    free(vet_1);
    free(vet_2);

    return 0;
}