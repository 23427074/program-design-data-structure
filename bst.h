#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifndef BST_H
#define BST_H

typedef struct tnode
{
    int bstnum;
    struct tnode *right;
    struct tnode *left;
}Tnode;

Tnode *buildbst(Tnode *makebst, int num, int *bstcnt)
{
    Tnode *current = makebst;
    if(current==NULL)
    {
        Tnode *current = malloc(sizeof(Tnode));
        current->bstnum = num;
        current->right = NULL;
        current->left = NULL;
        (*bstcnt)++;
        return current;
    }
    if(num>current->bstnum)
    {
        makebst->right = buildbst(makebst->right, num, bstcnt);
    }
    else if(num<current->bstnum)
    {
        makebst->left = buildbst(makebst->left, num, bstcnt);
    }
    return makebst;
}

void searchbst(Tnode *makebst, int tmp)
{
    if(makebst==NULL)return;
    if(tmp<makebst->bstnum)
    {
        searchbst(makebst->left, tmp);
    }
    else if(tmp>makebst->bstnum)
    {
        searchbst(makebst->right, tmp);
    }
    else
    {
        return;
    }
}

#endif