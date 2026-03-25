#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado); 

int main()
{
    int ncasos, c = 0;
    int X, TAM;

    scanf("%d\n", &ncasos);
    while(c < ncasos)
    {

        scanf("%d %d\n", &X, &TAM);
        int vet[TAM], i;

        for(i = 0; i < TAM; i++)
        {
            scanf("%d", &vet[i]);
        }

        printf("%d\n", ContaOcorrencias(vet, TAM, X));

        c++;

    }

    return 0;

}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado)
{
    int i, soma = 0;

    if(numElementos < 0)
    {
        return 0;
    }

    for(i = numElementos; i >= 0; i--)
    {
        if(vet[i] == numeroProcurado)
        {
            soma++;
            return soma + ContaOcorrencias(vet, numElementos - 1, numeroProcurado);
        }
        else 
        {
            return ContaOcorrencias(vet, numElementos - 1, numeroProcurado);
        }
    }
}