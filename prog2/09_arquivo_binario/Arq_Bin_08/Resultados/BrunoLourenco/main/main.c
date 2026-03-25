#include <stdio.h>

#include "lista_contato.h"

void ImprimeMenu();

void Cadastrar();

void Buscar();

int main()
{
    tListaContato *lista = CriarListaContato();

    char caminho[100];
    scanf("%[^\n]", caminho);
    scanf("%*c");
    
    CarregarListaContato(lista, caminho);

    int op = 0;
    while (1)
    {
        ImprimeMenu();
        scanf("%d%*c", &op);

        if (!op)
            break;

        switch (op)
        {
        case 1:
            Cadastrar(lista);
            break;
        case 2:
            RemoverContatoListaContato(lista);
            break;
        case 3:
            Buscar(lista);
            break;
        case 4:
            ImprimirListaContato(lista);
            break;
        default:
            break;
        }
    }

    scanf("%[^\n]", caminho);
    scanf("%*c");

    SalvarListaContato(lista, caminho);

    DestruirListaContato(lista);

    return 0;
}

void ImprimeMenu()
{
    printf("1 - Cadastrar contato\n");
    printf("2 - Remover contato\n");
    printf("3 - Realizar busca\n");
    printf("4 - Exibir todos os contatos\n");
    printf("0 - Sair da lista de contatos\n");
    printf("Opcao escolhida: \n");
}

void Cadastrar(tListaContato *lista)
{
    tContato *c = LeContato();
    AdicionarContatoListaContato(lista, c);
}

void Buscar(tListaContato *lista)
{
    int op = 0;

    printf("1 - Buscar pelo nome\n");
    printf("2 - Buscar pelo numero de telefone\n");
    printf("Opcao escolhida: \n");

    scanf("%d", &op);
    scanf("%*c");

    if (op == 1)
    {
        BuscarPorNomeListaContato(lista);
    }
    else if (op == 2)
    {
        BuscarPorNumeroTelefoneListaContato(lista);
    }
}