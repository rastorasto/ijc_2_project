// htab_bucket_count.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Subor pre pocet prvkov v poli

#include "htab_private.h"

// Vrati pocet prvkov v poli
unsigned htab_bucket_count(const htab_t * t) {
    return t->arr_size;
}