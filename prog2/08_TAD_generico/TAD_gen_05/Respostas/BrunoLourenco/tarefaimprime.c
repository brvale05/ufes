#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

struct impr
{
    char texto[100];
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg)
{
    tImpr *tarefa = malloc(sizeof(tImpr));
    if(!tarefa)
    {
        printf("erro ao alocar tarefaimpressao!\n");
        exit(0);
    }

    strcpy(tarefa->texto, msg);

    return tarefa;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp)
{
    printf("\n%s\n", ((tImpr*)imp)->texto);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp)
{
    if(imp)
    {
        free(imp);
    }
}