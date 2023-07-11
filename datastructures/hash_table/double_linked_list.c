#include "double_linked_list.h"

typedef int (*COMPARE)(void *a, void *b);

int compareInt(void *a, void *b) {
    return *(int*)a == *(int*)b;
}

void init_ll(ll_t *list) {
    list->head = list->current = list->tail = NULL;
    list->size = 0;
}

node_t *create_node(ll_t *list, void *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = list->head;
    return node;
}

void list_append(ll_t *list, void *data) {
    node_t *node = create_node(list, data);
    node->next = NULL;
    if(list->head == NULL) {
        list->head = list->tail = node;
        node->prev = NULL;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
    }
    list->tail = node;
    list->size++;
}

void list_prepend(ll_t *list, void *data) {
    node_t *node = create_node(list, data);
    if(list->head != NULL) {
        list->head->prev = node;
    } else {
        list->tail = node;
        node->next = NULL;
    }
    list->head = node;
    node->prev = NULL;
    list->size++;
}

void destroy_ll(ll_t *list) {
    node_t *node = list->head;
    while(node != NULL) {
        node_t *temp = node;
        node = node->next;
        free(temp);
    }
    list->head = list->current = list->tail = NULL;
    list->size = 0;
}

void print_ll(ll_t *list) {
    node_t *node = list->head;
    while(node != NULL) {
        printf("%d ", *(int *)node->data);
        node = node->next;
    }
    printf("\n");
}

// returns the first node that matches the data 
node_t *list_search(ll_t *list, COMPARE compare, void *data) {
    node_t *node = list->head;
    while(node != NULL) {
        if(compare(node->data, data)) 
            return node;
        node = node->next;
    }
    return NULL;
}

void delete_node(ll_t *list, node_t *node) {
    if(node == list->head) {
        list->head = node->next;
        if(list->head != NULL) {
            list->head->prev = NULL;
        }
    } else if(node == list->tail) {
        list->tail = node->prev;
        if(list->tail != NULL) {
            list->tail->next = NULL;
        }
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    list->size--;
    free(node);
}