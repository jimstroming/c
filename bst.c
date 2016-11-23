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

void print_tree(tree *l)
{
    if (l != NULL){
        print_tree(l->left);
        printf("%d",l->item);
        printf("\n");
        print_tree(l->right);
    }
}



insert_tree(tree **l, int x, tree *parent)
{
    tree *p;                       /* temporary pointer */
    
    printf("Inserting node ");
    printf("%d", x);
    printf("\n");
    if (*l == NULL) {
        p = malloc(sizeof(tree));  /* allocate new node */
        printf("%p\n", (void *) p);  
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


delete_tree(tree **l, int x, tree *parent)
{
    tree *p;                       /* temporary pointer */
    printf("\n");
    printf("delete_tree\n");

    printf("l is at \n");
    printf("%p\n", (void *) &l);      
    printf("l points to \n");
    printf("%p\n", (void *) l); 
    printf("*l points to \n");
    printf("%p\n", (void *) (*l)); 
    
               
    printf("parent points to \n");
    printf("%p\n", (void *) parent);     
    
    
    if (*l == NULL) 
        return;     /* nothing to delete */
    
    if ((*l)->item == x) {      /* found the node */

        int numberchildren = 2;    /* check how man children the node has */  
        if ((*l)->right == NULL){
            printf("no right child\n");
            numberchildren -= 1;
        }
        if ((*l)->left == NULL){
            printf("no left child\n");
            numberchildren -= 1;
        }
        if (numberchildren == 0){  /* zero children, find the parent pointer */
            printf("No child case.\n");
            printf("l points to \n");
            printf("%p\n", (void *) l);
            printf("*l points to \n");
            printf("%p\n", (void *) *l); 
            printf("parent->left IS AT \n");
            printf("%p\n", (void *) &(parent->left));                     
            printf("parent->left points to \n");
            printf("%p\n", (void *) parent->left);                    
            
            free(*l);              /* free the memory allocated for the node */
            *l = NULL;          
            return;        
        }
        
        if (numberchildren == 1){ /* one child, connect the parent and child */
            printf("One child case.\n");
            p = *l;            

                if ((*l)->right == NULL){
                    printf("Left Left case\n");
                    printf("l is at \n");
                    printf("%p\n", (void *) &l);   
                    printf("l points to \n");
                    printf("%p\n", (void *) l);                     
                    printf("*l points to \n");
                    printf("%p\n", (void *) (*l));                    
                    printf("*l->item is at \n");
                    printf("%p\n", (void *) &((*l)->item));                    
                    printf("*l->parent is at \n");
                    printf("%p\n", (void *) &((*l)->parent));                    
                    printf("*l->left is at \n");
                    printf("%p\n", (void *) &((*l)->left));                    
                    printf("*l->right is at \n");
                    printf("%p\n", (void *) &((*l)->right));                    
                                                            
                    ((*l)->left)->parent = parent;
                    *l = (*l)->left;                 
                }
                else{
                    printf("Left Right case\n");
                    ((*l)->right)->parent = parent;
                    *l = (*l)->right;
                }


            
            
            //print_tree(*l);
            
            printf("Now free the node\n");
            free(p);
            return;
            
                       
        
        }
        
        return;                              
    
    }

    if (x < (*l)->item)
        delete_tree(&((*l)->left), x, *l);
    else
        delete_tree(&((*l)->right), x, *l);        
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


void main()
{

    tree *MyTree = NULL;
    printf("MyTree is at \n");
    printf("%p\n", (void *) &MyTree);   
    printf("MyTree points to \n");
    printf("%p\n", (void *) MyTree); 

    insert_tree(&MyTree, 7, NULL);
    
    printf("MyTree is at \n");
    printf("%p\n", (void *) &MyTree);   
    printf("MyTree points to \n");
    printf("%p\n", (void *) MyTree); 
   
    
    
    
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
    
    printf("MyTree is at \n");
    printf("%p\n", (void *) &MyTree);   
    printf("MyTree points to \n");
    printf("%p\n", (void *) MyTree);     
    
    
    //delete_tree(&MyTree, 12, NULL);
    //delete_tree(&MyTree, 0, NULL);
    //delete_tree(&MyTree, 1, NULL);
    //delete_tree(&MyTree, 5, NULL);
    printf("Delete node 3\n");
    delete_tree(&MyTree, 3, NULL);

    print_tree(MyTree);
    
    printf("Search for node 9999\n");
    tree *node9999 = search_tree(MyTree, 9999);
    printf("%d",node9999->item); 
    printf("\n");

}
