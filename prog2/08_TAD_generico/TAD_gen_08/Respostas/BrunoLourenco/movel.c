#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movel.h"

/**
 * @brief Estrutura representando um Movel.
 */
struct Movel
{
    char *nome;
};

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome)
{
    tMovel *m = malloc(sizeof(tMovel));
    m->nome = malloc(sizeof(char)*(strlen(nome)+1));

    strcpy(m->nome, nome);

    return m;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m)
{
    if(m)
    {
        if(m->nome)
        {
            free(m->nome);
        }
        free(m);
    }
}

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel()
{
    scanf("%*[^A-Za-z]");

    char nome[30];
    scanf("%[^\n]", nome);

    tMovel *m = CriaMovel(nome);

    return m;
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m)
{
    printf("%s\n", m->nome);
}