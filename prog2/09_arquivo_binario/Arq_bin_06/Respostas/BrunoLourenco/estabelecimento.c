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
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento)
{
    float soma = 0;

    for(int i = 0; i < VectorSize(estabelecimento->produtos); i++)
    {
        soma += GetQuantidadeVendidaProduto(VectorGet(estabelecimento->produtos, i))*GetPrecoProduto(VectorGet(estabelecimento->produtos, i));
    }

    return soma;

}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento)
{
    float porcentagem, preco, valorTotal = GetValorTotalVendidoEstabelecimento(estabelecimento);

    int qtdVendida;

    printf("Valor total vendido: R$ %.2f\n", valorTotal);

    printf("Produtos vendidos:\n");

    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");

    for(int i = 0; i < VectorSize(estabelecimento->produtos); i++)
    {
        qtdVendida = GetQuantidadeVendidaProduto(VectorGet(estabelecimento->produtos, i)); 
        preco = GetPrecoProduto(VectorGet(estabelecimento->produtos, i));

        ImprimeProduto(VectorGet(estabelecimento->produtos, i));
        porcentagem = (((float)qtdVendida*preco)/valorTotal)*100;
        printf(";%.2f%%\n", porcentagem);
    }
}