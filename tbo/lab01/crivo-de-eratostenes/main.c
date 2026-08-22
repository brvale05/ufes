#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *cria_lista(int num);
int le_numero();
void imprime_lista(int *lista, int tam);

int main(int argc, char **argv)
{
    printf("Digite um número:\n");

    int num = le_numero();
    int *lista = cria_lista(num);

    for (int i = 2; i < num; i++)
    {
        if (lista[i] == -1)
        {
            continue;
        }

        for (int j = i * 2; j < num; j = j + i)
        {
            lista[j] = -1;
        }
    }

    imprime_lista(lista, num);

    free(lista);

    return 0;
}

int *cria_lista(int num)
{
    int *lista = malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
    {
        lista[i] = i;
    }

    return lista;
}

int le_numero()
{
    int num;
    scanf("%d", &num);

    return num + 1;
}

void imprime_lista(int *lista, int tam)
{
    for (int i = 2; i < tam; i++)
    {
        if (lista[i] != -1)
            printf("%d ", lista[i]);
    }
}