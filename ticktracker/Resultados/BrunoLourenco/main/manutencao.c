#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "manutencao.h"


struct Manutencao
{
    char nome[TAM_NOME_MANUT];
    char estado[TAM_ESTADO];
    char local[TAM_LOCAL_MANUTENCAO];
    int duracao;
};

Manutencao *criaManutencao(char *nome, char *estado, char *local)
{
    Manutencao *m = malloc(sizeof(Manutencao));
    if(!m)
    {
        printf("erro ao alocar manutencao!\n");
        exit(0);
    }

    strcpy(m->nome, nome);
    strcpy(m->estado, estado);
    strcpy(m->local, local);
    m->duracao = 0;

    return m;

}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao()
{
    char nome[TAM_NOME_MANUT], estado[TAM_ESTADO], local[TAM_LOCAL_MANUTENCAO];

    scanf("%[^\n]", nome);
    scanf("%*c");

    scanf("%[^\n]", estado);
    scanf("%*c");

    scanf("%[^\n]", local);
    scanf("%*c");

    Manutencao *m = criaManutencao(nome, estado, local);

    return m;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da categoria e impacto
 * @param m  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *m, char *setor)
{
    if(!strcmp(m->estado, "RUIM"))
    {
        if(!strcmp(setor, "RH"))
        {
            m->duracao = TEMPO_ESTIMADO_RH*TEMPO_ESTIMADO_RUIM;
        }
        else
        if(!strcmp(setor, "FINANCEIRO"))
        {
            m->duracao = TEMPO_ESTIMADO_FINANCEIRO*TEMPO_ESTIMADO_RUIM;
        }
        else
        {
            m->duracao = TEMPO_ESTIMADO_OUTROS_SETORES*TEMPO_ESTIMADO_RUIM;
        }
    }
    else
    if(!strcmp(m->estado, "REGULAR"))
    {
        if(!strcmp(setor, "RH"))
        {
            m->duracao = TEMPO_ESTIMADO_RH*TEMPO_ESTIMADO_REGULAR;
        }
        else
        if(!strcmp(setor, "FINANCEIRO"))
        {
            m->duracao = TEMPO_ESTIMADO_FINANCEIRO*TEMPO_ESTIMADO_REGULAR;
        }
        else
        {
            m->duracao = TEMPO_ESTIMADO_OUTROS_SETORES*TEMPO_ESTIMADO_REGULAR;
        }
    }
    else
    if(!strcmp(m->estado, "BOM"))
    {
        if(!strcmp(setor, "RH"))
        {
            m->duracao = TEMPO_ESTIMADO_RH*TEMPO_ESTIMADO_BOM;
        }
        else
        if(!strcmp(setor, "FINANCEIRO"))
        {
            m->duracao = TEMPO_ESTIMADO_FINANCEIRO*TEMPO_ESTIMADO_BOM;
        }
        else
        {
            m->duracao = TEMPO_ESTIMADO_OUTROS_SETORES*TEMPO_ESTIMADO_BOM;
        }
    }
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado)
{
    return ((Manutencao*)dado)->duracao;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao()
{
    return 'M';
}

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param m  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *m)
{
    if(((Manutencao*)m))
    {
        free(((Manutencao*)m));
    }
}

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado)
{
    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n", ((Manutencao *)dado)->nome);
    printf("- Estado de conservacao: %s\n", ((Manutencao *)dado)->estado);
    printf("- Local: %s\n", ((Manutencao *)dado)->local);
    printf("- Tempo estimado: %dh\n", ((Manutencao *)dado)->duracao);
}