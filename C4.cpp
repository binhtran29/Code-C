#include<stdio.h>
#include<stdlib.h>

#define ForI(i,a,b) for(int i=a;i<b;++i)
#define ForD(i,a,b) for(int i=b-1;i>=a;--i)

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
    ForI(i,0,*n)
        scanf("%d",*a+i);
}

bool CheckX(int n, int *a, int x)
{
    bool c = false;
    ForI(i,0,n)
        if(a[i] == x)
            c = true;
    return c;
}

int FindLastx(int n, int *a, int x)
{
    int c;
    ForD(i,0,n)
        if(a[i] == x)
        {
            c = i;
            break;
        }
    return c;
}

int main()
{
    int n, *a, x;
    ip(&n,&a);

    printf("Nhap gia tri x = ");
    scanf("%d",&x);

    if(CheckX(n,a,x))
        printf("Vi tri phan tu cuoi cung co gia tri %d la: %d",x,FindLastx(n,a,x));
    else    
        printf("Khong co phan tu nao co gia tri %d",x);

    free(a);
}