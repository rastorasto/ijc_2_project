// tail.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include "htab_private.h"
#include "io.h"

#define MAX_WORD 127
#define MAX_TABLE 100

void htab_print(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main(void){
    htab_t *table = htab_init(MAX_TABLE);
    // if (table == NULL) {
    //     fprintf(stderr, "Error: Failed to initialize table\n");
    //     return 1;
    // }

    // char word[MAX_WORD + 1];
    // while (read_word(word, MAX_WORD, stdin) != EOF) {
    //     htab_lookup_add(table, word);
    // }

    // htab_for_each(table, htab_print);

    // htab_free(table);
    htab_lookup_add(table, "ahoj");
    printf("size %zu\n", htab_size(table));
    printf("arr size %zu\n", htab_bucket_count(table));
    htab_pair_t *par = htab_find(table, "ahoj");
    htab_print(par);
    htab_pair_t *par2 = htab_find(table, "cus");
    htab_print(par2);
    // htab_lookup_add(table, "ahoj");
    // htab_lookup_add(table, "ahoj");
    // htab_lookup_add(table, "kokot");
    // htab_lookup_add(table, "ahoj2");
    // htab_lookup_add(table, "pica");
    // int hodnota = htab_size(table);
    // int hodnota2 = htab_bucket_count(table);
    // printf("size %d\n", hodnota);
    // printf("arr size %d\n", hodnota2);

    // htab_pair_t *pair = htab_find(table, "ahoj");
    // htab_pair_t *pair2 = htab_find(table, "kokot");
    // htab_pair_t *pair3 = htab_find(table, "ahoj2");
    // htab_pair_t *pair4 = htab_find(table, "pica");
    // htab_print(pair);
    // htab_print(pair2);
    // htab_print(pair3);
    // htab_print(pair4);
    // printf("\n");
    // htab_for_each(table, htab_print);

    //htab_pair_t *item = htab_find(table, "vyjebany_kokot");
   // htab_print(item);

    htab_free(table);

    return 0;


}
