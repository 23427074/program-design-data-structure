#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef BS_H
#define BS_H

int *buildbs(int *makebs, int *bsarray, int generate)
{
    for(int i=0;i<generate;i++)
    {
        *(bsarray+i) = *(makebs+i);
    }
    return bsarray;
}

void searchbs(int *bsarray, int len, int tmp)
{
    int left = 0;
    int right = tmp - 1;
    while(left<right)
    {
        int mid = (left+right)/2;
        if(bsarray[mid] < len)
        {
            left = mid + 1;
        }
        else
        {
            right = mid + 1;
        }
    }
    right++;
}

#endif