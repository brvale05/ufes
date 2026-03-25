#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


//typedef void *DataType; // void pointer
//typedef struct Vector Vector;

struct Vector
{
    DataType *data;
    int tamanho;
    int capacidade;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = malloc(sizeof(Vector));

    v->data = malloc(sizeof(DataType)*10);

    v->capacidade = 10;
    v->tamanho = 0;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if(v->tamanho >= v->capacidade)
    {
        v->capacidade *= 2;
        v->data = realloc(v->data, sizeof(DataType));
    }

    v->data[v->tamanho] = val;
    v->tamanho++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
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
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    int i;
    if(v)
    {
        if(v->data)
        {
            for(i = 0; i < v->tamanho; i++)
            {
                destroy(v->data[i]);
            }
            free(v->data);
        }
        free(v);
    }
}

