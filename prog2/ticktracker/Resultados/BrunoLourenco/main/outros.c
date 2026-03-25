#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outros.h"

struct Outros
{
    char descricao[MAX_TAM_DESC_OUTROS];
    char local[MAX_TAM_LOCAL_OUTROS];
    int dificuldade;
    int tempoEstimado;
};

Outros *criaOutros(char *descricao, char *local, int dificuldade)
{
    Outros* o = (Outros*)malloc(sizeof(Outros));

    strcpy(o->descricao, descricao);
    strcpy(o->local, local);
    o->dificuldade = dificuldade;
    o->tempoEstimado = dificuldade;

    return o;
}

Outros *lerOutros()
{
    char desc[MAX_TAM_DESC_OUTROS], local[MAX_TAM_LOCAL_OUTROS];
    int dificuldade;

    scanf("%[^\n]", desc);
    scanf("%*c");

    scanf("%[^\n]", local);
    scanf("%*c");

    scanf("%d", &dificuldade);
    scanf("%*[^\n]");
    scanf("%*c");

    Outros *o = criaOutros(desc, local, dificuldade);

    return o;
}

int getTempoEstimadoOutros(void *dado)
{
    Outros* o = (Outros*)dado;
    return o->tempoEstimado;
}

char getTipoOutros()
{
    return 'O';
}

void desalocaOutros(void *o)
{
    if (o)
    {
        free(o);
    }
    o = NULL;
}

void notificaOutros(void *dado)
{
    Outros* o = (Outros*)dado;

    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n", o->descricao);
    printf("- Local: %s\n", o->local);
    printf("- Nivel de Dificuldade: %d\n", o->dificuldade);
    printf("- Tempo Estimado: %dh\n", getTempoEstimadoOutros(dado));
}