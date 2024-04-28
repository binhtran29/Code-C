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

bool IsPrime(int n)
{
    bool c = true;
    if(n == 1)
        return false;
    for(int i=2;i<=n/2;++i)
        if(n%i==0)
            c = false;
    return c;
}

int CountPrime(int n, int *a)
{
    int c = 0;
    For(i,0,n)
        if(IsPrime(a[i]))
            c++;
    return c;
}

int SumPrime(int n, int *a)
{
    int s = 0;
    For(i,0,n)
        if(IsPrime(a[i]))
         s += a[i];
    return s;
}

int main()
{
    int n, *a;
    ip(&n,&a);

    if(CountPrime(n,a) == 0)
        printf("Khong co phan tu nao trong mang la so nguyen to!");
    else
        printf("Trung binh cong cac phan tu la so nguyen to la: %.2f",1.0*SumPrime(n,a)/CountPrime(n,a));
    
    free(a);
}