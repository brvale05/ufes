#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main(int argc, char **argv)
{
    BST *root = create();

    root = insert(root, 200);

    // Monta sub-arvore esquerda
    root = insert(root, 120);
    root = insert(root, 90);
    root = insert(root, 160);
    root = insert(root, 150);
    root = insert(root, 170);

    // Monta sub-arvore direita
    root = insert(root, 250);
    root = insert(root, 300);
    root = insert(root, 270);

    Stack *s = init();

    preorder(root, s, print_visited_node);

    destroy_BST(root);
    destroy_stack(s);

    return 0;
}