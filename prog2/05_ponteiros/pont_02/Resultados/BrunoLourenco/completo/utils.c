#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n)
{
    scanf("%d %d", m, n);
}

int EhPrimo(int n)
{
    int i, qtdDivisores = 0;

    if(n == 1)
    return 0;

    for(i = 1; i <= n; i++)
    {
        if(n%i < 1)
        {
            qtdDivisores++;
        }

        if(qtdDivisores > 2)
        return 0;
    }

    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{
    *maior = m; 
    *menor = n;

    int i;

    for(i = m; i <= n; i++)
    {
        if(EhPrimo(i))
        {
            if(i > *maior)
            {
                *maior = i;
            }
            
            if(i < *menor)
            {
                *menor = i;
            }
        }
    }
}