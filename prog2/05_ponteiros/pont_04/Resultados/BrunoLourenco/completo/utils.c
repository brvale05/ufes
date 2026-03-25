#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho)
{
    int i;
    for(i = 0; i < tamanho; i++)
    {
        scanf("%d", array+i);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{
    int i;

    *media = 0;

    for(i = 0; i < tamanho; i++)
    {
        if(!i)
        {
            *maior = *(array+i);
            *menor = *(array+i);
        }
        
        if(*(array+i) > *maior)
        {
            *maior = *(array+i);
        }

        if(*(array+i) < *menor)
        {
            *menor = *(array+i);
        }

        *media = *(array+i) + *media;
    }

    *media = (*media/tamanho);
}