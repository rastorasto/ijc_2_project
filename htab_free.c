// htab_free.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funkcia pre uvolnenie pamate alokovanej pre tabulku

#include "htab_private.h"
#include <stdlib.h>

void htab_free(htab_t * t) {
   // Clears the table items and frees the table
   htab_clear(t);
   free(t);
}
