#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"

tEleitor* CriaEleitor()
{
    tEleitor *eleitor = malloc(sizeof(tEleitor));
    if(eleitor == NULL)
    {
        exit(0);
    }

    eleitor->id = -1;
    eleitor->votoG = -1;
    eleitor->votoP = -1;

    return eleitor;
}

void ApagaEleitor(tEleitor* eleitor)
{
    free(eleitor);
}

void LeEleitor(tEleitor *eleitor)
{
    scanf("%*[^0-9]");
    scanf("%d %d %d", &eleitor->id, &eleitor->votoP, &eleitor->votoG);
}

int ObtemVotoPresidente(tEleitor* eleitor)
{
    return eleitor->votoP;
}

int ObtemVotoGovernador(tEleitor* eleitor)
{
    return eleitor->votoG;
}

int EhMesmoEleitor(tEleitor* eleitor1, tEleitor* eleitor2)
{
    if(eleitor1->id == eleitor2->id)
    {
        return 1;
    }

    return 0;
}