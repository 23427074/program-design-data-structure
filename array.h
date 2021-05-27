#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef ARRAY_H
#define ARRAY_H

void buildarray(int *str, int generate)
{
    int *array = malloc(sizeof(int)*generate);
    for(int i=0;i<generate;i++)
    {
        *(array+i) = *(str+i);
    }
    free(array);
}

void searcharray(int *str, int len, int tmp)
{
    for(int i=0;i<len;i++)
    {
        if(*(str+i)==tmp)
        {
            return;
        }
    }
}

#endif