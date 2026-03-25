#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

int *CriaVetor(int tamanho)
{
    int *vet;
    vet = malloc(tamanho*sizeof(int));

    if(vet == NULL)
    {
        printf("Erro ao alocar memoria!\n");
    }

    return vet;
}

void LeVetor(int *vetor, int tamanho)
{
    int i;
    for(i = 0; i < tamanho; i++)
    {
        scanf("%d", vetor+i);
    }
}

float CalculaMedia(int *vetor, int tamanho)
{
    float soma = 0;
    int i;

    for(i = 0; i < tamanho; i++)
    {
        soma = soma + *(vetor+i);
    }

    return soma/(float)tamanho;
}

void LiberaVetor(int *vetor)
{
    free(vetor);
}