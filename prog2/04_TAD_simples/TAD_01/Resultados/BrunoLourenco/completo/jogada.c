#include "jogada.h"
#include <stdio.h>

tJogada LeJogada()
{
    tJogada jogada;

    int x, y;

    printf("Digite uma posicao (x e y):\n");

    if(scanf("%d %d", &x, &y) == 2)
    {
        scanf("%*c");
        jogada.x = x;
        jogada.y = y;
        jogada.sucesso = 1;
    }
    else
    {
        jogada.sucesso = 0;
    }

    return jogada;

}

int ObtemJogadaX(tJogada jogada)
{
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada)
{
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada)
{
    if(jogada.sucesso == 1) return 1;

    return 0;
}