#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(FILE *file, int *n)
{
    fscanf(file,"%d",n);
}

void ip(FILE *file, int n, int **a)
{
    *a = (int*) malloc(sizeof(int) * n);
    For(i,0,n)
        ip(file,*a+i);
}

void op(int n, int *a)
{
    For(i,0,n)
        printf(" %d ",*(a+i));
}

int Max(int n, int *a)
{
    int max = a[0];
    For(i,1,n)
        if(max < a[i])
            max = a[i];
    return max;
}

void SortDcr(int n, int *a)
{
    For(i,0,n-1)
        For(j,i+1,n)
            if(a[i] < a[j])
            {
                a[i] += a[j];
                a[j] = a[i] - a[j];
                a[i] -= a[j];
            }
}

int main()
{
    FILE *file;

    int m, n, *a, *b;

    file = fopen("input.txt","r");

    ip(file,&n);
    ip(file,&m);
    ip(file,n,&a);
    ip(file,m,&b);

    printf("Cac phan tu cua day a:\n");
    op(n,a);
    printf("\nCac phan tu cua day b:\n");
    op(m,b);

    printf("\nGTLN trong day a: %d",Max(n,a));
    printf("\nGTLN trong day b: %d",Max(m,b));

    SortDcr(n,a);
    printf("\nDay a sau sap xep:\n");
    op(n,a);

    SortDcr(m,b);
    printf("\nDay b sau sap xep:\n");
    op(m,b);

    fclose(file);
    free(a);
    free(b);
}