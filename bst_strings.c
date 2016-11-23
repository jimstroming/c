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

typedef struct tree {
    char item[100];                /* data item */
    struct tree *parent;     /* pointer to parent */
    struct tree *left;       /* pointer to left child */
    struct tree *right;      /* pointer to right child */

}   tree;

void print_tree(tree *l)
{
    if (l != NULL){
        print_tree(l->left);
        printf("%s",l->item);
        printf("\n");
        print_tree(l->right);
    }
}



insert_tree(tree **l, char* x, tree *parent)
{
    tree *p;                       /* temporary pointer */
    
    if (*l == NULL) {
        p = malloc(sizeof(tree));  /* allocate new node */
        //printf("%p\n", (void *) p);      
        strcpy(p->item, x);
        //p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;                    /* link into parent's record */
        return;
    }
    
    if (strcmp(x ,(*l)->item) < 0)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);        
}


tree *find_minimum(tree *t)
{
    tree *min;            /* pointer to minimum */
    
    if (t == NULL) return(NULL);
    
    min = t;
    while (min->left != NULL)
        min = min->left;
    return(min);       
}


delete_tree(tree **l, char* x, tree *parent)
{
    tree *p;                       /* temporary pointer */
  
    if (*l == NULL) 
        return;     /* nothing to delete */
    
    if (strcmp((*l)->item,x) == 0) {      /* found the node */

        int numberchildren = 2;    /* check how man children the node has */  
        if ((*l)->right == NULL){
            numberchildren -= 1;
        }
        if ((*l)->left == NULL){
            numberchildren -= 1;
        }
        if (numberchildren == 0){  /* zero children, find the parent pointer */                  
            
            free(*l);              /* free the memory allocated for the node */
            *l = NULL;          
            return;        
        }
        
        if (numberchildren == 1){ /* one child, connect the parent and child */
            p = *l;            

            if ((*l)->right == NULL){
                                                                             
                ((*l)->left)->parent = parent;
                *l = (*l)->left;                 
            }
            else{
                ((*l)->right)->parent = parent;
                *l = (*l)->right;
            }
            
            free(p);
            return;            
            
        }
        
        
        if (numberchildren == 2) { /* two child is the most complicated case */
        
            /* find the minimum node on the left subtree */
            p = find_minimum((*l)->right);
            
            char minvalue[100];
            strcpy(minvalue, p->item);
            //char* minvalue = p-> item;
                      
            /* remove that node */
            delete_tree(&((*l)->right), minvalue, ((*l)->right)->parent);
            
            /* give the node we want to remove the value of the node we just removed */
            strcpy((*l)->item, minvalue);
            
            return;
        }
            
        return;                                 
    }

    if (strcmp(x ,(*l)->item) < 0)
        delete_tree(&((*l)->left), x, *l);
    else
        delete_tree(&((*l)->right), x, *l);        
}

tree *search_tree(tree *l, char* x)
{
    if (l == NULL) return(NULL);
    if (strcmp(l->item,x) == 0) return(l);
    if (strcmp(x ,l->item) < 0)
        return (search_tree(l->left, x));
    else
        return (search_tree(l->right, x));
}


void oldmain()
{

    tree *MyTree = NULL;
    printf("MyTree is at \n");
    printf("%p\n", (void *) &MyTree);   
    printf("MyTree points to \n");
    printf("%p\n", (void *) MyTree); 

    insert_tree(&MyTree, "7", NULL);
    
    printf("MyTree is at \n");
    printf("%p\n", (void *) &MyTree);   
    printf("MyTree points to \n");
    printf("%p\n", (void *) MyTree); 
   
    
    
    
    insert_tree(&MyTree, "14", NULL);
    insert_tree(&MyTree, "3", NULL);
    insert_tree(&MyTree, "2", NULL);
    insert_tree(&MyTree, "1", NULL);
    insert_tree(&MyTree, "10000", NULL);
    insert_tree(&MyTree, "10001", NULL);
    insert_tree(&MyTree, "9999", NULL);
    insert_tree(&MyTree, "12", NULL);
    insert_tree(&MyTree, "0", NULL);
    insert_tree(&MyTree, "9998", NULL);
    
    printf("\nPrint the Tree.\n");    
    print_tree(MyTree);       
    
    printf("MyTree is at \n");
    printf("%p\n", (void *) &MyTree);   
    printf("MyTree points to \n");
    printf("%p\n", (void *) MyTree);     
    
    
    delete_tree(&MyTree, "12", NULL);

    delete_tree(&MyTree, "3", NULL);
    delete_tree(&MyTree, "14", NULL);
    delete_tree(&MyTree, "0", NULL);
    delete_tree(&MyTree, "1", NULL);
    delete_tree(&MyTree, "7", NULL);  
        
   
    delete_tree(&MyTree, "10000", NULL);  
        
        
    printf("\nPrint the Tree.\n");    
    print_tree(MyTree);   
    
    printf("Search for node 9999\n");
    tree *node9999 = search_tree(MyTree, "9999");
    printf("%s",node9999->item); 
    printf("\n");

}


int main()
{
    tree *MyTree = NULL;

    tree *SearchNode = NULL;
    
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
                SearchNode =  search_tree(MyTree, token);
                //printf("Came out of the search\n");
                if (SearchNode == NULL)
                {
                    insert_tree(&MyTree,token, NULL); 
                    //printf("%s\n", token);
                }
            }
            token = strtok(NULL, s);            
         }
        
        /* are any of the characters letters? */
    
    }  

        
    fclose(ptr_file);
    
    /* now print the list */
    print_tree(MyTree);  
    
    return 0;    

}
