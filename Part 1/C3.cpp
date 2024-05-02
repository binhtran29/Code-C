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

int CountDivisor(int n)
{
    int d = 0;
    for(int i=1;i<=n;++i)
        if(n%i==0)
            d++;
    return d;
}

int Count3Divisor(int n, int *a)
{
    int d = 0;
    For(i,0,n)
        if(CountDivisor(a[i]) >= 3)
            d++;
    return d;
}

int *DivisorArr(int n, int *a)
{
    int *dv = (int*) malloc(sizeof(int) * Count3Divisor(n,a));
    int j = 0;
    For(i,0,n)
        if(CountDivisor(a[i]) >= 3)
        {
            dv[j] = a[i];
            j++;
        }
    return dv;
}

void op(int n, int *a)
{
    For(i,0,n)
        printf(" %d ",*(a+i));
}

int main()
{
    int n, *a, *dv;
    ip(&n,&a);

    if(Count3Divisor(n,a) == 0)
        printf("Khong co phan tu nao trong mang co tu 3 uoc tro len!");
    else{
        printf("Cac phan tu co tu 3 uoc tro len la:\n");
        dv = DivisorArr(n,a);
        op(Count3Divisor(n,a),dv);
    }

    free(a);
    free(dv);
}