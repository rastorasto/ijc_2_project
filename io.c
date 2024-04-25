// io.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Funckia na nacitanie slova zo suboru

#include "io.h"
#include <ctype.h>

int read_word(char *s, int max, FILE *f){
    int charc = 0;
    int i = 0;
    // Skip whitespaces
    while(isspace(charc = fgetc(f)));
    
    // If the file is empty or contains only whitespaces return EOF
    if(charc == EOF){
        return EOF;
    }
    
    // Reads the word until it reaches a whitespace or EOF
    do{
        // If it reaches the max length of the word it returns WORD_LENGTH_EXCEEDED
        if(i == max-1){
            s[max-1] = '\0';
            return WORD_LENGTH_EXCEEDED;
        }
        s[i] = charc;
        i++;
    }while(!isspace(charc = fgetc(f)) && charc != EOF);

    // Adds the null terminator to the end of the string
    s[i] = '\0';
    return i;
}

