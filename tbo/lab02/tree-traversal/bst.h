#ifndef BST_H
#define BST_H

typedef struct BST BST;

BST *create();

BST *insert(BST *node, int key);

int bst_height(BST *node);

void rec_preorder(BST *t, void (*visit)(BST*));

void rec_in_order(BST *t, void (*visit)(BST*));

void rec_post_order(BST *t, void (*visit)(BST*));

void print_visited_node(BST *t);

void destroy(BST *node);

#endif