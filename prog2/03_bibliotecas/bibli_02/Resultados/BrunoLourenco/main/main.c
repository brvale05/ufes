#include "./matrix_utils.h"
#include <stdio.h>

void Imprime_Cabecalho();

void Realiza_Op(int op, int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2]);

int main()
{

    int rows1, cols1; 
    scanf("%d %d", &rows1, &cols1);

    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);
    
    int rows2, cols2;
    
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    int op;

    while(scanf("%d", &op) == 1)
    {
        Imprime_Cabecalho();
        Realiza_Op(op, rows1, cols1, matrix1, rows2, cols2, matrix2);
    }

    return 0;

}

void Imprime_Cabecalho()
{
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}

void Realiza_Op(int op, int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2])
{
    int whichMatrix, scalar;

    if(op == 1)
    {
        int result[rows1][cols1];
        if(possible_matrix_sum(rows1, cols1, rows2, cols2) > 0)
        {
            matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols1, result);
        }
        else
        {
            printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
    }
    if(op == 2)
    {
        int result[rows1][cols1];
        if(possible_matrix_sub(rows1, cols1, rows2, cols2) > 0)
        {
            matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols1, result);
        }
        else
        {
            printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
    }  
    if(op == 3)
    {
        int result[rows1][cols2];
        if(possible_matrix_multiply(cols1, rows2) > 0)
        {
            matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols2, result);
        }
        else
        {
            printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        }
    }  
    if(op == 4)
    {
        scanf("%d %d", &scalar, &whichMatrix);

        if(whichMatrix == 1)
        {
            scalar_multiply(rows1, cols1, matrix1, scalar);
            matrix_print(rows1, cols1, matrix1);
        }
        else
        {
            scalar_multiply(rows2, cols2, matrix2, scalar);
            matrix_print(rows2, cols2, matrix2);
        }
    }  
    if(op == 5)
    {
        int result1[cols1][rows1];
        transpose_matrix(rows1, cols1, matrix1, result1);
        matrix_print(cols1, rows1, result1);
       
        int result2[cols2][rows2];
        transpose_matrix(rows2, cols2, matrix2, result2);
        matrix_print(cols2, rows2, result2);
        
    }  
    if(op == 6)
    {
        return 0;
    }
}

