
#include "ator.h"
#include "ticket.h"

#ifndef _TECNICO_H
#define _TECNICO_H

#define MAX_TAM_AREA 10

typedef struct Tecnico Tecnico;

Tecnico *criaTecnico(Ator *ator, char *area, int disponibilidade, float salario);

Tecnico *leTecnico();

void imprimeTecnico(void *t);

void desalocaTecnico(void *t);

int EhMesmoTecnico(Tecnico *t1, Tecnico *t2);

int getTempoTrabalhado(Tecnico *t);

int getDisponibilidade(Tecnico *t);

int CalculaIdadeTec(Tecnico *t, Data *dtRef);

char *getAreaAtuacao(Tecnico *t);

char *getNomeTecnico(Tecnico *t);

int comparaTecnicos(const void *t1, const void *t2);

void AlteraHorasTecnico(Tecnico *t, int horas);

Tecnico *CopiaTecnicos(Tecnico *t1, Tecnico *t2);

void CopiaHorasTrabalhadas(Tecnico *t1, Tecnico *t2);

#endif
