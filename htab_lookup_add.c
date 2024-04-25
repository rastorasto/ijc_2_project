// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre najdenie polozky v tabulke alebo pridanie novej polozky ak sa nenajde

#include "htab_private.h"
#include <stdlib.h>

htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) {
    struct htab_pair *item = NULL;
    item = htab_find(t, key);
    if (item != NULL) {
        return item;
    }

    struct htab_item *new_item = malloc(sizeof(struct htab_item));
    if (new_item == NULL) {
        return NULL;
    }
    char* new_key = malloc(strlen(key) * sizeof(char) + 1);
    strcpy(new_key, key);
    new_item->pair.key = new_key;
    new_item->pair.value = 0;
    new_item->next = NULL;
    t->size++;

    size_t hash = htab_hash_function(key) % t->arr_size;
    struct htab_item *tmp = t->arr[hash];
    if(tmp == NULL){
        t->arr[hash] = new_item;
        return &(new_item->pair);
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = new_item;

    return &(new_item->pair);
}
