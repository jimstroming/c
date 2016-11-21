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

void print_list(list *l)
{
    if (l == NULL){
        printf("\n");
        return;
    }
    printf("%d",l->item);
    
    return print_list(l->next);
}

list *predecessor_list(list *l, int x)
{
    if ((l == NULL ) || (l->next == NULL)){
        // predecessor sought on null list
        return(NULL);    
    }
    
    if ((l->next)->item == x)
        return(l);
    else
        return(predecessor_list(l->next,x));
}

void main()
{

    struct list MyList;
    MyList.item = 7;
    MyList.next = NULL;
    printf("Hello, World\n");
    list *ListHead = &MyList; 

    /* Insert a couple of nodes */
    insert_list(&ListHead, 6);
    insert_list(&ListHead, 4);
        
    /* Try searching the list */
    list *SevenNode = search_list(ListHead, 7);
    SevenNode = search_list(ListHead, 7);    
    printf("%p\n", (void *) SevenNode);
    SevenNode = search_list(ListHead, 6);
    printf("%p\n", (void *) SevenNode);  
    SevenNode = search_list(ListHead, 4);
    printf("%p\n", (void *) SevenNode);   
    
    /* Print the list */
    printf("Lets print the list \n");
    print_list(ListHead);   
    
    /* Delete a node */
     
}
