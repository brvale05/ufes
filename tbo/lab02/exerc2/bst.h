#ifndef BST_H
#define BST_H

typedef struct BST BST;

BST *create();

BST *insert(BST *node, int key);

int bst_height(BST *node);

void print(BST *node);

void destroy(BST *node);

#endif