#include <stdio.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos)
{
    if(*numEventos == MAX_EVENTOS)
    {
        printf("Limite de eventos atingido!\n");
    }
    else
    {
        scanf("%*[^\n]");
        scanf("%*c");

        scanf("%[^\n]", (eventos+*(numEventos))->nome);
        scanf("%*c");

        scanf("%d %d %d", &(eventos+*(numEventos))->dia, &(eventos+*(numEventos))->mes, &(eventos+*(numEventos))->ano);
        scanf("%*[^\n]");
        scanf("%*c");

        *numEventos++;

        printf("Evento cadastrado com sucesso!\n");
    }
}

void exibirEventos(Evento* eventos, int* numEventos)
{
    printf("Eventos cadastrados:\n");

    int i;
    for(i = 0; i < *numEventos; i++)
    {
        printf("%d - %s - %02d/%02d/%d\n", i, (eventos+i)->nome, (eventos+i)->dia, (eventos+i)->mes, (eventos+i)->ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos)
{
    scanf("%*[^\n]");
    scanf("%*c");

    int indice;

    scanf("%d\n", &indice);

    if(indice >= *numEventos)
    {
        printf("Indice invalido!\n");
    }
    else
    {
        scanf("%d %d %d", &(eventos+indice)->dia, &(eventos+indice)->mes, &(eventos+indice)->ano);
        scanf("%*[^\n]");
        scanf("%*c");
        printf("Data modificada com sucesso!\n");   
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
    Evento eventoAux;

    if(*indiceA >= *numEventos || *indiceB >= *numEventos)
    {
        printf("Indices invalido!\n");
    }
    else
    {
        eventoAux = *(eventos+(*indiceA));
        *(eventos+(*indiceA)) = *(eventos+(*indiceB));
        *(eventos+(*indiceB)) = eventoAux;
        printf("Eventos trocados com sucesso!\n");
    }
}