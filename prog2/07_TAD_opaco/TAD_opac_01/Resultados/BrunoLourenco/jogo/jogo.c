#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"


struct Jogo{

    tTabuleiro* tabuleiro;
    tJogador* jogador1;
    tJogador* jogador2;
    
};

tJogo* CriaJogo()
{
    tJogo *jogo = malloc(sizeof(struct Jogo));
    if(jogo == NULL)
    {
        exit(0);
    }

    return jogo;
}

void ComecaJogo(tJogo* jogo)
{
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);

    tJogador *jogadorAtual;
    int idAtual = ID_JOGADOR_1;

    do
    {
        if(idAtual == ID_JOGADOR_1)
        {
            jogadorAtual = jogo->jogador1;
        }
        else
        {
            jogadorAtual = jogo->jogador2;
        }

        JogaJogador(jogadorAtual, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);

        if(VenceuJogador(jogadorAtual, jogo->tabuleiro))
        {
            printf("JOGADOR %d Venceu!\n", idAtual);
            break;
        }

        idAtual++;

        if(idAtual > ID_JOGADOR_2)
        {
            idAtual = ID_JOGADOR_1;
        }

    } while(!AcabouJogo(jogo));

}

int AcabouJogo(tJogo* jogo)
{
    if(TemPosicaoLivreTabuleiro(jogo->tabuleiro))
    {
        return 0;
    }
    printf("Sem vencedor!\n");
    return 1;
}

int ContinuaJogo()
{
    printf("Jogar novamente? (s,n)\n");

    char c;
    scanf("%*[^a-z]");
    scanf("%c", &c);

    if(c == 's')
    {
        return 1;
    }
    return 0;
}

void DestroiJogo(tJogo* jogo)
{
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    DestroiTabuleiro(jogo->tabuleiro);

    free(jogo);
}