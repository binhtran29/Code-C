#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(int *n, int **a)
{
    printf("Nhap n = ");
    re:
        scanf("%d",n);
        if(*n<1){
            printf("Nhap lai n = ");
            goto re;
        }
    *a = (int*) malloc(sizeof(int) * (*n));
    printf("Nhap cac phan tu cua mang:\n");
    For(i,0,*n)
        scanf("%d",*a+i);
}

void op(int n, int *a)
{
    For(i,0,n)
        printf(" %d ",*(a+i));
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
    op(n,a);
}

void SortDecr(int n, int *a)
{
    For(i,0,n-1)
        For(j,i+1,n)
            if(a[i] < a[j])
            {
                a[i] += a[j];
                a[j] = a[i] - a[j];
                a[i] -= a[j];
            }
    op(n,a);
}

int main()
{
    int n, *a;

    ip(&n,&a);

    printf("Mang sau sap xep tang dan:\n");
    SortIncr(n,a);

    printf("\nMang sau sap xep giam dan:\n");
    SortDecr(n,a);

    free(a);
}