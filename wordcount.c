// tail.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 128

typedef struct {
    char *word;
    int count;
} word_t;

typedef struct {
    int count;
    word_t *words;
} words_t;

int main(int argc, char **argv){
    (void)argv;
    (void)argc;
    words_t *words = malloc(sizeof(words_t));
    if(words == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    words->count = 0;
    char word[MAX_WORD_LENGTH];

   while(scanf("%s", word)==1){
        int exists = 0;
        for(int i=0; i<words->count; i++){
            if(strcmp(words->words[i].word, word)==0){
                words->words[i].count++;
                exists = 1;
                break;
            }
        }
        if(!exists){
            words->count++;
            words = realloc(words->words, words->count * sizeof(word_t));
            if(words == NULL){
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            words->words[words->count - 1].word = word;
            words->words[words->count - 1].count = 1;
        }
    }
    for (int i = 0; i < words->count; i++) {
        printf("%s %d\n", words->words[i].word, words->words[i].count);
        free(words->words[i].word);
    }
    free(words->words);
    free(words);
    return 0;
}
