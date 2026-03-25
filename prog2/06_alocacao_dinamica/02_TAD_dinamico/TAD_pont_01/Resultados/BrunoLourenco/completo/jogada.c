#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada *CriaJogada()
{
    tJogada *jogada = malloc(sizeof(tJogada));

    if (!jogada)
    {
        exit(0);
    }

    jogada->sucesso = 0;

    return jogada;
}

void DestroiJogada(tJogada *jogada)
{

    free(jogada);
}

void LeJogada(tJogada *jogada)
{
    printf("Digite uma posicao (x e y):\n");

    if (scanf("%d %d", &jogada->x, &jogada->y) == 2)
    {
        jogada->sucesso = 1;
    }
    else
    {
        jogada->sucesso = 0;
    }
}

int FoiJogadaBemSucedida(tJogada *jogada)
{
    if (jogada->sucesso > 0)
    {
        return 1;
    }

    return 0;
}

int ObtemJogadaX(tJogada *jogada)
{
    return jogada->x;
}

int ObtemJogadaY(tJogada *jogada)
{
    return jogada->y;
}
