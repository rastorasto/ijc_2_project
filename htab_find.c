// htab_find.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre vyhladanie prvku v tabulke

#include "htab_private.h"
#include <stdlib.h>

htab_pair_t *htab_find(const htab_t * t, htab_key_t key) {
    // Gets first item in the table with the same hash
    struct htab_item *item = t->arr[htab_hash_function(key) % t->arr_size];

    // Iterates through the list of items with the same hash
    while (item != NULL) {
        // If the key is the same, return the item
        if (strcmp(item->pair.key, key) == 0) {
            return &(item->pair);
        }
        // Move to the next item
        item = item->next;
    }

    return NULL;
}
