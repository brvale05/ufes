#include "fila.h"
#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    Fila *f = FilaConstruct();

    char op[15];
    int qtd_op;

    scanf("%d", &qtd_op);
    scanf("%*[^\n]\n");

    for(int i = 0; i < qtd_op; i++)
    {
        scanf("%s", op);

        if(!strcmp(op, "ENTRADA"))
        {
            tMovel *m = LeMovel();
            FilaPush(f, m);
        }
        else
        {
            tMovel *aux = FilaPop(f);
            ImprimeMovel(aux);
            DestroiMovel(aux);
        }
    }

    FilaDestroy(f, DestroiMovel);

    return 0;

}