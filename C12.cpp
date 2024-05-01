#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(int *d, int *m, int *y)
{
    printf("Nhap ngay: ");
    scanf("%d",d);
    printf("Nhap thang: ");
    scanf("%d",m);
    printf("Nhap nam: ");
    scanf("%d",y);
}

int *Sep2Arr(int d, int m, int y)
{
    int *a = (int*) malloc(sizeof(int) * 8);
    a[0] = d / 10;
    a[1] = d % 10;
    a[2] = m / 10;
    a[3] = m % 10;
    a[4] = y / 1000;
    a[5] = y % 1000 / 100;
    a[6] = y % 1000 % 100 / 10;
    a[7] = y % 1000 % 100 % 10;
    return a;
}

bool DateValid(int *a)
{
    bool c = true;
    if(a[4] > 9)
        c = false;
    if(a[2] == 0)
        if(a[3] == 0)
            c = false;
    else if(a[2] == 1)
        if(a[3] > 2)
            c = false;
    else
        c = false;
    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
}

void op(int n, int *a)
{
    For(i,0,n)
    {
        printf("%d",*(a+i));
        if(i == 1 || i == 3)
            printf("/");
    }
}

int main()
{
    int d,m,y;

    ip(&d,&m,&y);

    int *a = Sep2Arr(d,m,y);

    op(8,a);
}