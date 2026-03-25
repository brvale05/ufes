#ifndef SIG_H
#define SIG_H

#include <signal.h>

// Apenas a DECLARAÇÃO (promessa de existência).
// EXTERN: garante que o compilador nao aloque memoria para essa variavel aqui
// VOLATILE: aparentemente tem a ver com o funcionamento do compilador (nao sei se eh verdade) mas deixei por questoes de seguranca. Força a leitura dessa variavel diretamente da memoria principal e impede que o compilador cacheie o valor da variavel em um registrador e assuma que ele não mudou.
// SIG_ATOMIC_T: garante a ATOMICIDADE da operacao, ou ela ocorre, ou nao
extern volatile sig_atomic_t ctrlc_recebido;
extern volatile sig_atomic_t qtdfilhos_vivos;

/**
 * @brief Handler para o sinal SIGINT (Ctrl+C). Apenas altera o estado da flag ctrlc_recebido para 1.
 * @param sig O número do sinal recebido.
 */
void handle_sigint(int sig);

/**
 * @brief Handler para o sinal SIGCHLD. Decrementa o contador de filhos vivos.
 * @param sig O número do sinal recebido.
 */
void handle_sigchld(int sig);

/**
 * @brief Configura as ações para os sinais do sistema.
 * * Define os handlers para SIGINT e SIGCHLD, bem como as Flags
 */
void config_sigaction();

/**
 * @brief Gerencia a lógica de confirmação de saída.
 * @return int Retorna 1 se o usuário confirmou a saída, 0 caso contrário.
 */
int confirma_saida();

#endif