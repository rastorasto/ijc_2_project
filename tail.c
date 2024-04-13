// tail.c
// Řešení IJC-DU2, příklad 1), 13.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cbuf_create(int n){

// }

// cbuf_put(cb, line){

// }

// cbuf_get(cb){

// } 

// cbuf_free(cb){

// }

int main(int argc, char *argv[]){
    int number_of_lines = 10;
    FILE *file = stdin;
    if(strcmp(argv[1], "-n") == 0 && argc > 2){
        number_of_lines = atoi(argv[2]);
        if(number_of_lines < 0){
            fprintf(stderr, "Neplatny pocet riadkov\n");
            return 1;
        }
        if(argc == 4){
            file = fopen(argv[3], "r");
            if(file==NULL){
                fprintf(stderr, "Subor sa nepodarilo otvorit\n");
                return 1;
            }
        }
    } else if(argc == 2){
        file = fopen(argv[1], "r");
        if(file==NULL){
            fprintf(stderr, "Subor sa nepodarilo otvorit\n");
            return 1;
        }
    }
    fprintf(stdout, "\nNumber of lines: %d\n", number_of_lines);
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    return 0; 
}
