#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

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

void rec_preorder(BST *t, void (*visit)(BST *))
{
    if (t)
    {
        visit(t);
        rec_preorder(t->left, visit);
        rec_preorder(t->right, visit);
    }
}

void rec_in_order(BST *t, void (*visit)(BST *))
{
    if (t)
    {
        rec_in_order(t->left, visit);
        visit(t);
        rec_in_order(t->right, visit);
    }    
}

void rec_post_order(BST *t, void (*visit)(BST *))
{
    if (t)
    {
        rec_post_order(t->left, visit);        
        rec_post_order(t->right, visit);
        visit(t);
    }
}

void print_visited_node(BST *t)
{
    printf("%d ", t->key);
}

void destroy(BST *node)
{
    if (node)
    {
        destroy(node->left);
        destroy(node->right);
        free(node);
    }
}