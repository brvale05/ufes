#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pacote.h"

struct pacote
{
    void *vet;
    int tam;
    Type tipo;
    int soma;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem)
{
    tPacote *pacote = malloc(sizeof(tPacote));

    switch (type)
    {
    case INT:
        pacote->vet = malloc(sizeof(int) * numElem);
        break;
    case CHAR:
        pacote->vet = malloc(sizeof(char) * (numElem + 1));
        break;

    default:
        break;
    }

    pacote->tam = numElem;
    pacote->tipo = type;
    pacote->soma = 0;

    return pacote;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{
    if (pac)
    {
        if (pac->vet)
        {
            free(pac->vet);
        }
        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{
    scanf("%*c");

    printf("\nDigite o conteúdo do vetor/mensagem: ");

    int i;
    char c;

    switch (pac->tipo)
    {
    case INT:
        for (i = 0; i < pac->tam; i++)
        {
            scanf("%d", &((int *)pac->vet)[i]);
        }
        break;
    case CHAR:
        for (i = 0; i < pac->tam; i++)
        {
            scanf("%c", &c);
            if (c == '\n')
            {
                break;
            }
            else
            {
                ((char *)pac->vet)[i] = c;
            }
        }
        ((char *)pac->vet)[i] = '\0';
        break;
    default:
        break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac)
{
    CalculaSomaVerificacaoPacote(pac);

    printf("%d ", pac->soma);
    switch (pac->tipo)
    {
    case INT:
        for (int i = 0; i < pac->tam; i++)
        {
            printf("%d ", ((int *)pac->vet)[i]);
        }
        break;
    case CHAR:
        printf("%s", (char*)pac->vet);
        break;
    default:
        break;
    }

    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    int i;

    for (i = 0; i < pac->tam; i++)
    {
        switch (pac->tipo)
        {
        case INT:
            pac->soma = pac->soma + ((int *)pac->vet)[i];
            break;
        case CHAR:
            pac->soma = pac->soma + ((char *)pac->vet)[i];
            break;

        default:
            break;
        }
    }
}
