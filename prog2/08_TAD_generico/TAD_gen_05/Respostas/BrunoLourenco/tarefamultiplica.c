#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefamultiplica.h"

struct mult
{
    float x;
    float y;
};

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2)
{
    tMult *m = malloc(sizeof(tMult));

    m->x = n1;
    m->y = n2;

    return m;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult)
{
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f\n", ((tMult*)mult)->x,((tMult*)mult)->y, ((tMult*)mult)->x*((tMult*)mult)->y);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult)
{
    if(mult)
    {
        free(mult);
    }
}