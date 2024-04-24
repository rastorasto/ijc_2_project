// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre najdenie polozky v tabulke alebo pridanie novej polozky ak sa nenajde

#include "htab_private.h"
#include <stdlib.h>

htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) {
    size_t hash = htab_hash_function(key) % t->arr_size;
    struct htab_item *item = t->arr[hash];

    while (item != NULL) {
        if (strcmp(item->pair.key, key) == 0) {
            return &(item->pair);
        }
        item = item->next;
    }
    struct htab_item *new_item = malloc(sizeof(struct htab_item));
    if (new_item == NULL) {
        return NULL;
    }
    
    new_item->pair.key = (char *)malloc(strlen(key) + 1);
    strcpy(new_item->pair.key, key);
    new_item->pair.value = 0;
    new_item->next = NULL;
    t->size++;
    if (item == NULL) {
        t->arr[hash] = new_item;
    } else {
        item->next = new_item;
    }
    return &(new_item->pair);
}
