#include "jogo.h"
#include "jogada.h"

int main()
{
    tJogo jogo;

    int queroJogar;

    do
    {

        jogo = CriaJogo();
        ComecaJogo(jogo);
        queroJogar = ContinuaJogo();

    } while(queroJogar);

    return 0;
    
}