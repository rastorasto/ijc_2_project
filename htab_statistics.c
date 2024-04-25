// htab_statistics.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Subor pre vypocet a tlac statistik dlzky zoznamov

#include "htab_private.h"
#include <stdio.h>

void htab_statistics(const htab_t *t) {
    size_t min = 0;
    size_t max = 0;
    size_t avg = t->size / t->arr_size;
    size_t count = 0;
    // Iterates through the first array to set min max values
    struct htab_item *item = t->arr[0];
    while(item != NULL){
        min++;
        max++;
        item=item->next;
    }
    // Itterates through the rest of the arrays
    for (unsigned i = 1; i < t->arr_size; i++) {
        count = 0;
        // Iterates through the array and counts the items
        while(item != NULL){
            count++;
            item=item->next;
        }
        // Compares min and max and sets the new values
        if (count < min) {
            min = count;
        }
        if (count > max) {
            max = count;
        }
    }
    // Prints the statistics
    fprintf(stderr, "Minimum lenght of array: %lu", min);
    fprintf(stderr, "Maximum lenght of array: %lu", max);
    fprintf(stderr, "Average lenght of array: %lu", avg);

}
