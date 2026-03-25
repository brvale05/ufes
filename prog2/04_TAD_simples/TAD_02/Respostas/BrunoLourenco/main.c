#include <stdio.h>
#include "eleicao.h"

tEleicao Conta_Votos(tEleicao eleicao, int voto, int tam, char cargo)
{
    int i;

    if(voto < 1)
    {
        if(cargo == 'P')
        {
            eleicao.votosBrancosPresidente++;
            return eleicao;
        }
        else
        {
            eleicao.votosBrancosGovernador++;
            return eleicao;
        }
    }

    for(i = 0; i < tam; i++)
    {
        if(eleicao.governadores[i].id == voto)
        {
            eleicao.governadores[i].votos++;
            return eleicao;
        }
    }

    if(cargo == 'P')
    {
        eleicao.votosNulosPresidente++;
        return eleicao;
    }
    else
    {
        eleicao.votosNulosGovernador++;
        return eleicao;
    }

}

int main()
{
    tEleicao eleicao;

    eleicao = InicializaEleicao();

    eleicao = RealizaEleicao(eleicao);

    if(eleicao.totalEleitores > 10 || eleicao.totalGovernadores > 3 || eleicao.totalPresidentes > 3)
    {
        printf("ELEICAO ANULADA\n");
        return 0;
    }

    int i, j;
    for(i = 0; i < eleicao.totalEleitores - 1; i++)
    {
        for(j = i + 1; j < eleicao.totalEleitores; j++)
        {
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j]))
            {
                printf("ELEICAO ANULADA\n");
                return 0;
            }
        }
    }


    for(i = 0; i < eleicao.totalEleitores; i++)
    {
        eleicao = Conta_Votos(eleicao, eleicao.eleitores[i].votoG, eleicao.totalGovernadores, 'G');
        eleicao = Conta_Votos(eleicao, eleicao.eleitores[i].votoP, eleicao.totalPresidentes, 'P');
    }


    return 0;

}