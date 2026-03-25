#include <stdio.h>
#include "tabuleiro.h"
#include <stdlib.h>

tTabuleiro *CriaTabuleiro()
{
    int i, j;
    tTabuleiro *tabuleiro;

    tabuleiro = malloc(sizeof(tTabuleiro));

    if (!tabuleiro)
    {
        exit(0);
    }

    tabuleiro->posicoes = malloc(TAM_TABULEIRO * sizeof(char *));

    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        tabuleiro->posicoes[i] = (char *)malloc(TAM_TABULEIRO * sizeof(char));
    }

    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';
    tabuleiro->pecaVazio = '-';

    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro->posicoes[i][j] = tabuleiro->pecaVazio;
        }
    }

    return tabuleiro;
}

void DestroiTabuleiro(tTabuleiro *tabuleiro)
{
    int i;

    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        if (tabuleiro->posicoes[i])
        {
            free(tabuleiro->posicoes[i]);
        }
    }

    free(tabuleiro->posicoes);

    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y)
{
    if (peca == PECA_1)
    {
        tabuleiro->posicoes[x][y] = tabuleiro->peca1;
    }
    else
    {
        tabuleiro->posicoes[x][y] = tabuleiro->peca2;
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro)
{
    int i, j;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, i, j))
            {
                return 1;
            }
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca)
{
    if (peca == PECA_1)
    {
        if (tabuleiro->posicoes[x][y] == tabuleiro->peca1)
        {
            return 1;
        }
    }
    else
    {
        if (tabuleiro->posicoes[x][y] == tabuleiro->peca2)
        {
            return 1;
        }
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y)
{
    if (tabuleiro->posicoes[x][y] == tabuleiro->pecaVazio)
    {
        return 1;
    }

    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    if (x >= 0 && x <= 2)
    {
        if (y >= 0 && y <= 2)
        {
            return 1;
        }

        return 0;
    }

    return 0;
}

void ImprimeTabuleiro(tTabuleiro *tabuleiro)
{
    int i, j;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro->posicoes[j][i]);
        }
        printf("\n");
    }
}