#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

int main(int argc, char **argv)
{
    tBanco *banco = CriaBanco();
    LeBanco(banco);

    tAgencia *agencia; tConta *conta;

    char car;
    while(1)
    {
        scanf("%c", &car);

        if(car == 'A')
        {
            agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }
        else
        if(car == 'C')
        {
            conta = CriaConta();
            LeConta(conta);
            int numAgencia;
            scanf("%d\n", &numAgencia);
            InsereContaBanco(banco, numAgencia, conta);
        }
        else
        if(car == 'F')
        {
            break;
        }
    }

    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;

}