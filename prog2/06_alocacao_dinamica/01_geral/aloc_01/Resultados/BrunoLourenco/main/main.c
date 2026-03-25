#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
    int tam;
    scanf("%d", &tam);

    int *vet;

    vet = CriaVetor(tam);
    LeVetor(vet, tam);

    printf("%.2f", CalculaMedia(vet, tam));

    LiberaVetor(vet);

    return 0;
}