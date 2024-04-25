// htab_clear.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia pre vymazanie vsetkych prvkov v tabulke

#include "htab_private.h"
#include <stdlib.h>

void htab_clear(htab_t * t) {
    // Iterates through the array of arrays
    for (size_t i = 0; i < t->arr_size; i++) {
        struct htab_item *item = t->arr[i];
        // Iterates through the single array and frees the items
        while (item != NULL) {
            struct htab_item *tmp = item->next;
            // Frees the key and the item
            free((char *)item->pair.key);
            free(item);
            item = tmp;
        }
        // Sets the array to NULL
        t->arr[i] = NULL;
    }
    // Sets the size to 0
    t->size = 0;
}
