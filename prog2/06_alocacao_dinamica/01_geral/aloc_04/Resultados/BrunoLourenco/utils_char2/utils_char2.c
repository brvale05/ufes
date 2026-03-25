#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

char *CriaVetorTamPadrao()
{
    char *str;

    str = malloc(TAM_PADRAO*sizeof(char));
    if(str == NULL)
    exit(0);

    int i;
    for(i = 0; i < TAM_PADRAO; i++)
    {
        if(i == 9)
        {
            *(str+i) = '\0';
            break;
        }
        *(str+i) = '_';
    }

    return str;

}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo)
{
    vetor = realloc(vetor, tamanhoantigo + TAM_PADRAO);
    return vetor;
}

char* LeVetor(char *vetor, int *tamanho)
{
    int i = 0;
    do
    {
        scanf("%c", vetor+i);

        if(*(vetor+i) == '\n')
        break;

        if(i == *tamanho-1)
        {
            *tamanho = *tamanho + TAM_PADRAO;
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
        }

        i++;

    } while(1);

    *(vetor+i) = '\0';

    for(i = i; i < *tamanho; i++)
    {
        if(i == *tamanho - 1)
        {
            *(vetor+i) = '\0';
            break;
        }
        *(vetor+i) = '_';
    }
    
    return vetor;

}

void ImprimeString(char *vetor)
{
    printf("%s_\n", vetor);
}

void LiberaVetor(char *vetor)
{
    free(vetor);
}