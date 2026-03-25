#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;

    while(1)
    {
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();

        if(FoiJogadaBemSucedida(jogada))
        {
            if(EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
            {
                if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
                {
                    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
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
            exit(1);
        }
    }

    return tabuleiro;

}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    if(jogador.id == PECA_1)
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, PECA_1))
        {
            //horizontal
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, PECA_1)) return 1;

            //diagonal esquerda para direita
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, PECA_1)) return 1;

            //vertical
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, PECA_1)) return 1;
        }
        
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, PECA_1))
        {
            //horizontal
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, PECA_1)) return 1;

            //diagonal direita para esquerda
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, PECA_1)) return 1;

            //vertical
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, PECA_1)) return 1;
        }
        
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, PECA_1))
        {
            //horizontal
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, PECA_1)) return 1;

            //vertical
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, PECA_1) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, PECA_1)) return 1;
        }
    }

    if(jogador.id == PECA_2)
    {
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, PECA_2))
        {
            //horizontal
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, PECA_2)) return 1;

            //diagonal esquerda para direita
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, PECA_2)) return 1;

            //vertical
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, PECA_2)) return 1;
        }
        
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, PECA_2))
        {
            //horizontal
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, PECA_2)) return 1;

            //diagonal direita para esquerda
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, PECA_2)) return 1;

            //vertical
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, PECA_2)) return 1;
        }
        
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, PECA_2))
        {
            //horizontal
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, PECA_2)) return 1;

            //vertical
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, PECA_2) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, PECA_2)) return 1;
        }
    }

    return 0;
    
}