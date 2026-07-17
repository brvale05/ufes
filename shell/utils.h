#ifndef UTILS_H
#define UTILS_H

// Definições de limites
#define TAM_MAX_LINE 1000   ///< Tamanho máximo de caracteres por linha
#define TAM_MAX_BUFFER 5    ///< Capacidade máxima do buffer de comandos
#define ARG_MAX 10          ///< Número máximo de argumentos por comando 

/**
 * @brief Lê uma linha da entrada padrão.
 * * Utiliza fgets para leitura segura e remove o caractere '\n' final.
 * * @return char* Ponteiro para a string alocada dinamicamente (deve ser liberada com free),
 * ou NULL em caso de erro/EOF.
 */
char *read_line();

/**
 * @brief Tokeniza uma string em um vetor de argumentos.
 * * Separa a string por espaços e detecta o caractere especial "#" (usado como pipe).
 * * @param line A string contendo o comando completo.
 * @param args O vetor de strings onde os tokens serão armazenados.
 * @return int Retorna o índice do token após o pipe se houver "#", ou 0 se for comando simples.
 */
int split_line(char *line, char **args);

/**
 * @brief Libera a memória de vetores de strings.
 * * Percorre e libera cada string individualmente e depois o vetor principal.
 * Útil para limpar 'buffer' e 'args'.
 * @param args O vetor de argumentos.
 * @param buffer Buffer de comandos.
 */
void libera_mem(char **args, char **buffer);

#endif