#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "array.h"
#include "linklist.h"
#include "bst.h"
#include "bs.h"
#include "hash.h"

void freehash(Hash *makehash)
{
    free(makehash->buckets);
}

void make(int *str, int generate)
{
    srand(time(NULL));
    int tmp=0;
    for(int i=0;i<generate;i++)
        *(str+i) = i;
    for(int i=0;i<generate;i++)
    {
        tmp = (rand()%generate);
        int swap = *(str+i);
        *(str+i) = *(str+tmp);
        *(str+tmp) = swap;
    }
}

int bscmp(const void *a, const void *b)
{
    return (*(int*)a-*(int*)b);
}

int main(int argc, char **argv)
{
    struct  timeval start;
    struct  timeval end;
    double arrtime, arrstime, lltime, llstime, bsttime, bststime, bstime, bsstime, hashtime, hashstime;
    srand(time(NULL));
    int generate = 0;
    int search = 0;
    int tmp = 0;
    int *str = NULL;
    for(int i=1; i<argc; i++)
    {
        if(strcmp(argv[i],"-d")==0)
        {
            if(strcmp(argv[i+1],"1e4")==0)
            {
                generate = 10000;
            }
            else if(strcmp(argv[i+1],"1e5")==0)
            {
                generate = 100000;
            }
            else if(strcmp(argv[i+1],"1e6")==0)
            {
                generate = 1000000;
            }
            else
            {
                generate = atoi(argv[i+1]);
            }
            str = malloc(sizeof(int)*generate);
            make(str, generate);
        }
        if(strcmp(argv[i],"-q")==0)
        {
            if(strcmp(argv[i+1],"1e3")==0)
            {
                search = 1000;
            }
            else if(strcmp(argv[i+1],"1e4")==0)
            {
                search = 10000;
            }
            else if(strcmp(argv[i+1],"1e5")==0)
            {
                search = 100000;
            }
            else
            {
                search = atoi(argv[i+1]);
            }
        }
        if(strcmp(argv[i],"-arr")==0)
        {
            gettimeofday(&start,NULL);
            buildarray(str, generate);
            gettimeofday(&end,NULL);
            arrtime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("arr:\n");
            printf("building time: %lf sec\n", arrtime);

            gettimeofday(&start,NULL);
            for(int i=0;i<search;i++)
            {
                tmp = (rand()%generate);
                searcharray(str, generate, tmp);
            }
            gettimeofday(&end,NULL);
            arrstime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("query time: %lf sec\n", arrstime);
        }
        if(strcmp(argv[i],"-ll")==0)
        {
            Node *makell = NULL;
            int llcnt=0;

            gettimeofday(&start,NULL);
            while(llcnt!=generate)
            {
                buildlinked(&makell, str[llcnt]);
                llcnt++;
            }
            gettimeofday(&end,NULL);
            lltime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("ll:\n");
            printf("building time: %lf sec\n", lltime);
            

            gettimeofday(&start,NULL);
            for(int j=0;j<search;j++)
            {
                tmp = (rand()%generate);
                searchlinked(&makell, tmp);
            }
            gettimeofday(&end,NULL);
            llstime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("query time: %lf sec\n", llstime);
            free(makell);
        }
        if(strcmp(argv[i],"-bst")==0)
        {
            Tnode *makebst = NULL;
            int bstcnt=0;

            gettimeofday(&start,NULL);
            while(bstcnt!=generate)
            {
                makebst = buildbst(makebst, str[bstcnt], &bstcnt);
            }
            gettimeofday(&end,NULL);
            bsttime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("bst:\n");
            printf("building time: %lf sec\n", bsttime);

            gettimeofday(&start,NULL);
            for(int i=0;i<search;i++)
            {
                tmp = (rand()%generate);
                searchbst(makebst, tmp);
            }
            gettimeofday(&end,NULL);
            bststime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("query time: %lf sec\n", bststime);
            free(makebst);
        }
        if(strcmp(argv[i],"-bs")==0)
        {
            int *makebs = malloc(sizeof(int)*generate);
            make(makebs,generate);
            int *bsarray = malloc(sizeof(int)*generate);

            gettimeofday(&start,NULL);
            bsarray = buildbs(makebs, bsarray, generate);
            qsort(bsarray,generate,sizeof(int),bscmp);
            gettimeofday(&end,NULL);
            bstime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("bs:\n");
            printf("building time: %lf sec\n", bstime);

            gettimeofday(&start,NULL);
            for(int i=0;i<search;i++)
            {
                tmp = (rand()%generate);
                searchbs(bsarray, generate, tmp);
            }
            gettimeofday(&end,NULL);
            bsstime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("query time: %lf sec\n", bsstime);
            free(makebs);
            free(bsarray);
        }
        if(strcmp(argv[i],"-hash")==0)
        {
            Hash *makehash;
            makehash = inithash(makehash, generate);
            int hashcnt=0;

            gettimeofday(&start,NULL);
            while(hashcnt!=generate)
            {
                buildhash(makehash, str[hashcnt]);
                hashcnt++;
            }
            gettimeofday(&end,NULL);
            hashtime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("hash:\n");
            printf("building time: %lf sec\n", hashtime);

            gettimeofday(&start,NULL);
            for(int j=0;j<search;j++)
            {
                tmp = (rand()%generate);
                searchhash(makehash, tmp);
            }
            gettimeofday(&end,NULL);
            hashstime = (double)((end.tv_sec*1000000+end.tv_usec)-(start.tv_sec*1000000+start.tv_usec))/1000000.0;
            printf("query time: %lf sec\n", hashstime);
            freehash(makehash);
        }
    }
    free(str);
}
