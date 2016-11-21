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

typedef struct list {
    int item;                   /* data item */
    struct list *next;          /* point to successor */
} list;


void insert_list(list **l, int x)
{
    list *p;   /* temporary pointer */
       
    p = malloc( sizeof(list) );
    p->item = x;
    p->next = *l;
    *l = p;
}

void main()
{
    printf("Hello, World\n"); 
}
