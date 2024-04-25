// io.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Subor pre vratenie poctu zaznamov v tabulke

#include "htab_private.h"

size_t htab_size(const htab_t * t) {
    return t->size;
}
