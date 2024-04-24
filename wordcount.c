// tail.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include "htab_private.h"
#include "io.h"

#define MAX_WORD 127
#define MAX_TABLE 10000

void htab_print(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main(void){
    htab_t *table = htab_init(MAX_TABLE);

    char word[MAX_WORD + 1];
    while (read_word(word, MAX_WORD, stdin) != EOF) {
        htab_pair_t *item = htab_lookup_add(table, word);
        item->value++;
    }

    htab_for_each(table, htab_print);

    // htab_lookup_add(table, "mnau");
    // htab_lookup_add(table, "vrrrr");
    // htab_lookup_add(table, "grrrr");
    // htab_for_each(table, htab_print);

    htab_free(table);
    return 0;


}
