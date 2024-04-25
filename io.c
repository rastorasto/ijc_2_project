// io.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Subor pre implementaciu io.h

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
    
    do{
        if(i == max-1){
            s[max-1] = '\0';
            return WORD_LENGTH_EXCEEDED;
        }
        s[i] = charc;
        i++;
    }while(!isspace(charc = fgetc(f)) && charc != EOF);

    s[i] = '\0';
    return i;
}

