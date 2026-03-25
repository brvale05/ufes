#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        scanf("%d", vet+i);
    }
}

void ImprimeDadosDoVetor(int * n, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("%d ", *(n+i));
    }

    printf("\n");

}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar)
{
    int i, aux;

    for(i = 0; i < tam; i++)
    {
        if(*(vet+i) > *paraTrocar)
        {
            aux = *(vet+i) ;
            *(vet+i) = *paraTrocar;
            *paraTrocar = aux;
        }
    }
}

void OrdeneCrescente(int * vet, int tam)
{
    int i;

    for(i = 0; i < tam; i++)
    {
        TrocaSeAcharMenor(vet, tam, vet+i);
    }
}