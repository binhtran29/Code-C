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

void op(FILE *file, int n, int *a)
{
    For(i,0,n)
        fprintf(file," %d ",*(a+i));
}

void SortIncr(int n, int *a)
{
    For(i,0,n-1)
        For(j,i+1,n)
            if(a[i] > a[j])
            {
                a[i] += a[j];
                a[j] = a[i] - a[j];
                a[i] -= a[j];
            }
}

int main()
{
    int n, *a;
    FILE *file;

    file = fopen("array.inp","r");
    
    ip(file,&n,&a);

    file = fopen("array.out","w");

    op(file,n,a);

    fprintf(file,"\n");
    SortIncr(n,a);

    op(file,n,a);

    fclose(file);
}