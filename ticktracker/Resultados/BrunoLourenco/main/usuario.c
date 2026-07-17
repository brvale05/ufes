#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

struct Usuario
{
    Ator *ator;
    char setor[MAX_TAM_SETOR];
    int qtdTickets;
};

Usuario *criaUsuario(Ator *ator, char *setor)
{
    Usuario *u = malloc(sizeof(Usuario));
    if (!u)
    {
        printf("erro ao alocar usuario!\n");
        exit(0);
    }

    u->ator = ator;
    strcpy(u->setor, setor);
    u->qtdTickets = 0;

    return u;
}

Usuario *leUsuario()
{

    Ator *a = leAtor();

    char setor[MAX_TAM_SETOR];

    scanf("%[^\n]", setor);
    scanf("%*c");

    Usuario *u = criaUsuario(a, setor);

    return u;
}

void imprimeUsuario(void *data)
{
    Usuario *u = (Usuario *)data;

    imprimeAtor(u->ator);
    printf("- Setor: %s\n", u->setor);
    printf("- Tickets solicitados: %d\n", u->qtdTickets);
}

void desalocaUsuario(void *data)
{
    if (((Usuario *)data))
    {
        desalocaAtor(((Usuario *)data)->ator);
        free(((Usuario *)data));
    }
}

int EhMesmoUsuario(Usuario *u1, Usuario *u2)
{
    return EhMesmoAtor(u1->ator, u2->ator);
}

char *getCPFUser(Usuario *u)
{
    return getCPFAtor(u->ator);
}

int comparaCPFUser(Usuario *u, char *cpf)
{
    return comparaCPFAtor(u->ator, cpf);
}

char *getSetorUser(Usuario *u)
{
    return u->setor;
}

char *getNomeUser(Usuario *u)
{
    return getNomeAtor(u->ator);
}

int CalculaIdadeUser(Usuario *u, Data *dtRef)
{
    return CalculaIdadeAtor(u->ator, dtRef);
}

void IncrementaTicketsUser(Usuario *u)
{
    u->qtdTickets++;
}

// Função que vai ser usado no qsort
int comparaUsuarios(const void *u1, const void *u2)
{

    if ((*(Usuario **)u1)->qtdTickets > (*(Usuario **)u2)->qtdTickets)
    {
        return -1;
    }
    else if ((*(Usuario **)u1)->qtdTickets < (*(Usuario **)u2)->qtdTickets)
    {
        return 1;
    }
    else
    {
        return strcmp(getNomeUser(*(Usuario **)u1), getNomeUser(*(Usuario **)u2));
    }
}

Usuario *CopiaUsers(Usuario *u1, Usuario *u2)
{
    u1 = malloc(sizeof(Usuario));

    u1->ator = CopiaAtor(u1->ator, u2->ator);

    strcpy(u1->setor, u2->setor);
    u1->qtdTickets = 0;

    return u1;
}

void CopiaQtdTickets(Usuario *u1, Usuario *u2)
{
    u1->qtdTickets = u2->qtdTickets;
}
