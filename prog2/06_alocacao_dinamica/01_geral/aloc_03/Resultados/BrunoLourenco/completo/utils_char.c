#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

char *CriaVetor(int tamanho)
{
    char *str;
    int i;

    str = malloc(tamanho*sizeof(char));
    if(str == NULL)
    exit(0);

    for(i = 0; i < tamanho; i++)
    {
        *(str+i) = '_';
    }

    return str;

}

void LeVetor(char *vetor, int tamanho)
{
    int i;
    for(i = 0; i < tamanho; i++)
    {
        scanf("%c", vetor+i);
        if(*(vetor+i) == '\n')
        {
            *(vetor+i) = '_';
        }
    }
    printf("\n");
}

void ImprimeString(char *vetor, int tamanho)
{
    int i;
    for(i = 0; i < tamanho; i++)
    {
        printf("%c", *(vetor+i));
    }
    printf("\n");
}

void LiberaVetor(char *vetor)
{
    free(vetor);
}