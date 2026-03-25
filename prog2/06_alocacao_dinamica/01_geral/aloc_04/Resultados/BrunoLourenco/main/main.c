#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

int main()
{
    char *str;
    int tam = TAM_PADRAO;

    str = CriaVetorTamPadrao();
    str = LeVetor(str, &tam);
    ImprimeString(str);
    LiberaVetor(str);

    return 0;

}