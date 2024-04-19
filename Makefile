# Makefile
# Řešení IJC-DU2, příklad 1), 13.04.2024
# Autor: Rastislav Uhliar, FIT
# Makefile na vytvorenie programu tail

CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra
TARGETS = tail

all: $(TARGETS)

tail.o: tail.c

tail: tail.o
	$(CC) $(CFLAGS) -o $@ $^

run : tail
	./tail lines.txt
	./tail -n 5 lines.txt
	./tail -n 8 <lines.txt
	./tail -n 19 <lines.txt 
	./tail -n 0 lines.txt
	./tail -n 25 lines.txt
	./tail -n 1 max_line.output

clean:
	rm -f *.o $(TARGETS)

zip:
	zip xuhlia00.zip *.c *.h Makefile