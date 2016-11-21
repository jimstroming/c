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
    struct list *prev;          /* point to predecessor */
} list;


void insert_list(list **l, int x)
{
    list *p;   /* temporary pointer */
       
    p = malloc( sizeof(list) );
    p->item = x;
    p->next = *l;
    printf("Set the previous\n");
    (p->next)->prev = p;
    printf("Done setting the previous\n");
    p->prev = NULL;
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
        printf("Done printing the list\n");
        return;
    }
    printf("%p\n", (void *) l);    
    printf("%d",l->item);
    printf("\n");   
    return print_list(l->next);
}

list *predecessor_list(list *l, int x)
{
    //printf("Get predecessor\n");
    if ((l == NULL ) || (l->next == NULL)){
        // predecessor sought on null list
        return(NULL);    
    }
    
    if ((l->next)->item == x)
        return(l);
    else
        return(predecessor_list(l->next,x));
}

delete_list(list **l, int x)
{
    list *p;            /* item pointer */
    list *pred;         /* predecessor pointer */
    list *search_list(), *predecessor_list();
    
    p = search_list(*l,x);
    if (p != NULL) {
        pred = predecessor_list(*l,x);
        if (pred == NULL)    /* splice out of list */
            *l = p->next;
        else
            pred->next = p->next;
        printf("Free p\n");
        free(p);          /* free memory used by node */    
    }
}

void main()
{

    struct list MyList;

    printf("Hello, World\n");
    list *ListHead = NULL; 
    
    /* Print the empty list */
    printf("Lets print the list \n");
    print_list(ListHead);   

    /* Insert a couple of nodes */
    insert_list(&ListHead, 7);    
    insert_list(&ListHead, 6);
    insert_list(&ListHead, 4);
        
    /* Try searching the list */
    printf("Try searching the list \n");
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
    delete_list(&ListHead, 4);  
    print_list(ListHead);  
    printf("Delete node 7\n");
    delete_list(&ListHead, 7);
    printf("Deleted node 7\n");
    print_list(ListHead);    
           
}
