#ifndef BST_H
#define BST_H

typedef struct tnode
{
    int bstnum;
    struct tnode *right;
    struct tnode *left;
}Tnode;

Tnode *buildbst(Tnode *makebst, int num, int *bstcnt);
void searchbst(Tnode *makebst, int tmp);

#endif
