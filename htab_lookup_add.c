// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre najdenie polozky v tabulke alebo pridanie novej polozky ak sa nenajde

#include "htab_private.h"
#include <stdlib.h>

htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) {
    // Finds the item in the table and returns it if it exists
    struct htab_pair *item = item = htab_find(t, key);
    if (item != NULL) {
        return item;
    }
    // Allocates memory for the new item
    struct htab_item *new_item = malloc(sizeof(struct htab_item));
    if (new_item == NULL) {
        return NULL;
    }
    // Allocates memory for the key
    char* new_key = malloc(strlen(key) * sizeof(char) + 1);
    // Sets the values of the new item and increments the size of the table
    strcpy(new_key, key);
    new_item->pair.key = new_key;
    new_item->pair.value = 0;
    new_item->next = NULL;
    t->size++;

    size_t hash = htab_hash_function(key) % t->arr_size;
    // Sets temporary item to the first item in the array
    struct htab_item *tmp = t->arr[hash];
    // If the first item is NULL, it sets the new item as the first
    if(tmp == NULL){
        t->arr[hash] = new_item;
        return &(new_item->pair);
    }
    // Iterates through the array to the last item and sets the new item as the next
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = new_item;
    
    return &(new_item->pair);
}
