#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"
#include <string.h>

tCandidato* CriaCandidato()
{
    tCandidato *cand = malloc(sizeof(tCandidato));
    
    cand->nome = NULL;
    cand->partido = NULL;
    cand->id = -1;
    cand->votos = -1;

    return cand;
}

void ApagaCandidato(tCandidato* candidato)
{
    free(candidato->nome);
    free(candidato->partido);
    free(candidato);
}

void LeCandidato(tCandidato *candidato)
{
    scanf("%*[^A-Za-z]");

    char buffer[100];

    scanf("%[^,]", buffer);
    scanf("%*[^A-Za-z]");

    candidato->nome = malloc(sizeof(char) * (strlen(buffer) + 1));
    if(candidato->nome == NULL)
    {
        exit(0);
    }
    strcpy(candidato->nome, buffer);

    scanf("%[^,]", buffer);
    scanf("%*[^A-Za-z]");

    candidato->partido = malloc(sizeof(char) * (strlen(buffer) + 1));
    if(candidato->partido == NULL)
    {
        exit(0);
    }
    strcpy(candidato->partido, buffer);

    scanf("%c", &candidato->cargo);
    scanf("%*[^0-9]");
    scanf("%d", &candidato->id);
    
    candidato->votos = 0;
    
}

int VerificaIdCandidato(tCandidato *candidato, int id)
{
    if(candidato->id == id)
    return 1;

    return 0;
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2)
{
    if(candidato1->id == candidato2->id)
    {
        return 1;
    }
    return 0; 
}

char ObtemCargo(tCandidato* candidato)
{
    return candidato->cargo;
}

void IncrementaVotoCandidato(tCandidato* candidato)
{
    candidato->votos++;
}

int ObtemVotos(tCandidato* candidato)
{
    return candidato->votos;
}

float CalculaPercentualVotos(tCandidato* candidato, int totalVotos)
{
    float votos = ObtemVotos(candidato);
    float total = totalVotos;

    return (votos/total)*100;
}

void ImprimeCandidato (tCandidato* candidato, float percentualVotos)
{
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato->nome, candidato->partido, ObtemVotos(candidato), percentualVotos);   
}