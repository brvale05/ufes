#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

#define TAM_NOME_MANUT 100
#define TAM_LOCAL_MANUTENCAO 100
#define TAM_ESTADO 11
#define TEMPO_ESTIMADO_RUIM 3
#define TEMPO_ESTIMADO_REGULAR 2
#define TEMPO_ESTIMADO_BOM 1
#define TEMPO_ESTIMADO_RH 2
#define TEMPO_ESTIMADO_FINANCEIRO 3
#define TEMPO_ESTIMADO_OUTROS_SETORES 1


/**
 * Estrutura de um Ticket Manutencao contendo os parametros especificos de um ticket do tipo Manutencao
 */
typedef struct Manutencao Manutencao;


Manutencao *criaManutencao(char *nome, char *estado, char *local);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao();

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da categoria e impacto
 * @param m  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *m, char *setor);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao();

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param m  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *m);

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado);

#endif