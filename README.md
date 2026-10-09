# IJC — Homework 2

FIT VUT course *Jazyk C* (IJC) homework #2, graded out of 15 points.

## What it does

- **`libhtab.a` / `libhtab.so`** — a full hash-table ADT with an opaque
  (incompletely declared) public struct and one module per operation:
  init, find, lookup_add, erase, clear, free, bucket statistics and
  `for_each`. Released as public domain.
- **`wordcount.c`** — classic word-frequency counter built on top of htab,
  with both a statically linked and a dynamically linked (`wordcount-dynamic`)
  variant.
- **`tail.c`** — the first sub-task: a POSIX-style `tail` printing the last
  *N* lines (default 10) from a file or stdin.

## Stack

C11 (`-O2 -fPIC`), `io.c` line reader, keys handled through `htab_private.h`.

## Build & run

```bash
make
./tail -n 20 big.log
cat words.txt | ./wordcount
```

Assignment (Czech): [ASSIGNMENT.md](ASSIGNMENT.md)
