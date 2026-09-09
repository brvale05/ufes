#ifndef BST_H
#define BST_H

#include "stack.h"

typedef struct BST BST;

BST *create();

BST *insert(BST *node, int key);

int bst_height(BST *node);

void preorder(BST *t, Stack *s, void (*visit)(BST*));

void in_order(BST *t, Stack *s, void (*visit)(BST *));

void post_order(BST *t, Stack *s, void (*visit)(BST *));

void print_visited_node(BST *t);

void destroy_BST(BST *node);

#endif