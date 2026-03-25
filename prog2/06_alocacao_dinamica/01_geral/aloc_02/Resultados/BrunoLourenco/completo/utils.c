#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int **CriaMatriz(int linhas, int colunas)
{
    int **mat;

    mat = malloc(linhas * sizeof(int*));

    if(mat == NULL)
    {
        exit(1);
    }

    int i;
    for(i = 0; i < linhas; i++)
    {
        mat[i] = malloc(colunas * sizeof(int));
        if(mat[i] == NULL)
        exit(1);
    }

    return mat;

}

void LiberaMatriz(int **matriz, int linhas)
{
    int i;
    for(i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas)
{
    int i, j;
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{
    int i, j;
    for(i = 0; i < colunas; i++)
    {
        for(j = 0; j < linhas; j++)
        {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}