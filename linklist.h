#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct node
{
    int linknum;
    struct node *next;
}Node;


Node *buildlinked(Node *makell, int num, int *llcnt, int generate)
{
    if(makell == NULL)
    {
        Node *firstnode = malloc(sizeof(Node));
        makell = firstnode;
        firstnode->linknum = num;
        makell->next = NULL;
        (*llcnt)++;
        return makell;
    }
    Node *newnode = malloc(sizeof(Node));
    newnode->linknum = num;
    newnode->next = makell;
    makell = newnode;
    (*llcnt)++;
    return makell;
}

void searchlinked(Node *makell, int tmp)
{
    if(makell==NULL)return;
    Node *current = makell;
    while(current)
    {
        if((current->linknum)==tmp)
        {
            return;
        }
        current = current->next;
    }
}

#endif