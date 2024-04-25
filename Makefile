# Makefile
# Řešení IJC-DU2, příklad 1), 13.04.2024
# Autor: Rastislav Uhliar, FIT
# Makefile na vytvorenie programu tail

CC = gcc
AR = ar
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra
TARGETS = tail wordcount wordcount-dynamic libhtab.a libhtab.so

MODULES = htab_bucket_count.o \
	htab_clear.o \
	htab_erase.o \
	htab_find.o \
	htab_for_each.o \
	htab_free.o \
	htab_hash_function.o \
	htab_init.o \
	htab_lookup_add.o \
	htab_size.o \
	htab_statistics.o
all: $(TARGETS)

tail.o: tail.c
wordcount.o: wordcount.c htab.h io.h


libhtab.a: $(MODULES)
	$(AR) rcs $@ $^

libhtab.so: $(MODULES)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^

tail: tail.o
	$(CC) $(CFLAGS) -o $@ $^

wordcount: wordcount.o libhtab.a io.o
	$(CC) $(CFLAGS) -o $@ $^

wordcount-dynamic: wordcount.o libhtab.so io.o
	$(CC) $(CFLAGS) -o $@ $^ -fPIC
	

run : tail wordcount
	# ./tail lines.txt
	# ./tail -n 5 lines.txt
	# ./tail -n 8 <lines.txt
	./wordcount <char.input
	export LD_LIBRARY_PATH="."
	./wordcount-dynamic <char.input

clean:
	rm -f *.o $(TARGETS)

zip:
	zip xuhlia00.zip *.c *.h Makefile

htab_bucket_count.o: htab_bucket_count.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_clear.o: htab_clear.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_erase.o: htab_erase.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_find.o: htab_find.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_for_each.o: htab_for_each.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_free.o: htab_free.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_hash_function.o: htab_hash_function.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_init.o: htab_init.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_lookup_add.o: htab_lookup_add.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_size.o: htab_size.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<

htab_statistics.o: htab_statistics.c htab_private.h
	$(CC) $(CFLAGS) -c -o $@ $<