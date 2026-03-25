#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogada
{
    int x;
    int y;
    int sucesso; //1 para lida com sucesso 0 para o contrario
};

tJogada* CriaJogada()
{
    tJogada *jogada = malloc(sizeof(tJogada));

    if(!jogada)
    {
        exit(0);
    }

    jogada->x = -1;
    jogada->y = -1;
    jogada->sucesso = 0;

    return jogada;
}

void DestroiJogada(tJogada* jogada)
{
    if(jogada)
    {
        free(jogada);
    }
}

void LeJogada(tJogada* jogada)
{
    int x, y;

    printf("Digite uma posicao (x e y):\n");

    if(scanf("%d %d", &x, &y) == 2)
    {
        jogada->x = x;
        jogada->y = y;
        jogada->sucesso = 1;
    }
}

int ObtemJogadaX(tJogada* jogada)
{
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada)
{
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada)
{
    if(jogada->sucesso > 0)
    return 1;

    return 0;
}