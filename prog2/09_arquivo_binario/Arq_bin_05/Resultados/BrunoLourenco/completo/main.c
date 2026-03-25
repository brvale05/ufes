#include "estabelecimento.h"

int main(int argc, char *argv[])
{
    tEstabelecimento *estabelecimento = CriaEstabelecimento();
    LeEstabelecimento(estabelecimento);
    ImprimeProdutosEmFaltaEstabelecimento(estabelecimento);
    DestroiEstabelecimento(estabelecimento);

    return 0;
}