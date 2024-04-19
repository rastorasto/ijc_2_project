// tail.c
// Řešení IJC-DU2, příklad 1), 13.04.2024
// Autor: Rastislav Uhliar, FIT
// Program na vypisovanie poslednych n riadkov suboru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 2047 characters  + 1 character for '\0'
#define BUFFER_SIZE 2048 * sizeof(char)

typedef struct {
    int size;
    int possition;
    int used;
    char **buffer;
} cbuf_t;

cbuf_t *cbuf_create(int number_of_lines);
int cbuf_put(cbuf_t *cb, char *line);
char *cbuf_get(cbuf_t *cb);
void cbuf_free(cbuf_t *cb);
int save_to_cbuf(cbuf_t *cb, FILE* file);
void print_cbuf(cbuf_t *cb);

int main(int argc, char *argv[]){
    int number_of_lines = 10;
    int nflag_index = 0;
    FILE *file = stdin;
    // Check if the number of lines is specified and sets the number_of_lines variable
    if (argc > 2 && strcmp(argv[1], "-n") == 0){
        nflag_index = 1;
        // Checks if the argument is a number
        for(unsigned int i = 0; i < strlen(argv[2]); i++){
            if(!isdigit(argv[2][i])){
                fprintf(stderr, "Invalid number of lines\n");
                return 1;
            }
        }
        number_of_lines = atoi(argv[2]);
    } else if (argc > 3 && strcmp(argv[2], "-n") == 0){
        nflag_index = 2;
        // Checks if the argument is a number
        for(unsigned int i = 0; i < strlen(argv[3]); i++){
            if(!isdigit(argv[3][i])){
                fprintf(stderr, "Invalid number of lines\n");
                return 1;
            }
        }
        number_of_lines = atoi(argv[3]);
    }

    // According to the nflag_index, opens the file
    if(nflag_index == 1 && argc == 4){
        file = fopen(argv[3], "r");
        if(file==NULL){
            fprintf(stderr, "File could not be opened.\n");
            return 1;
        }
    } else if (nflag_index == 2 && argc == 4){
        file = fopen(argv[1], "r");
        if(file==NULL){
            fprintf(stderr, "File could not be opened.\n");
            return 1;
        }
    } else if(argc == 2){ // If the file is not specified, open stdin
        file = fopen(argv[1], "r");
        if(file==NULL){
            fprintf(stderr, "File could not be opened.\n");
            return 1;
        }
    }
    // Creates a new circular buffer
    cbuf_t *cb = cbuf_create(number_of_lines);
    if(cb == NULL){
        fprintf(stderr, "Invalid number of lines\n");
        return 0;
    }
    // Save the lines from the file to the circular buffer
    if (save_to_cbuf(cb,file)){
        fprintf(stderr, "Malloc failed\n");
        return 1;
    }
    // Print the lines from the circular buffer
    print_cbuf(cb);

    // Free the circular buffer and close the file
    cbuf_free(cb);
    fclose(file);
    return 0; 
}

// Create a new circular buffer with number_of_lines lines
cbuf_t *cbuf_create(int number_of_lines){
    // If number of lines is less or equal to 0, return NULL
    if(number_of_lines <= 0){
        return NULL;
    }
    // Allocate memory for the circular buffer
    cbuf_t *cb = malloc(sizeof(cbuf_t));
    if(cb == NULL){
        return NULL;
    }
    cb->size = number_of_lines;
    cb->possition = 0;
    cb->used = 0;
    // Allocate memory for the buffer
    cb->buffer = malloc(number_of_lines * sizeof(char *));

    if(cb->buffer == NULL){
        free(cb);
        return NULL;
    }
    // Allocate memory for each line in the buffer
    for(int line_index = 0; line_index < number_of_lines; line_index++){
        cb->buffer[line_index] = malloc(BUFFER_SIZE * sizeof(char));
        // If malloc fails, free all the allocated memory and return NULL
        if(cb->buffer[line_index] == NULL){
            for(int free_line_index = 0; free_line_index < line_index; free_line_index++){
                free(cb->buffer[free_line_index]);
            }
            free(cb->buffer);
            free(cb);
            return NULL;
        }
    }
    return cb;
}

// Put a line to the circular buffer
int cbuf_put(cbuf_t *cb, char *line){
    if(cb == NULL || line == NULL){
        return 1;
    }
    // Copy the line to the buffer and move the possition
    strncpy(cb->buffer[cb->possition], line, BUFFER_SIZE);
    cb->possition++;

    if(cb->possition == cb->size){
        cb->possition = 0;
    }
    // If the buffer is not full, increment the used variable
    if(cb->used < cb->size){
        cb->used++;
    }
    return 0;
}

// Get a line from the circular buffer at the current possition 
char *cbuf_get(cbuf_t *cb){
    return cb->buffer[cb->possition];
} 

// Free the circular buffer and all the allocated memory
void cbuf_free(cbuf_t *cb){
    for(int i = 0; i < cb->size; i++){
        free(cb->buffer[i]);
    }
    free(cb->buffer);
    free(cb);

}

// Save the lines from the file to the circular buffer
int save_to_cbuf(cbuf_t *cb, FILE* file){
    char *line = malloc(BUFFER_SIZE);
    if(line == NULL){
        cbuf_free(cb);
        return 1;
    }
    // Read the lines from the file and put them to the circular buffer
    while(fgets(line, BUFFER_SIZE, file) != NULL){
        // If the line is longer than the buffer, read the rest of the line and discard it
        if(strlen(line) == BUFFER_SIZE - 1 && line[BUFFER_SIZE - 2] != '\n'){
            int c;
            for (; (c = fgetc(file)) != '\n' && c != EOF; );
        }
        cbuf_put(cb, line);
    }
    free(line);
    return 0;
}

// Print the lines from the circular buffer
void print_cbuf(cbuf_t *cb){
    char *line_to_print;
    // Prints all the used lines in the circular buffer
    for(int line_index = 0; line_index < cb->used; line_index++){
        if(cb->possition == cb->used){
            cb->possition = 0;
        }
        line_to_print = cbuf_get(cb);
        cb->possition = (cb->possition + 1) % cb->size;
        printf("%s", line_to_print);
        // If the line does not end with '\n', print '\n'
        if(line_to_print[strlen(line_to_print) - 1] != '\n'){
            printf("\n");
        }
    }
}
