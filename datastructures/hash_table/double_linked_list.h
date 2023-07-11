#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int (*COMPARE)(void *a, void *b);

typedef struct _node {
    void *data;
    struct _node *next;
    struct _node *prev;
} node_t;

typedef struct {
    node_t *head;
    node_t *current;
    node_t *tail;
    int size;
} ll_t;

int compareInt(void *a, void *b);

void init_ll(ll_t *list);

node_t *create_node(ll_t *list, void *data);

void list_append(ll_t *list, void *data);

void list_prepend(ll_t *list, void *data);

void destroy_ll(ll_t *list);

void print_ll(ll_t *list);

node_t *list_search(ll_t *list, COMPARE compare, void *data);

void delete_node(ll_t *list, node_t *node);

#endif // !DOUBLE_LINKED_LIST_H