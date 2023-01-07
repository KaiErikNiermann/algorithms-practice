#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int (*COMPARE)(void *a, void *b);

int compareInt(void *a, void *b) {
    return *(int*)a == *(int*)b;
}

typedef struct _node {
    void *data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct {
    Node *head;
    Node *current;
    Node *tail;
    int size;
} LinkedList;

void initList(LinkedList *list) {
    list->head = list->current = list->tail = NULL;
    list->size = 0;
}

Node *nodeConstructor(LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    return node;
}

void addTail(LinkedList *list, void *data) {
    Node *node = nodeConstructor(list, data);
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

void addHead(LinkedList *list, void *data) {
    Node *node = nodeConstructor(list, data);
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

void destroyList(LinkedList *list) {
    Node *node = list->head;
    while(node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    list->head = list->current = list->tail = NULL;
    list->size = 0;
}

void printList(LinkedList *list) {
    Node *node = list->head;
    while(node != NULL) {
        printf("%d ", *(int *)node->data);
        node = node->next;
    }
    printf("\n");
}

// returns the first node that matches the data 
Node *getNode(LinkedList *list, COMPARE compare, void *data) {
    Node *node = list->head;
    while(node != NULL) {
        if(compare(node->data, data)) 
            return node;
        node = node->next;
    }
    return NULL;
}

void delete(LinkedList *list, Node *node) {
    // node is head
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

int main() {
    LinkedList list;
    initList(&list);

    // add 3 elements
    int a = 1, b = 2, c = 3;
    addHead(&list, &a);
    addHead(&list, &b);
    addHead(&list, &c);

    // print the list
    printList(&list);

    // delete the first element
    delete(&list, list.head);
    printList(&list);

    // delete the last element
    delete(&list, list.tail);
    printList(&list);

    return 0;
}