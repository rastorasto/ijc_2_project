// htab_hash_function.c
// Řešení IJC-DU2, příklad 2), 22.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia pre hashovanie klucov
#include "htab_private.h"
#include <stdint.h>

size_t htab_hash_function(const char *str) {
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}
