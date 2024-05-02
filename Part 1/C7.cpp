#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(int *n, float **a, char b)
{
    printf("Nhap %c = ",b);
    re:
        scanf("%d",n);
        if(*n<1){
            printf("Nhap lai %c = ",b);
            goto re;
        }
    *a = (float*) malloc(sizeof(float) * (*n));
    printf("Nhap cac phan tu cua mang:\n");
    For(i,0,*n)
        scanf("%f",*a+i);
}

float *OnlyA(int n, int m, float *a, float *b, int *k)
{
    float *A = (float*) malloc(sizeof(float) * n);
    bool c = true;
    *k = 0;
    For(i,0,n)
    {
        For(j,0,m)
            if(a[i] == b[j])
                c = false;
        if(c){
            A[*k] = a[i];
            *k+=1;
        }
        c = true;
    }
    return A;
}

float *BothAB(int n, int m, float *a, float *b, int *k)
{
    int max = n;
    if(m > n)
        max = m;
    float *ab = (float*) malloc(sizeof(float) * max);
    *k = 0;
    For(i,0,n)
        For(j,0,n)
            if(a[i] == b[j])
            {
                ab[*k] = a[i];
                *k+=1;
            }
    return ab;
}

void op(int n, float *a)
{
    For(i,0,n)
        printf(" %.2f ",*(a+i));
}

int main()
{
    int n, m;
    float *a, *b;

    ip(&n,&a,'n');
    ip(&m,&b,'m');

    float *tmp;
    int k;
    
    tmp = OnlyA(n,m,a,b,&k);
    if(k == 0)
        printf("Khong co phan tu nao chi thuoc a!");
    else{
        printf("Cac phan tu chi thuoc a la:\n");
        op(k,tmp);
    }

    tmp = BothAB(n,m,a,b,&k);
    if(k == 0)
        printf("\nKhong co phan tu nao thuoc ca a va b!");
    else{
        printf("\nCac phan tu thuoc ca a va b la:\n");
        op(k,tmp);
    }
}