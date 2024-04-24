// htab_erase.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funcia pre vymazanie prvku z tabulky

#include "htab_private.h"
#include <stdlib.h>

bool htab_erase(htab_t * t, htab_key_t key) {
    if (t == NULL) {
        return false;
    }

    size_t index = htab_hash_function(key) % t->arr_size;
    struct htab_item *item = t->arr[index];
    struct htab_item *prev = NULL;

    while (item != NULL) {
        if (strcmp(item->pair.key, key) == 0) {
            if (prev == NULL) {
                t->arr[index] = item->next;
            } else {
                prev->next = item->next;
            }
            free(item);
            t->size--;
            return true;
        }
        prev = item;
        item = item->next;
    }
    return false;
}
