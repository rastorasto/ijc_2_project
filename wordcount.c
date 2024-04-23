// tail.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include "htab.h"
#include "io.h"

#define MAX_WORD 127
#define MAX_TABLE 5000

void htab_print(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main(void){
    htab_t *table = htab_init(MAX_TABLE);
    if (table == NULL) {
        fprintf(stderr, "Error: Failed to initialize table\n");
        return 1;
    }

    char word[MAX_WORD + 1];
    while (read_word(word, MAX_WORD, stdin) != EOF) {
        htab_lookup_add(table, word);
    }

    htab_for_each(table, htab_print);

    htab_free(table);
    
    return 0;


}
