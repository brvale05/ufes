#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

struct Tabuleiro
{
    char **mat;
    char peca1;
    char peca2;
    char pecavazio;
};

tTabuleiro* CriaTabuleiro()
{
    tTabuleiro *tabu = malloc(sizeof(tTabuleiro));

    if(!tabu)
    {
        exit(0);
    }

    tabu->mat = malloc(sizeof(char*)*TAM_TABULEIRO);

    if(!tabu->mat)
    {
        exit(0);
    }

    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++)
    {
        tabu->mat[i] = malloc(sizeof(char)*TAM_TABULEIRO);

        if(!tabu->mat[i])
        {
            exit(0);
        }
    }

    tabu->peca1 = 'X';
    tabu->peca2 = '0';
    tabu->pecavazio = '-';

    for(i = 0; i < TAM_TABULEIRO; i++)
    {
        for(j = 0; j < TAM_TABULEIRO; j++)
        {
            tabu->mat[i][j] = tabu->pecavazio;
        }
    }

    return tabu;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro)
{
    if(tabuleiro)
    {
        if(tabuleiro->mat)
        {
            int i;
            for(i = 0; i < TAM_TABULEIRO; i++)
            {
                if(tabuleiro->mat[i])
                {
                    free(tabuleiro->mat[i]);
                }
            }
            free(tabuleiro->mat);
        }
        free(tabuleiro);
    }
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y)
{
    if(peca == PECA_1)
    {
        tabuleiro->mat[x][y] = tabuleiro->peca1;
    }
    
    if(peca == PECA_2)
    {
        tabuleiro->mat[x][y] = tabuleiro->peca2;
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro)
{
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++)
    {
        for(j = 0; j < TAM_TABULEIRO; j++)
        {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, i, j))
            {
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca)
{
    if(peca == PECA_1)
    {
        if(tabuleiro->mat[x][y] == tabuleiro->peca1)
        {
            return 1;
        }
        return 0;
    }

    if(peca == PECA_2)
    {
        if(tabuleiro->mat[x][y] == tabuleiro->peca2)
        {
            return 1;
        }
        return 0;
    }

    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y)
{
    if(tabuleiro->mat[x][y] == tabuleiro->pecavazio)
    {
        return 1;
    }

    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    if(x > 2 || y > 2)
    return 0;

    if(x < 0 || y < 0)
    return 0;

    return 1;
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro)
{
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++)
    {
        for(j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro->mat[j][i]);
        }
        printf("\n");
    }
}