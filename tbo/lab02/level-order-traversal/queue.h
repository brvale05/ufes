#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;
typedef struct Node Node;

Queue *create_queue();

void insert_tree_node(Queue *q, void *tree_node);

void *remove_tree_node(Queue *q);

int is_queue_empty(Queue *q);

int get_size(Queue *q);

void destroy_queue(Queue *q);

#endif