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

int *DeleteX(int n, int *a, int x, int *d)
{
    int *tmp = (int*) malloc(sizeof(int) * n);
    *d = 0;
    For(i,0,n)
        if(a[i] != x)
        {
            tmp[*d] = a[i];
            *d += 1;
        }
    return tmp;
}

void op(int n, int *a)
{
    For(i,0,n)
        printf(" %d ",*(a+i));
}

int main()
{
    int n, *a, x, *tmp, d;

    ip(&n,&a);
    printf("Nhap x = ");
    scanf("%d",&x);

    tmp = DeleteX(n,a,x,&d);

    printf("Mang sau khi loai cac phan tu bang %d:\n",x);
    op(d,tmp);

    free(a);
    free(tmp);
}