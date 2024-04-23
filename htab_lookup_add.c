// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre najdenie polozky v tabulke alebo pridanie novej polozky ak sa nenajde

#include "htab_private.h"
#include <stdlib.h>

htab_pair_t *htab_lookup_add(htab_t * t, htab_key_t key) {
    
    if (t == NULL) {
        return NULL;
    }
    struct htab_item *item = htab_find(t, key);
    htab_pair_t *pair = malloc(sizeof(htab_pair_t));

    if (item != NULL) {
        //item->data++;
        
        pair->key = item->key;
        return pair;
    }
    
    struct htab_item *new_item = malloc(sizeof(struct htab_item));

    if (new_item == NULL) {
        return NULL;
    }
    size_t hash = htab_hash_function(key) % t->arr_size;
    if(t->arr[hash] == NULL) {
        t->arr[hash] = new_item;
    } else {
        struct htab_item *tmp = t->arr[hash];
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_item;
    }

    new_item->key = key;
    new_item->data = 1;
    new_item->next = NULL;
    t->size++;

    return new_item;

}
