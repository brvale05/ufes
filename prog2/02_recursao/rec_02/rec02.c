#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos); 

int main()
{
    int qtd_vetores;
    scanf("%d\n", &qtd_vetores);

    int q = 0, TAM;
    while(q < qtd_vetores)
    {
        scanf("%d\n", &TAM);

        int vet[TAM], i;
        for(i = 0; i < TAM; i++)
        {
            scanf("%d", &vet[i]);
        }

        int soma = 0;
        soma = SomaElementosPares(vet, TAM - 1);
        printf("%d\n", soma);

        q++;
    }

    return 0;

}

int SomaElementosPares(int* vet, int numElementos)
{
    int tam = numElementos;

    if(tam < 0)
    {
        return 0;
    }


    int i, soma;

    for(i = tam; i >= 0; i--)
    {

        if(vet[i]%2 == 0)
        {   
            return vet[i] + SomaElementosPares(vet, tam - 1);
        } else
        {
            return SomaElementosPares(vet, tam - 1);
        }
    }

}