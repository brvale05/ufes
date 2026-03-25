#include <stdio.h>
#include "pessoa.h"

tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;

    return pessoa;
}

void LePessoa(tPessoa *pessoa)
{
    scanf("%*[^\n]");
    scanf("%*c");
    scanf("%[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if((pessoa->mae != NULL) || (pessoa->pai != NULL)) {
        return 1;
    } else {
        return 0;
    }
}

void ImprimePessoa(tPessoa *pessoa)
{
    if(VerificaSeTemPaisPessoa(pessoa) > 0)
    {
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai == NULL)
        {
            printf("PAI: NAO INFORMADO\n");
        }
        else
        {
            printf("PAI: %s\n", pessoa->pai->nome);
        }

        if(pessoa->mae == NULL)
        {
            printf("MAE: NAO INFORMADO\n");
        }
        else
        {
            printf("MAE: %s\n", pessoa->mae->nome);
        }
        
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int mae, pai, filho, qtdAssociacoes, i;
    
    scanf("%d", &qtdAssociacoes);

    for(i = 0; i < qtdAssociacoes; i++) 
    {
        scanf("%*[^:]");
        scanf(":");
        scanf(" ");
        scanf("%d", &mae);
        scanf("%*[^:]");
        scanf(":");
        scanf(" ");
        scanf("%d", &pai);
        scanf("%*[^:]");
        scanf(":");
        scanf(" ");
        scanf("%d", &filho);
        scanf("%*[^\n]");
        scanf("%*c");

        if(pai > -1) {
            (pessoas+filho)->pai = (pessoas+pai);
        }
        if(mae > -1) {
            (pessoas+filho)->mae = (pessoas+mae);
        }
    }


}

