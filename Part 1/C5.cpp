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

int FindMaxMinus(int n, int *a)
{
    int max, c;
    For(i,0,n)
        if(a[i] < 0)
        {
            max = a[i];
            break;
        }
    For(i,0,n)
        if(a[i] < 0 && a[i] > max)
            c = i;
    return c;
}

bool CheckMinus(int n, int *a)
{
    bool c = false;
    For(i,0,n)
        if(a[i] < 0)
            c = true;
    return c;
}

int main()
{
    int n, *a;
    ip(&n,&a);

    if(CheckMinus(n,a))
        printf("Vi tri phan tu am lon nhat la: %d",FindMaxMinus(n,a));
    else
        printf("Khong co phan tu am nao trong mang!");

    free(a);
}