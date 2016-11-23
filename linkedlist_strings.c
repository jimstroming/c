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
#include <string.h>

typedef struct list {
    char item[100];             /* data item.  100 character long words */
    struct list *next;          /* point to successor */
} list;


void insert_list(list **l, char* x)
{
    list *p;   /* temporary pointer */
       
    p = malloc( sizeof(list) );
    strcpy(p->item, x);
    //p->item = x;
    p->next = *l;
    *l = p;
}

/*
list *search_list(list *l, char *x)
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
    printf("%p\n", (void *) l);    
    printf("%d",l->item);
    printf("\n");   
    return print_list(l->next);
}

list *predecessor_list(list *l, char *x)
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

*/

/*
delete_list(list **l, char *x)
{
    list *p;            
    list *pred;        
    list *search_list(), *predecessor_list();
    
    p = search_list(*l,x);
    if (p != NULL) {
        pred = predecessor_list(*l,x);
        if (pred == NULL)  
            *l = p->next;
        else
            pred->next = p->next;
        printf("Free p\n");
        free(p);            
    }
}
 
 
list *reverse_node(list *l, list *lastnode)
{
    printf("Reverse the node\n");
    printf("%d",l->item);
    printf(", ");
    if (lastnode != NULL){
        printf("%d",lastnode->item);
    }
    printf("\n");
    if (l == NULL)
        return(NULL);
    list *nextnode = l->next;
    l->next = lastnode;
    if (nextnode == NULL) {
        printf("Return l\n");
        return(l);  
    }    
    return reverse_node(nextnode, l);  
      
}        
*/

/*
reverse_list(list **l)
{
    list *newhead;
    newhead = reverse_node(*l, NULL);
    printf("Got newhead\n");
    *l = newhead;
    printf("Assigned l\n");

}
*/

void main()
{

    struct list MyList;

    printf("Hello, World\n");
    list *ListHead = NULL; 
    
    /* Print the empty list */
    /*
    printf("Lets print the list \n");
    print_list(ListHead);   
    */

    char batman[] = "Batman";
    char robin[] = "Robin";
    char joker[] = "Joker";


    /* Insert a couple of nodes */
    insert_list(&ListHead, batman);    
     
     
        
    /* Try searching the list */
    
    /*
    printf("Try searching the list \n");
    list *SevenNode = search_list(ListHead, 7);
    SevenNode = search_list(ListHead, 7);    
    printf("%p\n", (void *) SevenNode);
    SevenNode = search_list(ListHead, 6);
    printf("%p\n", (void *) SevenNode);  
    SevenNode = search_list(ListHead, 4);
    printf("%p\n", (void *) SevenNode);   
    */
    
    /* Print the list */
    
    /*
    printf("Lets print the list \n");
    print_list(ListHead);  
    */
    
    /* Reverse the list */
    /*
    printf("Reverse the list \n");
    reverse_list(&ListHead); 
    */
    
    /* Print the list */
    /*
    printf("Lets print the list \n");
    print_list(ListHead);  
    */
    
    /* Delete a node */
    /*
    delete_list(&ListHead, 4);  
    print_list(ListHead);  
    printf("Delete node 7\n");
    delete_list(&ListHead, 7);
    printf("Deleted node 7\n");
    print_list(ListHead);    
    */       
}
