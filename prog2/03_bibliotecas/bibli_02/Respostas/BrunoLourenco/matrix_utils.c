#include "./matrix_utils.h"
#include <stdio.h>

void matrix_read(int rows, int cols, int matrix[rows][cols])
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols])
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        printf("|");
        for(j = 0; j < cols; j++)
        {
            printf("%d", matrix[i][j]);
            if(j >= 0 && j < cols - 1) printf(" ");
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2)
{
    if(rows1 == rows2 && cols1 == cols2)
    {
        return 1;
    }
    return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2)
{
    if(rows1 == rows2 && cols1 == cols2)
    {
        return 1;
    }
    return 0;
}

int possible_matrix_multiply(int cols1, int rows2)
{
    if(cols1 == rows2)
    {
        return 1;
    }
    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    int i, j;
    for(i = 0; i < rows1; i++)
    {
        for(j = 0; j < cols1; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    int i, j;
    for(i = 0; i < rows1; i++)
    {
        for(j = 0; j < cols1; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    int j = 0, colsResult  = 0, rowsResult = 0, soma = 0;

    while(rowsResult < rows1)
    {
        while(colsResult < cols2)
        {
            for(j = 0; j < cols1; j++)
            {
                soma = soma + matrix1[rowsResult][j]*matrix2[j][colsResult];
            }

            result[rowsResult][colsResult] = soma;
            soma = 0;

            colsResult++;

        }

        colsResult = 0;

        rowsResult++;
        
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows])
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];  
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            matrix[i][j] = matrix[i][j] * scalar;
        }
    }
}
