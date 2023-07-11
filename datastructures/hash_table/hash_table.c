#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "double_linked_list.h"
#define m 5

typedef struct {
    int32_t key;
    char* data;  
} ht_item_t;

int32_t hash_division(int32_t k) {
    return k % m;
}

void chained_hash_insert(ll_t T[], ht_item_t* x) {
    int32_t k = hash_division(x->key);
    list_prepend(&T[k], x);
}

ht_item_t chained_hash_search(ll_t T[], int32_t key) {
    int32_t k = hash_division(key);
    node_t *node = list_search(&T[k], compareInt, &key);
    return *(ht_item_t *)node->data;
}   

void chained_hash_delete(ll_t T[], ht_item_t* x) {
    int32_t k = hash_division(x->key);
    node_t *node = list_search(&T[k], compareInt, &x->key);
    delete_node(&T[hash_division(x->key)], node);
}

int main(int argc, char** argv) {
    ll_t T[m];

    for(int i = 0; i < m; i++) {
        init_ll(&T[i]);
    }

    // create and insert 20 items 
    for(int i = 0; i < 20; i++) {
        ht_item_t *item = (ht_item_t *)malloc(sizeof(ht_item_t));
        item->key = i;
        item->data = (char *)malloc(sizeof(char) * 10);
        sprintf(item->data, "item%d", i);
        chained_hash_insert(T, item);
    }

    for(int i = 0; i < m; i++) {
        print_ll(&T[i]);
    }

    // search for item with key 5
    ht_item_t item = chained_hash_search(T, 5);
    printf("item with key 5: %s\n", item.data);

    // delete item with key 5
    print_ll(&T[hash_division(5)]);
    chained_hash_delete(T, &item);
    print_ll(&T[hash_division(5)]);
}