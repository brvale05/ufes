#include "eleicao.h"
#include <stdio.h>

tEleicao InicializaEleicao()
{
    int totalCandidatos;

    scanf("%d", totalCandidatos);
    scanf("%*[^\n]");
    scanf("%*c");

    tEleicao eleicao;
    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.totalEleitores = 0;

    int c = 0;

    int P = 0, G = 0;

    tCandidato candidato;

    while(c < totalCandidatos)
    {

        candidato = LeCandidato();

        if(candidato.cargo == 'P')
        {
            eleicao.presidentes[P] = candidato;
            P++;
            eleicao.totalPresidentes++;
        }
        else
        if(candidato.cargo == 'G')
        {
            eleicao.governadores[G] = candidato;
            G++;
            eleicao.totalGovernadores++;
        }

        c++;

    }

    return eleicao;

}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    int totalEleitores;

    scanf("%d", &totalEleitores);
    scanf("%*[^\n]");
    scanf("%*c");

    eleicao.totalEleitores = totalEleitores;

    tEleitor eleitor;

    int e = 0;
    while(e < totalEleitores)
    {
        eleitor = LeEleitor();

        eleicao.eleitores[e] = eleitor;

        e++;

    }

    return eleicao;

}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    int g, aux = 0;

    int idmaior = eleicao.governadores[0].id;
    int maiorVoto = eleicao.governadores[0].votos;

    for(g = 0; g < eleicao.totalGovernadores; g++)
    {
        if(eleicao.governadores[g].votos > maiorVoto)
        {
            maiorVoto = eleicao.governadores[g].votos;
            idmaior = eleicao.governadores[g].id;
        }
    }

    for(g = 0; g < eleicao.totalGovernadores; g++)
    {
        if(eleicao.governadores[g].votos == maiorVoto && eleicao.governadores[g].id != idmaior)
        {
            printf("SEM DECISAO\n");
            aux++;
            break;
        }
    }

}