#include<stdio.h>
#include<stdlib.h>

void ip(int *m, int *n)
{
    printf("Nhap khoang [m,n]:\n");
    re:
        scanf("%d%d",m,n);
        if(*m>=*n)
        {
            printf("Khoang khong hop le!\nNhap lai:\n");
            goto re;
        }
}

int *GenRand(int m, int n, int *i)
{
    int *a;
    a = (int*) malloc(sizeof(int) * (n-m));
    a[0] = rand()%(n-m+1)+m;
    *i = 0;
    while(a[*i] < n && *i < (n-m-2))
    {
        a[*i+1] = rand()%(n-a[*i]+1)+a[*i];
        *i += 1;
    }
    return a;
}

void op(int n, int *a)
{
    printf("Mang so nguyen ngau nhien tang dan:\n");
    for(int i=0;i<n;++i)
        printf(" %d ",a[i]);
}

int main()
{
    int m,n;
    ip(&m,&n);
    int *a,i;
    a = GenRand(m,n,&i);
    op(i+1,a);
}