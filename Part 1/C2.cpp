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

int *PrimeArr(int n, int *a)
{
    int *pr = (int*) malloc(sizeof(int) * CountPrime(n,a));
    int j = 0;
    For(i,0,n)
        if(IsPrime(a[i]))
        {
            pr[j] = a[i];
            j++;
        }
    return pr;
}

void op(int n, int *a)
{
    For(i,0,n)
        printf(" %d ",*(a+i));
}

int main()
{
    int n, *a, *pr;
    ip(&n,&a);

    if(CountPrime(n,a) == 0)
        printf("Khong co phan tu nao trong mang la so nguyen to!");
    else{
        printf("Cac phan tu la so nguyen to trong mang la:\n");
        pr = PrimeArr(n,a);
        op(CountPrime(n,a),pr);
    }
    
    free(a);
    free(pr);
}