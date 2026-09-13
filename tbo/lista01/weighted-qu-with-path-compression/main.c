#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000000

int *UF_init();
int *UF_size_init();
int UF_find(int i, int *id);
void UF_union(int p, int q, int *id, int *sz);
int connected(int p, int q, int *id);

int main(int argc, char **argv)
{
    int p, q;

    int *id = UF_init();
    int *sz = UF_size_init();

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (!connected(p, q, id))
        {
            UF_union(p, q, id, sz);
            printf("%d %d\n", p, q);
        }
        else
        {
            printf("\n");
        }
    }

    free(id);
    free(sz);
}

int *UF_size_init()
{
    int *sz = malloc(sizeof(int) * MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        sz[i] = 1;
    }

    return sz;
}

int *UF_init()
{
    int *id = malloc(sizeof(int) * MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        id[i] = i;
    }

    return id;
}

int UF_find(int i, int *id)
{
    // Salva o valor inicial de "i" para ser usado depois.
    int j = i;

    while (i != id[i])
    {
        i = id[i];
    }

    int root = i;

    // Percorre até encontrar a raiz novamente para atribuir o id[] de cada nó à raiz.
    while (j != id[j])
    {
        // Variável auxiliar que salva o valor antigo de j.
        int aux = j;

        j = id[j];
        id[aux] = root;
    }

    return root;
}

void UF_union(int p, int q, int *id, int *sz)
{
    int i = UF_find(p, id);
    int j = UF_find(q, id);

    if (i == j)
        return;

    if(sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}

int connected(int p, int q, int *id)
{
    int i = UF_find(p, id);
    int j = UF_find(q, id);

    if (i == j)
    {
        return 1;
    }

    return 0;
}