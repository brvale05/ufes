#include "candidato.h"
#include <stdio.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato;
    int i;

    for(i = 0; nome[i] != '\0'; i++)
    {
        candidato.nome[i] = nome[i];
    }
    for(i = 0; partido[i] != '\0'; i++)
    {
        candidato.partido[i] = partido[i];
    }

    candidato.cargo = cargo;
    candidato.id = id;

    return candidato;

}

tCandidato LeCandidato()
{
    char nome[50];
    char partido[50];
    char cargo;
    int id;

    scanf("%[^,]", nome);
    scanf(", ");
    scanf("%[^,]", partido);
    scanf(", ");
    scanf("%c", &cargo);
    scanf(", ");
    scanf("%d", &id);
    scanf("\n");

    tCandidato candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;

}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    if(candidato.id == id) return 1;

    return 0;

}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    if(candidato1.id == candidato2.id) return 1;

    return 0;

}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;

    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    return ((float)candidato.votos/totalVotos)*100;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos)
{
    printf("%s (%s), %d voto(s), %.2f%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}