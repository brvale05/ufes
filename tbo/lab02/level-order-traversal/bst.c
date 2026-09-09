#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "queue.h"

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

void level_order_traversal(Queue *q, BST *root, void (*visit)(BST *))
{
    if (!root)
        return;

    insert_tree_node(q, root);

    while (!is_queue_empty(q))
    {
        int lenght = get_size(q);

        for (int i = 0; i < lenght; i++)
        {
            BST *tree_node = remove_tree_node(q);

            visit(tree_node);

            if(tree_node->left)
            {
                insert_tree_node(q, tree_node->left);
            }

            if(tree_node->right)
            {
                insert_tree_node(q, tree_node->right);
            }
        }
        
    }
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