#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(int *n)
{
    printf("Nhap n = ");
    re:
        scanf("%d",n);
        if(*n < 1 || *n > 30000)
        {
            printf("Khoang khong hop le!\nNhap lai:\n");
            goto re;
        }
}

void GenRand(int n, int **a)
{
    *a = (int*) malloc(sizeof(int) * n);
    For(i,0,n)
        a[i] = rand() % 20001;
}