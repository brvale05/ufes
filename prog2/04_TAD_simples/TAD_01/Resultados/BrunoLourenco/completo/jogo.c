#include "jogo.h"
#include "jogada.h"
#include <stdio.h>

tJogo CriaJogo()
{
    tJogo jogo;

    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

    jogo.tabuleiro = CriaTabuleiro();

    return jogo;
}

void ComecaJogo(tJogo jogo)
{
    tJogada jogada;   

    tJogador Jogador_Atual[2];

    Jogador_Atual[0] = jogo.jogador1;
    Jogador_Atual[1] = jogo.jogador2;

    int id = 0;

    while(!AcabouJogo(jogo))
    {
        if(id > 1) id = 0;

        jogo.tabuleiro = JogaJogador(Jogador_Atual[id], jogo.tabuleiro);

        ImprimeTabuleiro(jogo.tabuleiro);    

        if(VenceuJogador(Jogador_Atual[id], jogo.tabuleiro))
        {
            printf("JOGADOR %d Venceu!\n", Jogador_Atual[id].id);
            return;
        }

        id++;
    }

    printf("Sem vencedor!\n");
}

int AcabouJogo(tJogo jogo)
{
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)) return 0;

    return 1;
}

int ContinuaJogo()
{
    char car;

    printf("Jogar novamente? (s,n)\n");

    scanf("%*[^a-z]");
    scanf("%c", &car);

    if(car == 's') return 1;

    return 0;

}