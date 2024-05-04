#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)
#define endl printf("\n")

void ip(FILE *file, int *n, float ***a)
{
    fscanf(file,"%d",n);
    *a = (float**) malloc(sizeof(float) * (*n) * (*n));
    For(i,0,*n)
    {
        *(*a+i) = (float*) malloc(sizeof(float) * (*n));
        For(j,0,*n)
            fscanf(file,"%f",*(*a+i)+j);
    }
}

void op(int n, float **a)
{
    For(i,0,n)
    {
        For(j,0,n)
            printf(" %5.2f ",*(*(a+i)+j));
        endl;
    }
}

float AveSubCross(int n, float **a)
{
    float s = 0;
    int d = 0;
    For(i,1,n)
        For(j,n-i,n)
        {
            s += a[i][j];
            d++;
        }
    return s/d;
}

bool IsUpTri(int n, float **a)
{
    For(i,1,n)
        For(j,0,i)
            if(a[i][j] != 0)
                return false;
    return true;
}

bool IsSymmetry(int n, float **a)
{
    For(i,0,n)
        For(j,0,n)
            if(a[i][j] != a[j][i])
                return false;
    return true;
}

float *SumRows(int n, float **a)
{
    float *s = (float*) malloc(sizeof(float) * n);
    For(i,0,n)
    {
        s[i] = 0;
        For(j,0,n)
            s[i] += a[i][j];
    }
    return s;
}

float MaxSum(int n, float **a)
{
    float *s = SumRows(n,a);
    float max = s[0];
    For(i,1,n)
        if(max < s[i])
            max = s[i];
    return max;
}

void opMaxSum(int n, float **a)
{
    float *s = SumRows(n,a);
    printf("\nCac hang co tong lon nhat la: ");
    For(i,0,n)
        if(s[i] == MaxSum(n,a))
            printf("%d",i);
}

int main()
{
    int n;
    float **a;
    FILE *file;
    char s[20];

    printf("Nhap ten file: ");
    gets(s);

    file = fopen(s,"r");

    ip(file,&n,&a);

    printf("Ma tran vua nhap:\n");
    op(n,a);

    printf("Trung binh cong cac phan tu phia duoi duong cheo phu la: %.2f",AveSubCross(n,a));

    if(IsUpTri(n,a))
        printf("\nMa tran la ma tran tam giac tren");
    else
        printf("\nMa tran khong phai ma tran tam giac tren");

    if(IsSymmetry(n,a))
        printf("\nMa tran la ma tran doi xung");
    else
        printf("\nMa tran khong phai ma tran doi xung");

    float *sum = SumRows(n,a);
    For(i,0,n)
        printf("\nTong hang thu %d la: %.2f",i,sum[i]);
    opMaxSum(n,a);
}