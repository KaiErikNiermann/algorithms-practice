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
    Node *current;
    Node *sentinel;
    int size;
} LinkedList;

void initList(LinkedList *list) {
    list->sentinel = (Node *)malloc(sizeof(Node));
    list->sentinel->next = list->sentinel->prev = list->sentinel;
    list->size = 0;
}

Node *nodeConstructor(LinkedList *list, void *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    return node;
}

void insertAfter(LinkedList *list, void *data, Node *prevNode) {
    Node *node = nodeConstructor(list, data);
    node->next = prevNode->next;
    node->prev = prevNode;
    prevNode->next->prev = node;
    prevNode->next = node;
}

void deleteNode(LinkedList *list, Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

Node *getNode(LinkedList *list, void *data, COMPARE compare) {
    Node *node = list->sentinel->next;
    while(node != list->sentinel) {
        if(compare(node->data, data)) return node;
        
        node = node->next;
    }
    return NULL;
}

void printList(LinkedList *list) {
    Node *node = list->sentinel->next;
    while(node != list->sentinel) {
        printf("%d ", *(int *)node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    initList(&list);

    // add 3 elements
    int a = 1, b = 2, c = 3;
    insertAfter(&list, &a, list.sentinel);
    insertAfter(&list, &b, list.sentinel);
    insertAfter(&list, &c, list.sentinel);

    // print the list
    printList(&list);

    // delete a node
    deleteNode(&list, list.sentinel->next);
    printList(&list);

    // get a node
    Node *node = getNode(&list, &b, compareInt);
    printf("%d\n", *(int *)node->data);

    return 0;
}