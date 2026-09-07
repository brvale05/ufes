#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main(int argc, char **argv)
{
    int N = 1000000;

    BST *root = create();

    srand(time(NULL)); 

    for (int i = 0; i < N; i++)
    {        
        int r = rand();
        root = insert(root, r);
    }

    int height = bst_height(root);

    printf("%d", height);

    destroy(root);

    return 0;
}