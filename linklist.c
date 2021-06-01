#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "linklist.h"

void buildlinked(Node **makell, int num)
{
    Node **current = makell;
    Node *newnode = malloc(sizeof(Node));
    newnode->linknum = num;
    newnode->next = *current;
    *current = newnode;
}

void searchlinked(Node **makell, int tmp)
{
    Node **current = makell;
    Node *present;
    while(present = *current)
    {
        if((present->linknum) == tmp)return;
        current = &(present->next);
    }
}