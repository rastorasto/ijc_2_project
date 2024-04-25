// tail.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include "htab_private.h"
#include "io.h"

#define MAX_WORD 256 // 255 + '\0'
#define MAX_TABLE 20000 

// Function to print htab_pair_t key and value
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
    int read_word_error = 0;
    char word[MAX_WORD];
    // Reads the words from the stdin and adds them to the hash table
    while ((read_word_value = read_word(word, MAX_WORD, stdin)) != EOF) {
        // If the word is too long, it prints an error message once
        if(read_word_error == 0 && read_word_value == WORD_LENGTH_EXCEEDED){
            read_word_error = 1;
            fprintf(stderr, "Word is too long\n");
        }
        // Gets the htab_pair_t item and increments the value
        htab_pair_t *item = htab_lookup_add(table, word);
        item->value++;
    }
    // Prints the hash table
    htab_for_each(table, htab_print);

    // If we compile with the STATISTICS flag, it prints the statistics
    #ifdef STATISTICS
        htab_statistics(table);
    #endif

    htab_free(table);
    return 0;

}
