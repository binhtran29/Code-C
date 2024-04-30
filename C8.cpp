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

int *GenRand(int n)
{
    int *a = (int*) malloc(sizeof(int) * n);
    For(i,0,n)
        a[i] = rand() % 20001;
    return a;
}

int *EachArr(int n, int *a, int *d)
{
    int *tmp = (int*) malloc(sizeof(int) * n);
    tmp[0] = a[0];
    *d = 1;
    For(i,1,n)
        if(a[i] != tmp[0])
        {
            tmp[*d] = a[i];
            *d+=1;
        }
    return tmp;
}

int *Frequence(int n, int *a)
{
    int d;
    int *tmp = EachArr(n,a,&d);
    int *f = (int*) malloc(sizeof(int) * d);
    For(i,0,d)
        For(j,0,n)
            if(a[j] == tmp[i])
                f[i] += 1;
    return f;
}

void op(int n, int *a)
{
    For(i,0,n)
        printf("%6d",*(a+i));
}

int main()
{
    int n, *a, *tmp, *f, d;

    ip(&n);

    a = GenRand(n);

    tmp = EachArr(n,a,&d);

    f = Frequence(n,a);

    printf("Tan suat xuat hien cac phan tu trong mang la:\n");
    op(d,tmp);
    printf("\n");
    op(d,f);

    free(a);
    free(tmp);
    free(f);
}