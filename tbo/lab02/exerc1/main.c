#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(int argc, char **argv)
{
    Tree *root = create_tree();

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 35);
    root = insert(root, 37);
    root = insert(root, 65);
    root = insert(root, 62);

    print(root);

    destroy(root);

    return 0;
}