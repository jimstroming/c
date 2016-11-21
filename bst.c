/* ========================================================================== */
/*                                                                            */
/*   Filename.c                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int item;                /* data item */
    struct tree *parent;     /* pointer to parent */
    struct tree *left;       /* pointer to left child */
    struct tree *right;      /* pointer to right child */

}   tree;


insert_tree(tree **l, int x, tree *parent)
{
    tree *p;                       /* temporary pointer */
    
    if (*l == NULL) {
        p = malloc(sizeof(tree));  /* allocate new node */
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;                    /* link into parent's record */
        return;
    }
    
    if (x < (*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);        
}


tree *search_tree(tree *l, int x)
{
    if (l == NULL) return(NULL);
    if (l->item == x) return(l);
    if (x < l->item)
        return (search_tree(l->left, x));
    else
        return (search_tree(l->right, x));
}

void print_tree(tree *l)
{
    if (l != NULL){
        print_tree(l->left);
        printf("%d",l->item);
        printf("\n");
        print_tree(l->right);
    }
}

void main()
{

    tree *MyTree = NULL;

    
    insert_tree(&MyTree, 7, NULL);
    insert_tree(&MyTree, 14, NULL);
    insert_tree(&MyTree, 3, NULL);
    insert_tree(&MyTree, 2, NULL);
    insert_tree(&MyTree, 1, NULL);
    insert_tree(&MyTree, 10000, NULL);
    insert_tree(&MyTree, 10001, NULL);
    insert_tree(&MyTree, 9999, NULL);
    insert_tree(&MyTree, 12, NULL);
    insert_tree(&MyTree, 0, NULL);
    insert_tree(&MyTree, 9998, NULL);


    print_tree(MyTree);
    
    printf("Search for node 9999\n");
    tree *node9999 = search_tree(MyTree, 9999);
    printf("%d",node9999->item); 
    printf("\n");

}
