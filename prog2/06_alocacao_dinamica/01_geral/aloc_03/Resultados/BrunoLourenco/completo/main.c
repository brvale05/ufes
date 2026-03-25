#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main()
{
    int tam;
    scanf("%d", &tam);
    scanf("%*[^\n]");
    scanf("%*c");

    char *str;

    str = CriaVetor(tam);
    ImprimeString(str, tam);
    LeVetor(str, tam);
    ImprimeString(str, tam);
    LiberaVetor(str);

    return 0;
}