#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia
{
    int numero;
    char nome[100];
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *agencia = malloc(sizeof(tAgencia));
    if(!agencia)
    {
        printf("erro ao alocar tagencia!\n");
        exit(0);
    }

    agencia->contas = VectorConstruct();

    return agencia;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    if((tAgencia*)agencia)
    {
        if(((tAgencia*)agencia)->contas)
        {
            VectorDestroy(((tAgencia*)agencia)->contas, DestroiConta);
        }
        free((tAgencia*)agencia);
    }
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf("%d", &agencia->numero);
    scanf(";");
    scanf("%[^\n]\n", agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    if(agencia2->numero == numAgencia)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    float soma = 0;
    int i;

    for(i = 0; i < VectorSize(agencia->contas); i++)
    {
        soma = soma + GetSaldoConta(VectorGet(agencia->contas, i));
    }

    return soma/(float)VectorSize(agencia->contas);

}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("Nome: %s\n", agencia->nome);

    printf("Numero: %d\n", agencia->numero);

    printf("Numero de contas cadastradas: %d\n", VectorSize(agencia->contas));

    printf("Saldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}
