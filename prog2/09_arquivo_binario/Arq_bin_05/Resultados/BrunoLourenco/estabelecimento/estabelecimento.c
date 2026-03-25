#include <stdlib.h>
#include "estabelecimento.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento
{
    Vector *produtos;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{
    tEstabelecimento *e = malloc(sizeof(tEstabelecimento));

    e->produtos = VectorConstruct();

    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{
    if(estabelecimento)
    {
        VectorDestroy(estabelecimento->produtos, DestroiProduto);
        free(estabelecimento);
    }
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto)
{
    VectorPushBack(estabelecimento->produtos, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento)
{
    char caminho[100];
    int tamanho;

    scanf("%[^\n]", caminho);
    scanf("%*c");

    FILE *fb = fopen(caminho, "rb");

    fread(&tamanho, sizeof(int), 1, fb);

    for(int i = 0; i < tamanho; i++)
    {
        tProduto *pAux;
        pAux = LeProduto(fb);
        AdicionaProdutoEstabelecimento(estabelecimento, pAux);
    }

    fclose(fb);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento)
{
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");

    int flag = 0;

    for(int i = 0; i < VectorSize(estabelecimento->produtos); i++)
    {
        if(!TemEstoqueProduto(VectorGet(estabelecimento->produtos, i)))
        {
            ImprimeProduto(VectorGet(estabelecimento->produtos, i));
            flag++;
        }
    }

    if(flag < 1)
    {
        printf("Nao ha produtos em falta!\n");
    }
}
