#include <stdio.h>
#include "data.h"

int main()
{
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if(verificaDataValida(dia, mes, ano) < 1)
    {
        printf("A data informada eh invalida\n");
        return 0;
    }

    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);

    if(verificaBissexto(ano) > 0)
    {
        printf("O ano informado eh bissexto\n");
    }
    else
    {
        printf("O ano informado nao eh bissexto\n");
    }

    printf("O mes informado possui %02d dias\n", numeroDiasMes(mes, ano));

    printf("A data seguinte eh: ");

    imprimeProximaData(dia, mes, ano);

    return 0;

}