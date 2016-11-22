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
    printf("delete_tree\n");
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
            if ((*l)-> item < parent->item)
                parent->left = NULL;  /* and set it to NULL */
            else
                parent->right = NULL; 
            free(*l);              /* free the memory allocated for the node */
            return;        
        }
        
        if (numberchildren == 1){ /* one child, connect the parent and child */
            printf("One child case.\n");
            if ((*l)->item < parent->item) {
                printf("If case\n");
                if ((*l)->right == NULL){
                    printf("Left Left case\n");
                    printf("l is ");
                    printf("%d",(*l)->item);
                    printf("\n");        
                    printf("parent is ");
                    printf("%d",parent->item);
                    printf("\n");                            
                                        
                    print_tree(*l);  
                                     
                    
                    //parent->left = (*l)->left;
                    tree *kid =  (*l)->left;
                    parent->left = kid;
                    printf("l is ");
                    printf("%d",(*l)->item);  
                    printf("\n");                                     
                    printf("Kid is ");
                    printf("\n");
                    printf("%d",kid->item);
                    printf("\n");                    
                    print_tree(*l);                      
                    if (parent->left == NULL)
                        printf("parent left is now NULL\n");  
                    printf("Parent left is now ");
                    printf("%d", parent->left->item);
                    printf("\n");                      
                    printf("Now set the left node parent\n");
                    print_tree(*l);                       
                    printf("Parent is ");
                    printf("%d",parent->item);
                    printf("\n");
                    tree *child = parent->left;
                    printf("Child is ");
                    printf("\n");
                    printf("%d",child->item);
                    printf("\n");
                    child->parent = parent;
                    printf("Left node parent set\n");
                    printf("child parent is now ");
                    printf("%d",child->parent->item);
                    printf("\n");
                    print_tree(*l);                       
                }
                else{
                    printf("Right Right case\n");
                    parent->left = (*l)->right;
                    ((*l)->right)->parent = parent;
                }
            }
            else{
                printf("Else case\n");
                if ((*l)->right == NULL){
                    printf("Right Left case\n");                
                    parent->right = (*l)->left;
                    ((*l)->left)->parent = parent;
                }
                else{
                    parent->right = (*l)->right;
                    ((*l)->right)->parent = parent;
                }
            }
            
            
            print_tree(*l);
            
            printf("Now free the node\n");
            free(*l);
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
