// htab_find.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre vyhladanie prvku v tabulke

#include "htab_private.h"

// htab_pair_t *htab_find(htab_t * t, htab_key_t key) {
//     if (t == NULL) {
//         return NULL;
//     }

//     size_t index = t->hash_fun(key) % t->arr_size;
//     htab_t *item = t->arr[index];

//     while (item != NULL) {
//         if (strcmp(item->pair.key, key) == 0) {
//             return &item->pair;
//         }
//         item = item->next;
//     }

//     return NULL;
// }