#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(int argc, char *agrv[])
{
    int type, tam;

    printf("tad_gen_01\n");

    printf("Digite o tipo e numero de elementos:\n");

    scanf("%d %d", &type, &tam);
    scanf("%*[0-9]");

    tGeneric *gen = CriaGenerico(type, tam);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;

}