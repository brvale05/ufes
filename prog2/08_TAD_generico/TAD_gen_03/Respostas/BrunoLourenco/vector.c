#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

#define CAP_MAX 10;

//typedef void *data_type; // void pointer
struct Vector
{
    data_type *data;
    int capacidade;
    int tam;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *vec = malloc(sizeof(Vector));
    if(!vec)
    {
        printf("erro ao alocar vector\n");
        exit(0);
    }

    vec->capacidade = CAP_MAX;
    vec->tam = 0;

    vec->data = malloc(sizeof(data_type)*vec->capacidade);
    if(!vec->data)
    {
        printf("erro ao alocar datatype\n");
        exit(0);
    }

    return vec;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
    if(v->capacidade == v->tam)
    {
        v->capacidade = v->capacidade*2;
        realloc(v->data, sizeof(data_type)*v->capacidade);
    }

    ((data_type*)v->data)[v->tam] = val;

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
    return v->data[i];
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
    int i;
    if(v)
    {
        if(v->data)
        {
            for(i = 0; i < v->tam; i++)
            {
                if(v->data[i])
                {
                    destroy(v->data[i]);
                }
            }
            free(v->data);
        }
        free(v);
        //v = NULL;
    }
}
