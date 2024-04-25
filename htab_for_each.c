// htab_for_each.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia ktora vykona funkciu pre kazdy prvok v tabulke

#include "htab_private.h"
#include <stdlib.h>

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    struct htab_item *item;
    // Iterates through the array of arrays
    for (size_t i = 0; i < t->arr_size; i++) {
        // Sets item to the current array
        item = t->arr[i];
        // Iterates through the single array and calls the function
        while (item != NULL) {
            f(&(item->pair));
            item = item->next;
        }
    }
}
