#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

struct Node
{
    Node *next;
    void *tree_node;
};

struct Queue
{
    Node *start;
    Node *end;
    int size;
};

Queue *create_queue()
{
    Queue *q = malloc(sizeof(Queue));

    q->start = q->end = NULL;
    q->size = 0;

    return q;
}

void insert_tree_node(Queue *q, void *tree_node)
{
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->tree_node = tree_node;

    // Lista vazia
    if (q->start == NULL)
    {
        q->start = q->end = node;
    }
    else
    {
        // Insere no fim
        q->end->next = node;
        q->end = node;
    }

    q->size++;
}

void *remove_tree_node(Queue *q)
{
    // Lista vazia
    if (q->start == NULL)
    {
        return NULL;
    }
    else
    {
        // Retira do inicio
        Node *aux = q->start;
        q->start = q->start->next;

        void *tree = aux->tree_node;
        free(aux);

        q->size--;

        return tree;
    }
}

int is_queue_empty(Queue *q)
{
    if (q->start == NULL)
        return 1;

    return 0;
}

int get_size(Queue *q)
{
    return q->size;
}

void destroy_queue(Queue *q)
{
    if(q)
    {
        Node *atual = q->start;
        Node *antes;

        while (atual)
        {
            antes = atual;
            atual = atual->next;
            free(antes);
        }

        free(q);
        
    }
}
