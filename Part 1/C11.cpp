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

int Max(int n, int *a)
{
    int max = a[0];
    For(i,0,n)
        if(a[i] > max)
            max = a[i];
    return max;
}

int CountMax(int n, int *a)
{
    int d = 0;
    For(i,0,n)
        if(a[i] == Max(n,a))
            d++;
    return d;
}

void InsertX(int n, int *a, int x)
{
    int max = Max(n,a);
    int d = CountMax(n,a);
    For(i,0,n+d)
        if(a[i] == max)
        {
            for(int j=n+d-1;j>i;--j)
                a[j+1] = a[j];
            a[i+1] = x;        
        }
}

void op(int n, int *a)
{
    For(i,0,n)
        printf(" %d ",*(a+i));
}

int main()
{
    int n, *a, x;

    ip(&n,&a);
    printf("Nhap x = ");
    scanf("%d",&x);

    int d = CountMax(n,a);

    InsertX(n,a,x);

    printf("Mang sau khi chen %d:\n",x);
    op(n+d,a);

    free(a);
}