 // io.h
// Řešení IJC-DU2, příklad 2), 19.04.2024
// Autor: Rastislav Uhliar, FIT
// Hlavickovy subor pre io.c

#ifndef _IO_H_
#define _IO_H_
 
#include<stdio.h>
#define WORD_LENGTH_EXCEEDED -2

int read_word(char *s, int max, FILE *f);

#endif // _IO_H_
