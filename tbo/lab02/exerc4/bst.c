#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "stack.h"

struct BST
{
    int key;
    BST *left;
    BST *right;
};

BST *create()
{
    return NULL;
}

BST *insert(BST *node, int key)
{
    if (!node)
    {
        BST *new_node = malloc(sizeof(BST));

        new_node->left = NULL;
        new_node->right = NULL;
        new_node->key = key;

        return new_node;
    }

    if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else if (key < node->key)
    {
        node->left = insert(node->left, key);
    }

    return node;
}

int bst_height(BST *node)
{
    if (!node)
    {
        return -1;
    }

    int height = 0;

    int left_height = 0;
    int right_height = 0;

    right_height = bst_height(node->right);
    left_height = bst_height(node->left);

    if (right_height > left_height)
    {
        height = right_height + 1;
    }
    else
    {
        height = left_height + 1;
    }

    return height;
}

void preorder(BST *t, Stack *s, void (*visit)(BST *))
{
    // Adiciona a raiz como primeiro elemento da pilha
    push(s, t);

    while (!is_empty(s))
    {
        // Desempilha o elemento
        BST *node = pop(s);

        if (!node)
            continue;

        visit(node);

        push(s, node->right);
        push(s, node->left);
    }
}

void in_order(BST *t, Stack *s, void (*visit)(BST *))
{
    // Adiciona a raiz como primeiro elemento da pilha
    push(s, t);

    while (!is_empty(s))
    {
        push(s, t->right);
        push(s, t->left);

        
    }
}

void post_order(BST *t, Stack *s, void (*visit)(BST *))
{
}

void print_visited_node(BST *t)
{
    printf("%d ", t->key);
}

void destroy_BST(BST *node)
{
    if (node)
    {
        destroy_BST(node->left);
        destroy_BST(node->right);
        free(node);
    }
}