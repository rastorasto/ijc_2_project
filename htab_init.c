// htab_init.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Subor pre inicializaciu hashovacej tabulky

#include "htab_private.h"
#include <stdlib.h>

htab_t *htab_init(size_t n) {
    // Allocate memory for the table and its array
    htab_t *t = malloc(sizeof(htab_t) + n * sizeof(struct htab_item *));
    if (t == NULL) {
        return NULL;
    }
    // Set the size of the array and the table
    t->arr_size = n;
    t->size = 0;
    // Initialize the array to NULL pointers
    for (size_t i = 0; i < n; i++) {
        t->arr[i] = NULL;
    }
    return t;
}
