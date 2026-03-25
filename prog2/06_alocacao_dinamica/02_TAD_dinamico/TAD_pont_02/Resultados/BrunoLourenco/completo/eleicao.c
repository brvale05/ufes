#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

tEleicao *InicializaEleicao()
{
    tEleicao *eleicao = malloc(sizeof(tEleicao));

    eleicao->eleitores = NULL;

    eleicao->totalPresidentes = 0;
    eleicao->totalEleitores = 0;
    eleicao->totalGovernadores = 0;

    eleicao->votosBrancosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosNulosPresidente = 0;

    tCandidato *candidatoLido = CriaCandidato();

    int qtdCandidatos, c = 0;
    scanf("%d", &qtdCandidatos);

    eleicao->presidentes = malloc(qtdCandidatos * sizeof(tCandidato *));
    eleicao->governadores = malloc(qtdCandidatos * sizeof(tCandidato *));

    while (c < qtdCandidatos)
    {
        LeCandidato(candidatoLido);

        if (ObtemCargo(candidatoLido) == 'P')
        {
            eleicao->presidentes[eleicao->totalPresidentes] = CriaCandidato();
            *eleicao->presidentes[eleicao->totalPresidentes] = *candidatoLido;
            eleicao->totalPresidentes++;
        }
        else
        {
            eleicao->governadores[eleicao->totalGovernadores] = CriaCandidato();
            *eleicao->governadores[eleicao->totalGovernadores] = *candidatoLido;
            eleicao->totalGovernadores++;
        }

        c++;
    }

    free(candidatoLido);

    return eleicao;

}

void ApagaEleicao(tEleicao *eleicao)
{
    int i;

    if (eleicao)
    {
        if (eleicao->governadores)
        {
            for (i = 0; i < (eleicao->totalGovernadores); i++)
            {
                if (eleicao->governadores[i])
                {
                    ApagaCandidato(eleicao->governadores[i]);
                }
            }
            free(eleicao->governadores);
        }

        if (eleicao->presidentes)
        {
            for (i = 0; i < eleicao->totalPresidentes; i++)
            {
                if (eleicao->presidentes[i])
                {
                    ApagaCandidato(eleicao->presidentes[i]);
                }
            }
            free(eleicao->presidentes);
        }

        if (eleicao->eleitores)
        {
            for (i = 0; i < eleicao->totalEleitores; i++)
            {
                if (eleicao->eleitores[i])
                {
                    ApagaEleitor(eleicao->eleitores[i]);
                }
            }
            free(eleicao->eleitores);
        }

        free(eleicao);
    }
}

void RealizaEleicao(tEleicao *eleicao)
{
    int E = 0, i, j;
    scanf("%d", &eleicao->totalEleitores);

    eleicao->eleitores = malloc(sizeof(tEleitor *) * eleicao->totalEleitores);

    while (E < eleicao->totalEleitores)
    {
        eleicao->eleitores[E] = CriaEleitor();
        LeEleitor(eleicao->eleitores[E]);
        E++;
    }

    int flagNulo = 0;

    // apura votos nulos, normais e brancos presidente
    for (i = 0; i < eleicao->totalEleitores; i++)
    {
        for (j = 0; j < eleicao->totalPresidentes; j++)
        {
            if (VerificaIdCandidato(eleicao->presidentes[j], ObtemVotoPresidente(eleicao->eleitores[i])))
            {
                IncrementaVotoCandidato(eleicao->presidentes[j]);
                flagNulo++;
                break;
            }
        }

        if (ObtemVotoPresidente(eleicao->eleitores[i]) < 1)
        {
            eleicao->votosBrancosPresidente++;
        }
        else if (!flagNulo)
        {
            eleicao->votosNulosPresidente++;
        }

        flagNulo = 0;
    }

    // apura votos nulos, normais e brancos governador
    for (i = 0; i < eleicao->totalEleitores; i++)
    {
        for (j = 0; j < eleicao->totalGovernadores; j++)
        {
            if (VerificaIdCandidato(eleicao->governadores[j], ObtemVotoGovernador(eleicao->eleitores[i])))
            {
                IncrementaVotoCandidato(eleicao->governadores[j]);
                flagNulo++;
                break;
            }
        }

        if (ObtemVotoGovernador(eleicao->eleitores[i]) < 1)
        {
            eleicao->votosBrancosGovernador++;
        }
        else if (!flagNulo)
        {
            eleicao->votosNulosGovernador++;
        }

        flagNulo = 0;
    }
}

int AchaMaior(tCandidato **candidato, int qtdCandidatos)
{
    int maior, idMaior, i;
    for (i = 0; i < qtdCandidatos; i++)
    {
        if (!i)
        {
            maior = candidato[i]->votos;
            idMaior = i;
        }

        if (candidato[i]->votos > maior)
        {
            maior = candidato[i]->votos;
            idMaior = i;
        }
    }

    for (i = 0; i < qtdCandidatos; i++)
    {
        if (candidato[i]->votos == maior)
        {
            if (i != idMaior)
            {
                return -1;
            }
        }
    }

    return idMaior;
}

int HouveEmpate(tCandidato **candidato, int qtdCandidatos)
{
    if (AchaMaior(candidato, qtdCandidatos) < 0)
    {
        return 1;
    }
    return 0;
}

void ApuraVotos(tEleicao *eleicao, int id, char cargo)
{
    int votosInvalidos;

    if (cargo == 'P')
    {
        votosInvalidos = eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente;
        if (votosInvalidos > eleicao->presidentes[id]->votos)
        {
            printf("SEM DECISAO\n");
        }
        else
        {
            ImprimeCandidato(eleicao->presidentes[id], CalculaPercentualVotos(eleicao->presidentes[id], eleicao->totalEleitores));
        }
    }
    else
    {
        votosInvalidos = eleicao->votosBrancosGovernador + eleicao->votosNulosGovernador;
        if (votosInvalidos > eleicao->governadores[id]->votos)
        {
            printf("SEM DECISAO\n");
        }
        else
        {
            ImprimeCandidato(eleicao->governadores[id], CalculaPercentualVotos(eleicao->governadores[id], eleicao->totalEleitores));
        }
    }
}

void ImprimeResultadoEleicao(tEleicao *eleicao)
{
    int i, j, idMaisVotos;

    for (i = 0; i < eleicao->totalEleitores - 1; i++)
    {
        for (j = i + 1; j < eleicao->totalEleitores; j++)
        {
            if (EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j]))
            {
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }

    printf("- PRESIDENTE ELEITO: ");

    if (HouveEmpate(eleicao->presidentes, eleicao->totalPresidentes))
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else
    {
        idMaisVotos = AchaMaior(eleicao->presidentes, eleicao->totalPresidentes);
        ApuraVotos(eleicao, idMaisVotos, 'P');
    }

    printf("- GOVERNADOR ELEITO: ");

    if (HouveEmpate(eleicao->governadores, eleicao->totalGovernadores))
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else
    {
        idMaisVotos = AchaMaior(eleicao->governadores, eleicao->totalGovernadores);
        ApuraVotos(eleicao, idMaisVotos, 'G');
    }

    printf("- NULOS E BRANCOS: %d, %d\n", eleicao->votosNulosGovernador + eleicao->votosNulosPresidente, eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente);

}