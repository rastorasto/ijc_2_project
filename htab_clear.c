// htab_clear.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia pre vymazanie vsetkych prvkov v tabulke

#include "htab_private.h"
#include <stdlib.h>

void htab_clear(htab_t * t) {
    for (size_t i = 0; i < t->arr_size; i++) {
        struct htab_item *item = t->arr[i];
        while (item != NULL) {
            struct htab_item *tmp = item->next;
            free(item);
            item = tmp;
        }
        t->arr[i] = NULL;
    }
    t->size = 0;
}
