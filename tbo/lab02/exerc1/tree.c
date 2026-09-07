#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

struct Tree
{
    int key;
    Tree *left;
    Tree *right;
};


Tree *create_tree()
{
    return NULL;
}

Tree *insert(Tree *node, int key)
{
    if (!node)
    {
        Tree *tree = malloc(sizeof(Tree));

        tree->left = NULL;
        tree->right = NULL;
        tree->key = key;

        return tree;
    }

    if(key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else if(key < node->key)
    {
        node->left = insert(node->left, key);
    }

    return node;
    
}

void print(Tree *root)
{
    if(root)
    {
        printf("%d\n", root->key);
        print(root->left);
        print(root->right);
    }
}

void destroy(Tree *root)
{
    if(root)
    {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}