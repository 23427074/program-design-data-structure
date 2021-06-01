#include "hash.h"

size_t hashvalue(int num)
{
    return (num*33+5381)*33+5381;
}

size_t hashidx(int size, int num)
{
    return (hashvalue(num))%size;
}

void buildhash(Hash *makehash, int num)
{
    size_t idx = hashidx(makehash->size, num);
    buildlinked(makehash->buckets+idx, num);
}

void searchhash(Hash *makehash, int tmp)
{
    size_t idx = hashidx(makehash->size, tmp);
    searchlinked(makehash->buckets+idx, tmp);
}

Hash *inithash(Hash *makehash, int generate)
{
    makehash = malloc(sizeof(Hash));
    makehash->buckets = malloc(sizeof(Node*)*generate);
    for(int i=0;i<generate;i++)
    {
        makehash->buckets[i] = NULL;
    }
    makehash->size = generate;
    return makehash;
}