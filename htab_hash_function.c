// htab_hash_function.c
// Řešení IJC-DU2, příklad 2), 22.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia pre hashovanie klucov pomocou djb2
//
// Djb2 hash function
// Zdroj: http://www.cse.yorku.ca/~oz/hash.html
// Prevzane 22.4.2024
//

#include "htab_private.h"

size_t htab_hash_function(htab_key_t str) {

    size_t hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

   return hash;
}
