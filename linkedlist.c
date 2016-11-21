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

list *search_list(list *l, int x)
{
    if (l == NULL) return (NULL);
    
    if (l->item == x)
        return(l);
    else
        return(search_list(l->next, x));
}

void main()
{

    struct list MyList;
    MyList.item = 7;
    MyList.next = NULL;
    printf("Hello, World\n");
    list *ListHead = &MyList; 
    
    /* Lets try searching the list */
    list *SevenNode = search_list(ListHead, 7);
    printf("%p\n", (void *) SevenNode);
    SevenNode = search_list(ListHead, 6);
    printf("%p\n", (void *) SevenNode);    
}
