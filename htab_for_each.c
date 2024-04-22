// htab_for_each.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia ktora vykona funkciu pre kazdy prvok v tabulke

#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    if (t == NULL) {
        return;
    }

    for (size_t i = 0; i < t->arr_size; i++) {
        struct htab_item *item = t->arr[i];
        while (item != NULL) {
            f(item);
            item = item->next;
        }
    }
}
