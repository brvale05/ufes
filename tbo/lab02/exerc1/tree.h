#ifndef TREE_H
#define TREE_H

typedef struct Tree Tree;

Tree *create_tree();

Tree *insert(Tree *node, int key);

void print(Tree *root);

void destroy(Tree *root);

#endif