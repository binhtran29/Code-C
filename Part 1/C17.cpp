#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(FILE *file, int *m, int *n, int ***a)
{
    fscanf(file,"%d%d",m,n);
    *a = (int**) malloc(sizeof(int) * (*n) * (*m));
    For(i,0,*m)
    {
        *(*a+i) = (int*) malloc(sizeof(int) * (*n));
        For(j,0,*n)
            fscanf(file,"%d",*(*a+i)+j);
    }
}

bool IsPrime(int n)
{
    if(n == 1 || n == 0)
        return false;
    For(i,2,n/2)
        if(n % i == 0)
            return false;
    return true;
}

int CountPrime(int m, int n, int **a)
{
    int d = 0;
    For(i,0,m)
        For(j,0,n)
            if(IsPrime(a[i][j]))
                d++;
    return d;
}

void op(FILE *file, int m, int n, int **a)
{
    fprintf(file,"%d",CountPrime(m,n,a));
}

int main()
{
    int m, n, **a;
    FILE *file;

    file = fopen("matrix.inp","r");

    ip(file,&m,&n,&a);

    file = fopen("matrix.out","w");

    op(file,m,n,a);

    fclose(file);
}