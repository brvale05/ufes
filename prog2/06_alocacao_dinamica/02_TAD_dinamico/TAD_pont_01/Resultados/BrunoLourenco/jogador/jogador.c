#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"

tJogador *CriaJogador(int idJogador)
{
    tJogador *jogador = malloc(sizeof(tJogador));

    jogador->id = idJogador;

    return jogador;
}

void DestroiJogador(tJogador *jogador)
{
    free(jogador);
}

void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    tJogada *jogada = CriaJogada();

    while (1)
    {
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);

        if (FoiJogadaBemSucedida(jogada))
        {
            if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
            {
                if (EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
                {
                    MarcaPosicaoTabuleiro(tabuleiro, jogador->id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                    break;
                }
                else
                {
                    printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            }
            else
            {
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }
        else
        {
            printf("Jogada mal sucedida!\n");
            exit(0);
        }
    }

    DestroiJogada(jogada);
}

int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    char peca;
    if (jogador->id == ID_JOGADOR_1)
    {
        peca = PECA_1;
    }
    else
    {
        peca = PECA_2;
    }

    // Linhas
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca))
    {
        return 1;
    } // Colunas
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca))
    {
        return 1;
    } // Diagonais
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca))
    {
        return 1;
    }
    else if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca))
    {
        return 1;
    }

    return 0;
}
