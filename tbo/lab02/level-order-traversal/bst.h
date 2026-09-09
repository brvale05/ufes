#ifndef BST_H
#define BST_H

typedef struct BST BST;

#include "queue.h"

BST *create();

BST *insert(BST *node, int key);

int bst_height(BST *node);

void level_order_traversal(Queue *q, BST *root, void (*visit)(BST *));

void print_visited_node(BST *t);

void destroy_BST(BST *node);

#endif