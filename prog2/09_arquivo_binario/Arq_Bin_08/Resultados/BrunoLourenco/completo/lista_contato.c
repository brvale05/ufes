#include "lista_contato.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ListaContato
{
    Vector *contatos;
};

/**
 * @brief Cria uma lista de contatos.
 *
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
 */
tListaContato *CriarListaContato()
{
    tListaContato *lista = malloc(sizeof(tListaContato));

    lista->contatos = VectorConstruct();

    return lista;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 *
 * @param l Ponteiro para a lista de contatos a ser liberada.
 */
void DestruirListaContato(tListaContato *l)
{
    if (l)
    {
        VectorDestroy(l->contatos, DestruirContato);
        free(l);
    }
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 *
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
 */
void AdicionarContatoListaContato(tListaContato *l, tContato *contato)
{
    int tamanho = VectorSize(l->contatos);

    printf("\n"); 

    for (int i = 0; i < tamanho; i++)
    {
        if (ComparaTelefoneContato(VectorGet(l->contatos, i), contato) || ComparaNomeContato(VectorGet(l->contatos, i), contato))
        {
            printf("Ja existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato);
            return;
        }
    }

    VectorPushBack(l->contatos, contato);
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 *
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 *
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
 */
void CarregarListaContato(tListaContato *l, char *nomeArquivo)
{

    FILE *fb = fopen(nomeArquivo, "rb");
    if (fb == NULL)
        return;

    int tamanho;

    fread(&tamanho, sizeof(int), 1, fb);

    for (int i = 0; i < tamanho; i++)
    {
        tContato *aux = CarregarContato(fb);
        VectorPushBack(l->contatos, aux);
    }

    fclose(fb);
}

void SalvarListaContato(tListaContato *l, char *nomeArquivo)
{
    FILE *fb = fopen(nomeArquivo, "wb");

    int tamanho = VectorSize(l->contatos);
    fwrite(&tamanho, sizeof(int), 1, fb);

    for (int i = 0; i < tamanho; i++)
    {
        SalvarContato(VectorGet(l->contatos, i), fb);
    }

    fclose(fb);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 *
 * @param l Ponteiro para a lista de contatos.
 */
void BuscarPorNumeroTelefoneListaContato(tListaContato *l)
{
    unsigned long int tel;
    scanf("%*[^0-9]");

    scanf("%lu", &tel);
    scanf("%*c");

    int tamanho = VectorSize(l->contatos);

    for (int i = 0; i < tamanho; i++)
    {
        if (GetTelefoneContato(VectorGet(l->contatos, i)) == tel)
        {
            ImprimirContato(VectorGet(l->contatos, i));
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 *
 * @param l Ponteiro para a lista de contatos.
 */
void BuscarPorNomeListaContato(tListaContato *l)
{

    char nome[100] = "";
    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", nome);
    scanf("%*c");

    int tamanho = VectorSize(l->contatos);

    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(GetNomeContato(VectorGet(l->contatos, i)), nome) == 0)
        {
            ImprimirContato(VectorGet(l->contatos, i));
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

/**
 * @brief Imprime a lista de contatos na tela.
 *
 * @param l Ponteiro para a lista de contatos.
 */
void ImprimirListaContato(tListaContato *l)
{

    int tamanho = VectorSize(l->contatos);
    printf("\n"); 
    printf("Lista de contatos cadastrados\n");

    for (int i = 0; i < tamanho; i++)
    {
        ImprimirContato(VectorGet(l->contatos, i));
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 *
 * @param l Ponteiro para a lista de contatos.
 */
void RemoverContatoListaContato(tListaContato *l)
{

    unsigned long int tel;
    scanf("%*[^0-9]");
    scanf("%lu", &tel);
    scanf("%*c");

    printf("\n"); 

    int tamanho = VectorSize(l->contatos);

    for (int i = tamanho - 1; i >= 0; i--)
    {
        tContato *c = VectorGet(l->contatos, i);

        if (GetTelefoneContato(c) == tel)
        {
            VectorRemove(l->contatos, i);
            DestruirContato(c);
            printf("Contato removido com sucesso\n");
            return;
        }
    }

    printf("Nao existe um contato cadastrado com esse numero de telefone\n");
}
