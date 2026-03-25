#ifndef _OUTROS_H
#define _OUTROS_H

#define MAX_TAM_DESC_OUTROS 500
#define MAX_TAM_LOCAL_OUTROS 100

typedef struct Outros Outros;

Outros *criaOutros(char *descricao, char *local, int dificuldade);

Outros *lerOutros();

int getTempoEstimadoOutros(void *dado);

char getTipoOutros();

void desalocaOutros(void *o);

void notificaOutros(void *dado);

#endif