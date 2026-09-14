#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 30

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
        vet_1[i] = (rand() % 30) + 1;
        vet_2[i] = (rand() % 30) + 1;
    }

    qsort(vet_1, MAX_SIZE, sizeof(int), compare_int);
    qsort(vet_2, MAX_SIZE, sizeof(int), compare_int);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", vet_1[i]);        
    }

    printf("\n\n");

    for (int i = 0; i < MAX_SIZE; i++)
    {        
        printf("%d ", vet_2[i]);
    }

    printf("\n\n");

    int last_index = 0;
    int i = 0;

    while (i < MAX_SIZE)
    {
        if (vet_1[i] < vet_2[last_index])
        {
            i++;
        }
        else if (vet_1[i] == vet_2[last_index])
        {
            printf("%d ", vet_1[i]);
            last_index++;
            i++;
        }
        else
        {
            last_index++;
        }
    }

    free(vet_1);
    free(vet_2);

    return 0;
}