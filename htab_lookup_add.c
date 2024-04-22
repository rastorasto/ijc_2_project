// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre najdenie polozky v tabulke alebo pridanie novej polozky ak sa nenajde

#include "htab_private.h"

htab_pair_t *htab_lookup_add(htab_t * t, htab_key_t key) {
    
    if (t == NULL) {
        return NULL;
    }
    struct htab_item *item = htab_find(t, key);

    if (item != NULL) {
        item->data++;
        return item;
    }
    
    struct htab_item *item = malloc(sizeof(struct htab_item));
    
    if (item == NULL) {
        return NULL;
    }
    size_t hash = htab_hash_function(key) % t->arr_size;
    if(t->arr[hash] == NULL) {
        t->arr[hash] = item;
    } else {
        struct htab_item *tmp = t->arr[hash];
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = item;
    }

    item->key = key;
    item->data = 1;
    item->next = NULL;
    t->size++;

    return item;

}