#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "software.h"

/**
 * Estrutura de um Ticket Software contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
struct Software
{
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    int impacto;
    char motivo[MAX_TAM_MOTIVO];
    int duracao;
};

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo)
{
    Software *soft = malloc(sizeof(Software));
    if (!soft)
    {
        printf("erro ao alocar software!\n");
        exit(0);
    }

    strcpy(soft->nome, nome);
    strcpy(soft->categoria, categoria);
    soft->impacto = impacto;
    strcpy(soft->motivo, motivo);
    soft->duracao = 0;

    return soft;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Software *lerSoftware()
{
    char nome[100], cat[100], mot[100];
    int impac;

    scanf("%[^\n]", nome);
    scanf("%*c");

    scanf("%[^\n]", cat);
    scanf("%*c");

    scanf("%d", &impac);
    scanf("%*[^\n]");
    scanf("%*c");

    scanf("%[^\n]", mot);
    scanf("%*c");

    Software *soft = criaSoftware(nome, cat, impac, mot);

    return soft;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s)
{
    if (!strcmp(s->categoria, "BUG"))
    {
        s->duracao = TEMPO_ESTIMADO_BUG + s->impacto;
    }
    else if (!strcmp(s->categoria, "OUTROS"))
    {
        s->duracao = TEMPO_ESTIMADO_OUTROS + s->impacto;
    }
    else if (!strcmp(s->categoria, "DUVIDA"))
    {
        s->duracao = TEMPO_ESTIMADO_DUVIDA + s->impacto;
    }
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado)
{
    return ((Software *)dado)->duracao;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware()
{
    return 'S';
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s)
{
    if ((Software *)s)
    {
        free((Software *)s);
    }
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaSoftware(void *dado)
{
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n", ((Software *)dado)->nome);
    printf("- Categoria: %s\n", ((Software *)dado)->categoria);
    printf("- Nível do impacto: %d\n", ((Software *)dado)->impacto);
    printf("- Motivo: %s\n", ((Software *)dado)->motivo);
    printf("- Tempo estimado: %dh\n", ((Software *)dado)->duracao);
}
