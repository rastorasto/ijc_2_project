// htab_statistics.c
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Subor pre vypocet a tlac statistik dlzky zoznamov

#include "htab_private.h"
#include <stdio.h>

void htab_statistics(htab_t *t) {
    size_t min = 0;
    size_t max = 0;
    size_t avg = 0;
    struct htab_item *item = t->arr[0];
    for (unsigned i = 1; i < t->arr_size; i++,item->next) {
        if (min == 0 || i < min) {
            min = i;
        }
        if (i > max) {
            max = i;
        }
        avg += i;
    }
    avg /= t->size;
    fprintf(stderr, "Minimum lenght of array: %lu", min);
    fprintf(stderr, "Maximum lenght of array: %lu", max);
    fprintf(stderr, "Average lenght of array: %lu", avg);

}