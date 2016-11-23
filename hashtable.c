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


unsigned long hashfunction(char *str) 
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;

}


void main()
{
    char a[] = "Hello";
    char b[] = "world";
    char c[] = "supercalifragilisticexpealidocious";
    char d[] = "thelongandwindingroadthatleadstoyourdoorwillneverdisappeariveknowthatroadbefore";
    
    
    printf("%s\n",a);
    
    printf("%c\n",b[0]);
    printf("%c\n",b[5]);
    printf("%c\n",b[16]);
    
    printf("%p\n",(void*)&a);
    printf("%p\n",(void*)&b);
    
    
    printf("%lu\n",hashfunction(a));
    printf("%lu\n",hashfunction(b));
    printf("%lu\n",hashfunction(c));
    printf("%lu\n",hashfunction(d));        
    printf("Done\n");
}