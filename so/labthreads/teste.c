#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *soma_primes(void *arg)
{
    int inicio = *((int *)arg);

    long soma = 0;

    for (int i = inicio; i < inicio + 5; i++)
    {
        soma += primes[i];
    }

    free(arg);

    return (void *)soma;
}

int main()
{
    pthread_t thread[2];

    void *result1, *result2;

    int *index1 = malloc(sizeof(int));
    int *index2 = malloc(sizeof(int));

    int i;

    *index1 = 0;
    *index2 = 5;

    if (pthread_create(&thread[0], NULL, &soma_primes, index1) != 0)
    {
        perror("Failed to created thread");
    }

    if (pthread_create(&thread[1], NULL, &soma_primes, index2) != 0)
    {
        perror("Failed to created thread");
    }

    if (pthread_join(thread[0], &result1) != 0)
    {
        perror("Failed to join thread");
    }

    if (pthread_join(thread[1], &result2) != 0)
    {
        perror("Failed to join thread");
    }

    long soma_final = (long)result1 + (long)result2;

    printf("Resultado da soma: %ld\n", soma_final);

    return 0;
}