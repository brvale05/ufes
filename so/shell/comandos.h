#ifndef COMANDO_H
#define COMANDO_H

#include "sig.h"
#include <sys/types.h>
#include <unistd.h>

/**
 * @brief Executa um comando externo simples.
 * @param args Vetor de argumentos terminados em NULL.
 * @param buffer Ponteiro para o buffer de comandos.
 * @param pgid_lider Ponteiro para o ID do líder do grupo.
 */
void exec_comando_externo(char **args, char **buffer, pid_t *pgid_lider);

/**
 * @brief Executa dois comandos conectados por um PIPE. Cria dois processos filhos. Ambos são colocados no mesmo grupo de processos.
 * @param args Vetor de argumentos terminados em NULL.
 * @param pipe_indice O índice no vetor 'args' onde começa o segundo comando (pós-pipe).
 * @param buffer Ponteiro para o buffer de comandos.
 * @param pgid_lider Ponteiro para o ID do líder do grupo.
 */
void exec_comando_pipe(char **args, int pipe_indice, char **buffer, pid_t *pgid_lider);

/**
 * @brief Processa e executa todos os comandos armazenados no buffer.
 * @param buffer Vetor de strings contendo as linhas de comando.
 * @param tam Ponteiro para o tamanho atual do buffer.
 * @param args Vetor auxiliar alocado para manipulação dos tokens.
 */
void exec_buffer(char **buffer, int *tam, char **args);

#endif