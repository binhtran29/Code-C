#include<stdio.h>
#include<stdlib.h>
void ip(int *n, int ***a)
{
    printf("Nhap kich thuoc ma tran vuong n = ");
    scanf("%d",n);
    *a = (int**) malloc(sizeof(int) * (*n) * (*n));
    printf("Nhap cac phan tu cua ma tran:\n");
    for(int i=0;i<*n;++i)
    {
        *(*a+i) = (int*) malloc(sizeof(int) * (*n));
        for(int j=0;j<*n;++j)
        {
            printf("Nhap A[%d][%d]: ",i,j);
            scanf("%d",*(*a+i)+j);
        }
    }
}
void op(int n, int **a)
{
    for(int i=0;i<n;++i)
    {
        printf("\n");
        for(int j=0;j<n;++j)
            printf(" %5d ",a[i][j]);
    }
}
int MaxMC(int n, int **a)
{
    int max = a[0][0];
    for(int i=1;i<n;++i)
        if(a[i][i] > max)
            max = a[i][i];
    return max;
}
int TbcX(int n, int **a, int x, int *c)
{
    float s=0;
    *c=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(a[i][j]>x)
            {
                s+=a[i][j];
                *c+=1;
            }
    return s/(*c);
}
void MaxSum(int n, int **a)
{
    int S[n];
    for(int i=0;i<n;++i)
    {
        S[i] = 0;
        for(int j=0;j<n;++j)
            S[i]+=a[i][j];
    }
    int max = S[0];
    for(int i=1;i<n;++i)
        if(S[i] > max)
            max = S[i];
    printf("\nCac hang co tong lon nhat la: ");
    for(int i=0;i<n;++i)
        if(S[i] == max)
            printf(" %d ",i);
}
void HoanVi(int &a, int &b)
{
    a = a+b;
    b = a-b;
    a = a-b;
}
void IncrSort(int n, int **a)
{
    for(int i=0;i<n*n-1;++i)
        for(int j=i+1;j<n*n;++j)
            if(a[i/n][i%n] > a[j/n][j%n])
                HoanVi(a[i/n][i%n],a[j/n][j%n]);
}
int main()
{
    int n;
    int **a;
    ip(&n,&a);
    printf("Ma tran vua nhap la:");
    op(n,a);
    
    printf("\nGTLN tren duong cheo chinh la: %d",MaxMC(n,a));

    int x,c;
    printf("\nNhap x = ");
    scanf("%d",&x);
    float tbc = TbcX(n,a,x,&c);
    if(c==0) printf("\nKhong co phan tu nao lon hon %d\n",x);
    else printf("Trung binh cong cac phan tu lon hon %d la: %.2f\n",x,tbc);
    MaxSum(n,a);
    
    printf("\nSap xep ma tran tang dan tu trai qua phai tu tren xuong duoi:");
    IncrSort(n,a);
    op(n,a);
    
    free(a);
}