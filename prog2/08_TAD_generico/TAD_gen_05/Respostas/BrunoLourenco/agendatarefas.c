#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendatarefas.h"

typedef void (**executa_tar)(void *);
typedef void (**destroi_tar)(void *);

struct agendatarefas
{
    void **tarefas;
    executa_tar exec;
    destroi_tar destr;
    int capacidade;
    int tam;
    int *prioridade;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas *CriaAgendaDeTarefas(int numElem)
{
    tAgendaTarefas *agenda = malloc(sizeof(tAgendaTarefas));
    agenda->tarefas = malloc(sizeof(void *) * numElem);
    agenda->exec = malloc(sizeof(void *) * numElem);
    agenda->destr = malloc(sizeof(void *) * numElem);
    agenda->prioridade = malloc(sizeof(int) * numElem);
    agenda->capacidade = numElem;
    agenda->tam = 0;

    return agenda;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas *tar)
{
    int i;
    for (i = 0; i < tar->tam; i++)
    {
        tar->destr[i](tar->tarefas[i]);
    }
    free(tar->destr);
    free(tar->exec);
    free(tar->prioridade);
    free(tar->tarefas);
    free(tar);
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa, void (*executa)(void *), void (*destroi)(void *))
{
    tar->tarefas[tar->tam] = tarefa;
    tar->destr[tar->tam] = destroi;
    tar->exec[tar->tam] = executa;
    tar->prioridade[tar->tam] = prioridade;
    tar->tam++;
}

void OrdenaTarefas(tAgendaTarefas *tar)
{
    for (int j = 0; j < tar->tam; j++)
    {
        for (int i = 0; i < tar->tam - 1; i++)
        {
            if (tar->prioridade[i] < tar->prioridade[i + 1])
            {
                // Trocar as coisas...
                int prioridadeAux;
                prioridadeAux = tar->prioridade[i];
                tar->prioridade[i] = tar->prioridade[i + 1];
                tar->prioridade[i + 1] = prioridadeAux;
                
                void *tarefaAux;
                tarefaAux = tar->tarefas[i];
                tar->tarefas[i] = tar->tarefas[i + 1];
                tar->tarefas[i + 1] = tarefaAux;

                void (*cb_dest_aux)(void *);
                cb_dest_aux = tar->destr[i];
                tar->destr[i] = tar->destr[i + 1];
                tar->destr[i + 1] = cb_dest_aux;

                void (*cb_exec_aux)(void *);
                cb_exec_aux = tar->exec[i];
                tar->exec[i] = tar->exec[i + 1];
                tar->exec[i + 1] = cb_exec_aux;
            }
        }
    }
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas *tar)
{
    OrdenaTarefas(tar);

    int i;
    for (i = 0; i < tar->tam; i++)
    {
        tar->exec[i](tar->tarefas[i]);
    }
}
