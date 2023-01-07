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
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

void addHead(LinkedList *list, void *data) {
    Node *node = nodeConstructor(list, data);
    if(list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    }
    list->head = node;
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
    if (node == list->head) {
        if(list->head->next == NULL) {       
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        Node *temp = list->head;
        while(temp != NULL && temp->next != node) 
            temp = temp->next;
        
        if(temp != NULL) temp->next = node->next;
    }
    free(node);
}

int main() {
    // init the list
    LinkedList list;
    initList(&list);

    // add some data
    int a = 1, b = 2, c = 3;
    addHead(&list, &a);
    addHead(&list, &b);
    addHead(&list, &c);
    
    addTail(&list, &a);
    addTail(&list, &b);
    addTail(&list, &c);

    // print the list
    printList(&list);


    // find a node
    int key = 3;
    Node *node = getNode(&list, compareInt, &key);
    if(node != NULL) {
        printf("Found node with data: %d\n", *(int*)node->data);
    } else {
        printf("Node not found\n");
    }
    
    // delete a node
    delete(&list, node);
    printList(&list);

    // destroy the list
    destroyList(&list);

    return 0;
}