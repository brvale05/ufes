#ifndef BUILTIN_H
#define BUILTIN_H

/**
 * @brief Altera o diretório atual de trabalho da shell (comando cd).
 * @param args Vetor de strings onde args[1] contém o caminho destino.
 */
void executa_cd(char **args);

/**
 * @brief Aguarda a finalização de processos filhos (comando wait).
 * Limpa processos zumbis e imprime o status de saída dos filhos terminados.
 */
void executa_wait();

/**
 * @brief Termina a execução da shell (comando exit).
 * * Realiza a limpeza de memória pendente antes de encerrar o programa.
 * Limpa processos zumbis antes de sair.
 * @param args Vetor de argumentos.
 * @param buffer O buffer de comandos atual para ser liberado antes do exit.
 */
void executa_exit(char **args, char **buffer);

/**
 * @brief Identifica qual comando interno foi chamado e executa a função correspondente.
 * @param args Vetor de argumentos contendo o comando e seus parâmetros.
 * @param buffer O buffer de comandos.
 */
void exec_builtin(char **args, char **buffer);

/**
 * @brief Verifica se um comando é interno (built-in).
 * @param args Vetor de argumentos.
 * @return int Retorna 1 se for builtin (cd, wait, exit), ou 0 caso contrário.
 */
int eh_builtin(char **args);

#endif