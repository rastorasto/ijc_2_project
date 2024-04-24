// tail.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include "htab_private.h"
#include "io.h"

#define MAX_WORD 255
#define MAX_TABLE 1000

void htab_print(htab_pair_t *data) {
    if(data != NULL){
        printf("%s\t%d\n", data->key, data->value);
    } else {
        printf("NULL\n");
    }
}
// void print_address(htab_pair_t *data) {
//     printf("%p\n", data->key);
// }

int main(void){
    htab_t *table = htab_init(MAX_TABLE);

    char word[MAX_WORD + 1];
    while (read_word(word, MAX_WORD, stdin) != EOF) {
       // fprintf(stderr, "%s\n", word);
        htab_pair_t *item = htab_lookup_add(table, word);
        item->value++;
       // htab_for_each(table, htab_print);
        // item->key = word;
    }
    // printf("\n--------\n");
    htab_for_each(table, htab_print);
    // printf("\n--------\n");
    // htab_for_each(table, print_address);
    // htab_pair_t *a = htab_find(table, "a");
    // htab_pair_t *b = htab_find(table, "b");
    // htab_print(a);
    // htab_print(b);


    // printf("\n--------\n");
    // for (size_t i = 0; i < table->arr_size; i++) {
    //     struct htab_item *item = table->arr[i];
    //     while (item != NULL) {
    //         htab_print(&item->pair);
    //         item = item->next;
    //     }
    // }

    // htab_lookup_add(table, "mnau");
    // htab_lookup_add(table, "vrrrr");
    // htab_lookup_add(table, "grrrr");
    // htab_for_each(table, htab_print);

    htab_free(table);
    return 0;


}
