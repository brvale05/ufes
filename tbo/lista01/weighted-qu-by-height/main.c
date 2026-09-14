#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000000

int *UF_init();
int *UF_size_init();
int UF_find(int i, int *id);
void UF_union(int p, int q, int *id, int *height);
int connected(int p, int q, int *id);

int main(int argc, char **argv)
{
    int p, q;

    int *id = UF_init();
    int *height = UF_size_init();

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (!connected(p, q, id))
        {
            UF_union(p, q, id, height);
            printf("%d %d\n", p, q);
        }
        else
        {
            printf("\n");
        }
    }

    free(id);
    free(height);
}

int *UF_size_init()
{
    int *height = malloc(sizeof(int) * MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        height[i] = 0;
    }

    return height;
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
    while (i != id[i])
    {
        i = id[i];
    }    

    return i;
}

void UF_union(int p, int q, int *id, int *height)
{
    int i = UF_find(p, id);
    int j = UF_find(q, id);

    if (i == j)
        return;

    if(height[i] == height[j])
    {
        id[i] = j;
        height[j] += 1;        
    }
    else if(height[i] < height[j])
    {
        id[i] = j;        
    }
    else
    {
        id[j] = i;        
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