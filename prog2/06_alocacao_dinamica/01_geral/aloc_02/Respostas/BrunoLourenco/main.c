#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    int **mat;
    mat = CriaMatriz(linhas, colunas);

    LeMatriz(mat, linhas, colunas);

    ImprimeMatrizTransposta(mat, linhas, colunas);

    LiberaMatriz(mat, linhas);

    return 0;
}