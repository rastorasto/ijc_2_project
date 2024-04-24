// htab_private.h
// Řešení IJC-DU2, příklad 2), 21.04.2024
// Autor: Rastislav Uhliar, FIT
// Subor pre deklaraciu privatnych struktur

#ifndef _HTAB_PRIVATE_H_
#define _HTAB_PRIVATE_H_

#include "htab.h"

struct htab_item {
    htab_pair_t pair;
    struct htab_item *next;
};

struct htab {
    size_t arr_size;
    size_t size;
    struct htab_item *arr[];
};

#endif // _HTAB_PRIVATE_H_
