#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main()
{
    tJogo *jogo;

    do
    {

        jogo = CriaJogo();
        ComecaJogo(jogo);
        DestroiJogo(jogo);

    } while (ContinuaJogo());

    return 0;
    
}