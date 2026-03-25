#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefasoma.h"

struct soma
{
    float x;
    float y;
};

/**
 * @brief Cria uma tarefa do tipo soma de dois números
 * 
 * @param n1 - Primeiro número que será somado quando a tarefa for executada
 * @param n2 - Segundo número que será somado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tSoma* CriaTarefaSoma(float n1, float n2)
{
    tSoma *soma = malloc(sizeof(tSoma));

    soma->x = n1;
    soma->y = n2;

    return soma;
}


/**
 * @brief Função que executa uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaSoma(void *sum)
{
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f\n",((tSoma*)sum)->x, ((tSoma*)sum)->y, ((tSoma*)sum)->x + ((tSoma*)sum)->y);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaSoma(void *sum)
{
    if(sum)
    {
        free(sum);
    }
}