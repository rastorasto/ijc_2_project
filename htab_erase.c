// htab_erase.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funcia pre vymazanie prvku z tabulky

#include "htab_private.h"
#include <stdlib.h>


bool htab_erase(htab_t * t, htab_key_t key) {
    // Gets the index of the key
    size_t index = htab_hash_function(key) % t->arr_size;
    struct htab_item *item = t->arr[index];
    struct htab_item *prev = NULL;
    // Iterates through the array with the index
    while (item != NULL) {
        // If the key is found, it deletes the item
        if (strcmp(item->pair.key, key) == 0) {
            // If the item is the first in the array, it sets the next item as the first
            if (prev == NULL) {
                t->arr[index] = item->next;
            }
            // Frees the key and the item and decrements the size
            free((char *)item->pair.key);
            free(item);
            t->size--;
            return true;
        }
        prev = item;
        item = item->next;
    }
    return false;
}
