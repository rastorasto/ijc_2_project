// htab_for_each.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia ktora vykona funkciu pre kazdy prvok v tabulke

#include "htab_private.h"
#include <stdlib.h>

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    if (t == NULL) {
        return;
    }
    struct htab_item *item;
    for (size_t i = 0; i < t->arr_size; i++) {
        item = t->arr[i];
        while (item != NULL) {
            htab_pair_t *data = malloc(sizeof(htab_pair_t));
            data->key = item->key;
            data->value = item->data;
            f(data);
            free(data);
            item = item->next;
        }
    }
}
