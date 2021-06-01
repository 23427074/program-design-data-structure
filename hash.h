#include <stdio.h>
#include <stdlib.h>
#ifndef HASH_H
#define HASH_H
#include "linklist.h"

typedef struct hash
{
    Node **buckets;
    int size;
}Hash;

size_t hashvalue(int num);
size_t hashidx(int size, int num);
void buildhash(Hash *makehash, int num);
void searchhash(Hash *makehash, int tmp);
Hash *inithash(Hash *makehash, int generate);

#endif 