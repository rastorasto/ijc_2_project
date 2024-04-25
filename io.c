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
    
    // If the first character is not a whitespace, put it into the string
    s[i] = charc;  
    
    // Read the rest of the word
    for(i = 1; i!=max-1; i++){
        // If the character is not a whitespace, put it into the string
        if(!isspace((charc = fgetc(f)))){
            s[i] = charc;
        }
        // If the character is a whitespace or EOF, end the string
        if (isspace(charc) || charc == EOF) {
            break;
        }
    }
    s[i] = '\0';
    if(i == max - 1){
        return WORD_LENGTH_EXCEEDED;
    }
    return i;
}
