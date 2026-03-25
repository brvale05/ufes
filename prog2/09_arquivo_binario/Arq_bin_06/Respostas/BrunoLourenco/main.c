#include "estabelecimento.h"

int main(int argc, char **argv)
{
    tEstabelecimento *e = CriaEstabelecimento();
    LeEstabelecimento(e);
    ImprimeRelatorioEstabelecimento(e);
    DestroiEstabelecimento(e);

    return 0;
    
}