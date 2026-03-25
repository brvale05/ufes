#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

void imprimeMenu();

int main ()
{
    printf("tad_gen_02\n\n");
    
    int tipo, op, qtd, idx = 0;
    tGerenciador* geren = CriaGerenciador();
    tPacote* pac = NULL;

    while (1)
    {
        imprimeMenu();
        scanf("%*[^0-9]");
        scanf("%d", &op); 

        if(op == 1)
        {
            printf("\nDigite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d", &tipo, &qtd);

            if(tipo == 0)
            {
                pac = CriaPacote(CHAR, qtd);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(geren, pac);
            }
            else
            if(tipo == 1)
            {
                pac = CriaPacote(INT, qtd);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(geren, pac);
            }
            else
            {
                printf("\nDigite um tipo valido!");
            }
        }
        else
        if(op == 2)
        {
            scanf("%d\n", &idx);
            ImprimirPacoteNoIndice(geren, idx);
        }
        else
        if(op == 3)
        {
            printf("\n");
            ImprimirTodosPacotes(geren);
            break;
        }
        else
        {
            printf("\nEscolha uma opcao valida para o menu!");
        }
    }

    DestroiGerenciador(geren);
    

    return 0;
}

void imprimeMenu()
{
    printf("\nEscolha uma opcao:\n\t(1) Cadastrar um novo pacote\n\t(2) Imprimir um pacote específico\n\t(3) Imprimir todos os pacotes e sair");
}