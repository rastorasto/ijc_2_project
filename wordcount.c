// tail.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include "htab_private.h"
#include "io.h"

#define MAX_WORD 256
#define MAX_TABLE 20000

void htab_print(htab_pair_t *data) {
    if(data != NULL){
        printf("%s\t%d\n", data->key, data->value);
    } else {
        printf("NULL\n");
    }
}

int main(void){
    htab_t *table = htab_init(MAX_TABLE);
    int read_word_value = 0;
    char word[MAX_WORD];
    while ((read_word_value = read_word(word, MAX_WORD, stdin)) != EOF && read_word_value != WORD_LENGTH_EXCEEDED) {
        htab_pair_t *item = htab_lookup_add(table, word);
        item->value++;
    }
    if(read_word_value == WORD_LENGTH_EXCEEDED){
        fprintf(stderr, "Word is too long\n");
    }

    htab_for_each(table, htab_print);

    htab_free(table);
    return 0;

}
