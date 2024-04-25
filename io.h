 // io.h
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Hlavickovy subor pre io.c

#ifndef _IO_H_
#define _IO_H_
 
#include<stdio.h>
// Word is always at least 1 character long and
// -1 is used for EOF so i decided to use 0
#define WORD_LENGTH_EXCEEDED 0

int read_word(char *s, int max, FILE *f);

#endif // _IO_H_
