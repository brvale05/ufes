
#include "ator.h"

#ifndef _USUARIO_H
#define _USUARIO_H

#define MAX_TAM_SETOR 15

typedef struct Usuario Usuario;

Usuario *criaUsuario(Ator *ator, char *setor);

Usuario *leUsuario();

void imprimeUsuario(void *data);

void desalocaUsuario(void *data);

int EhMesmoUsuario(Usuario *u1, Usuario *u2);

char *getCPFUser(Usuario *u);

int comparaCPFUser(Usuario *u, char *cpf);

char *getSetorUser(Usuario *u);

char *getNomeUser(Usuario *u);

int CalculaIdadeUser(Usuario *u, Data *dtRef);

void IncrementaTicketsUser(Usuario *u);

int comparaUsuarios(const void *u1, const void *u2);

Usuario *CopiaUsers(Usuario *u1, Usuario *u2);

void CopiaQtdTickets(Usuario *u1, Usuario *u2);

#endif
