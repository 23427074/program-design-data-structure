#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct node
{
    int linknum;
    struct node *next;
}Node;


void buildlinked(Node **makell, int num);
void searchlinked(Node **makell, int tmp);

#endif
