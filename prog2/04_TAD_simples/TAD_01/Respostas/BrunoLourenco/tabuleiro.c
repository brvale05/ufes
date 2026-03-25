#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro()
{
    tTabuleiro tabuleiro;

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';
    
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++)
    {
        for(j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;

}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    if(peca == PECA_1)
    {
        tabuleiro.posicoes[x][y] = tabuleiro.peca1;
    }
    else
    {
        tabuleiro.posicoes[x][y] = tabuleiro.peca2;
    }

    return tabuleiro;

}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++)
    {
        for(j = 0; j < TAM_TABULEIRO; j++)
        {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, i, j)) return 1;
        }
    }

    return 0;

}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    if(peca == 1)
    {
        if(tabuleiro.posicoes[x][y] == tabuleiro.peca1) return 1;
    }
    if(peca == 2)
    {
        if(tabuleiro.posicoes[x][y] == tabuleiro.peca2) return 1;
    }

    return 0;

}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    if(tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio) return 1;

    return 0;

}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    if(x > 2 || y > 2) return 0;

    if(x < 0 || y < 0) return 0;

    return 1;

}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++)
    {
        for(j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro.posicoes[j][i]);
        }
        printf("\n");
    }
}

