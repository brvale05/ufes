#include <stdlib.h>
#include <stdio.h>
#include "tadgen.h"

struct generic
{
    void *data;
    int tam;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem)
{
    tGeneric *tad = malloc(sizeof(tGeneric));

    switch (type)
    {
    case FLOAT:
        tad->data = malloc(sizeof(float)*numElem);
        break;
    case INT:
        tad->data = malloc(sizeof(int)*numElem);
        break;
    default:
        break;
    }

    tad->tipo = type;
    tad->tam = numElem;

    return tad;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen)
{
    if(gen)
    {
        if(gen->data)
        {
            free(gen->data);
        }
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen)
{

    printf("\nDigite o vetor:\n");

    int i;

    switch (gen->tipo)
    {
    case FLOAT:
        for(i = 0; i < gen->tam; i++)
        {
            scanf("%f", &((float*)gen->data)[i]);
        }
        break;
    case INT:
        for(i = 0; i < gen->tam; i++)
        {
            scanf("%d", &((int*)gen->data)[i]);
        }
        break;
    default:
        break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen)
{
    int i;

    for(i = 0; i < gen->tam; i++)
    {
        switch (gen->tipo)
        {
        case FLOAT:
            printf("%.2f ", ((float*)gen->data)[i]);
            break;
        case INT:
            printf("%d ", ((int*)gen->data)[i]);
        default:
            break;
        }
    }

    printf("\n");

}