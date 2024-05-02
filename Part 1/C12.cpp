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

bool IsLeapYear(int y)
{
    return (y % 4 == 0);
}

bool DateValid(int d, int m, int y)
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(IsLeapYear(y))
        days[1] = 29;
    if(y > 9999 || y < 0)
        return false;
    if(m < 1 || m > 12)
        return false;
    if(d < 1 || d > days[m-1])
        return false;
    return true;
}

void op(int d, int m, int y)
{
    printf("Ngay vua nhap: %02d/%02d/%04d",d,m,y);
}

int main()
{
    int d,m,y;

    ip(&d,&m,&y);

    op(d,m,y);

    if(DateValid(d,m,y))
        printf("\nNgay hop le!");
    else
        printf("\nNgay khong hop le!");
}