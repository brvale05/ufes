#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *data_type; // void pointer

struct Vector
{
    data_type *data;
    int tam;
    int capacidade;
};

/**
 * @brief Cria um vetor vazio
 *
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Vector *VectorConstruct()
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    if (!v)
    {
        printf("erro ao alocar vector!\n");
        exit(0);
    }

    v->capacidade = CAP_MAX;
    v->tam = 0;

    v->data = malloc(sizeof(data_type) * v->capacidade);
    if (!v->data)
    {
        printf("erro ao alocar data vector!\n");
        exit(0);
    }

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 *
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
 */
void VectorPushBack(Vector *v, data_type val)
{
    if (v->tam == v->capacidade)
    {
        v->capacidade = v->capacidade * 2;
        v->data = realloc(v->data, sizeof(data_type) * v->capacidade);
    }
    ((data_type *)v->data)[v->tam] = val;
    v->tam++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 *
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
 */
data_type VectorGet(Vector *v, int i)
{
    return ((data_type *)v->data)[i];
}

/**
 * @brief Retorna o tamanho do vetor
 *
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
 */
int VectorSize(Vector *v)
{
    return v->tam;
}

/**
 * @brief Libera a memória alocada para o vetor
 *
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
 */
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    if (v)
    {
        if (v->data)
        {
            for (int i = 0; i < v->tam; i++)
            {
                if (v->data[i])
                {
                    destroy(((data_type *)v->data)[i]);
                }
            }
            free(v->data);
        }
        free(v);
    }
}

void VectorPrint(Vector *v, void (*imprime)(data_type))
{
    for (int i = 0; i < VectorSize(v); i++)
    {
        printf("--------------------\n");
        imprime(VectorGet(v, i));
    }
}

void VectorOrdena(Vector *v, int (*compare)(const void *, const void *))
{
    qsort(v->data, v->tam, sizeof(void *), compare);
}
