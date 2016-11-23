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


list *search_list(list *l, char *x)
{
    //printf("Call search_list\n");
    if (l == NULL) return (NULL);
    if (strcmp(l->item,x) == 0)
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
    printf("%p contains ", (void *) l);    
    printf("%s",l->item);
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
    
    if (strcmp((l->next)->item,x) == 0)
        return(l);
    else
        return(predecessor_list(l->next,x));
}



delete_list(list **l, char *x)
{
    list *p;            
    list *pred;        
    list *search_list(), *predecessor_list();
    
    printf("Call delete_list\n");
    p = search_list(*l,x);
    if (p != NULL) {
        printf("Got a match\n");
        pred = predecessor_list(*l,x);
        if (pred == NULL)  
            *l = p->next;
        else
            pred->next = p->next;
        printf("Free p=%p\n",(void*)p);
        free(p);            
    }
}
 
 
list *reverse_node(list *l, list *lastnode)
{

    if (l == NULL)
        return(NULL);
    list *nextnode = l->next;
    l->next = lastnode;
    if (nextnode == NULL) {
        return(l);  
    }    
    return reverse_node(nextnode, l);  
      
}        



reverse_list(list **l)
{
    list *newhead;
    newhead = reverse_node(*l, NULL);
    *l = newhead;
}


void oldmain()
{

    struct list MyList;

    printf("Hello, World\n");
    list *ListHead = NULL; 
    
    /* Print the empty list */
    printf("Lets print the list \n");
    print_list(ListHead);   
    
    /* Insert a couple of nodes */
    insert_list(&ListHead, "Batman");    
    insert_list(&ListHead, "Robin");   
    insert_list(&ListHead, "Joker");        
     
    printf("Lets print the list \n");
    print_list(ListHead);   
            
    /* Try searching the list */
    
    
    printf("Try searching the list \n");
    list *SevenNode = search_list(ListHead, "Batman");
    printf("%p\n", (void *) SevenNode);
    SevenNode = search_list(ListHead, "Green");
    printf("%p\n", (void *) SevenNode);
    SevenNode = search_list(ListHead, "Joker");
    printf("%p\n", (void *) SevenNode);
    
    
    /* Reverse the list */
    
    printf("Reverse the list \n");
    reverse_list(&ListHead); 

    
    /* Print the list */

    printf("Lets print the list \n");
    print_list(ListHead);  

    
    /* Delete a node */
    
    delete_list(&ListHead, "Robin"); 
    printf("Deleted Robin\n"); 
    print_list(ListHead);  
    delete_list(&ListHead, "Batman");
    printf("Deleted Batman\n");
    print_list(ListHead);    
           
}


int main()
{
    struct list MyList;

    list *ListHead = NULL; 
    list *SearchNode = NULL;
    
		FILE *ptr_file;
		int x, i;
    int isaword = 0;
    
    const char s[100]= ",:;. —-\"”“!?()";
    char *token;

		ptr_file =fopen("mobydick.txt", "r");
    


		if (!ptr_file)
			return 1;
      
    char line[10000];  
    while(fgets(line,10000,ptr_file) != NULL)
    {
        //printf("%s",line);
        token = strtok(line, s);
        while (token != NULL)
        {

            isaword = 0;
            /* change to lower case */
            i = 0;
            while (i < strlen(token))
            {
                if (isupper(token[i]))
                {
                    token[i] = tolower(token[i]);
                    isaword = 1;
                }
        
                if (islower(token[i]))
                {
                    isaword = 1;
                }
                
                if(isspace(token[i]))
                {
                    token[i] = 0;
                }
        
                i = i+1;
            }
            
            if (isaword == 1)
            {
                SearchNode =  search_list(ListHead, token);
                //printf("Came out of the search\n");
                if (SearchNode == NULL)
                {
                    insert_list(&ListHead,token); 
                    //printf("%s\n", token);
                }
            }
            token = strtok(NULL, s);            
         }
        
        /* are any of the characters letters? */
    
    }  

        
    fclose(ptr_file);
    
    /* now print the list */
    print_list(ListHead);  
    
    return 0;    

}
