#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(FILE *file, int *n, int **a)
{
    fscanf(file,"%d",n);
    *a = (int*) malloc(sizeof(int) * *n);
    For(i,0,*n)
        fscanf(file,"%d",*a+i);
}