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


tree *find_minimum(tree *t)
{
    tree *min;            /* pointer to minimum */
    
    if (t == NULL) return(NULL);
    
    min = t;
    while (min->left != NULL)
        min = min->left;
    return(min);       
}


delete_tree(tree **l, int x, tree *parent)
{
    tree *p;                       /* temporary pointer */
  
    if (*l == NULL) 
        return;     /* nothing to delete */
    
    if ((*l)->item == x) {      /* found the node */

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
            int minvalue = p-> item;
                      
            /* remove that node */
            delete_tree(&((*l)->right), minvalue, ((*l)->right)->parent);
            
            /* give the node we want to remove the value of the node we just removed */
            (*l)->item = minvalue;
            
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
    
    
    delete_tree(&MyTree, 12, NULL);

    delete_tree(&MyTree, 3, NULL);
    delete_tree(&MyTree, 14, NULL);
    delete_tree(&MyTree, 0, NULL);
    delete_tree(&MyTree, 1, NULL);
    delete_tree(&MyTree, 7, NULL);  
        
   
    delete_tree(&MyTree, 10000, NULL);  
        
    print_tree(MyTree);   
    
    printf("Search for node 9999\n");
    tree *node9999 = search_tree(MyTree, 9999);
    printf("%d",node9999->item); 
    printf("\n");

}
