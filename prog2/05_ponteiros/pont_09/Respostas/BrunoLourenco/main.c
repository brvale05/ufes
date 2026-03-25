#include <stdio.h>
#include "pessoa.h"

int main()
{
    int qtd_prs;

    scanf("%d", &qtd_prs);

    int p = 0;

    tPessoa pessoas[qtd_prs];

    for(p = 0; p < qtd_prs; p++)
    {
        *(pessoas+p) = CriaPessoa();
    }

    for(p = 0; p < qtd_prs; p++)
    {
        LePessoa(pessoas+p);
    }

    AssociaFamiliasGruposPessoas(pessoas);

    for(p = 0; p < qtd_prs; p++)
    {
        ImprimePessoa(pessoas+p);
    }

    return 0;

}