// tail.c
// Řešení IJC-DU2, příklad 1), 13.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 2047 * sizeof(char)

typedef struct {
    int size;
    int possition;
    int used;
    char **buffer;
} cbuf_t;

cbuf_t *cbuf_create(int n){
    if(n < 0){
        return NULL;
    }
    cbuf_t *cb = malloc(sizeof(cbuf_t));
    if(cb == NULL){
        return NULL;
    }
    cb->size = n;
    cb->possition = 0;
    cb->used = 0;

    cb->buffer = malloc(n * sizeof(char *));

    if(cb->buffer == NULL){
        free(cb);
        return NULL;
    }

    for(int i = 0; i < n; i++){
        cb->buffer[i] = malloc(BUFFER_SIZE * sizeof(char));
        if(cb->buffer[i] == NULL){
            for(int j = 0; j < i; j++){
                free(cb->buffer[j]);
            }
            free(cb->buffer);
            free(cb);
            return NULL;
        }
    }
    return cb;
}

bool cbuf_put(cbuf_t *cb, char *line){
    if(cb == NULL || line == NULL){
        return false;
    }
    strncpy(cb->buffer[cb->possition], line, BUFFER_SIZE);

    cb->possition = (cb->possition + 1) % cb->size;
    if(cb->used < cb->size){
        cb->used++;
    }
    return true;
}

char *cbuf_get(cbuf_t *cb){
    if(cb == NULL){
        return NULL;
    }
    return cb->buffer[cb->possition];

} 

void cbuf_free(cbuf_t *cb){
    for(int i = 0; i < cb->size; i++){
        free(cb->buffer[i]);
    }
    free(cb->buffer);
    free(cb);

}

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
    } else {
        fprintf(stderr, "Neplatne argumenty\n");
        return 1;
    }

    fprintf(stdout, "\nNumber of lines: %d\n", number_of_lines);
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    return 0; 
}
