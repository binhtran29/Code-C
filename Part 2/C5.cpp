#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define For(i,a,b) for(int i=a;i<b;++i)

void ip(FILE *file, int *n, float ***a)
{
    fscanf(file,"%d",n);
    *a = (float**) malloc(sizeof(float) * (*n) * 2);
    For(i,0,*n)
    {
        *(*a+i) = (float*) malloc(sizeof(float) * 2);
        For(j,0,2)
            fscanf(file,"%f",*(*a+i)+j);
    }
}

void op(int n, float **a)
{
    For(i,0,n)
        printf("\n(%.2f , %.2f)",a[i][0],a[i][1]);
}

float LineLen(float a, float b, float c, float d)
{
    return sqrt(pow(a-c,2)+pow(b-d,2));
}

float MaxLenO(int n, float **a)
{
    float max = 0;
    For(i,0,n)
        if(LineLen(a[i][0],a[i][1],0,0) > max)
            max = LineLen(a[i][0],a[i][1],0,0);
    return max;
}

void FarthestPnt(int n, float **a)
{
    For(i,0,n)
        if(LineLen(a[i][0],a[i][1],0,0) == MaxLenO(n,a))
        {
            printf("\nDiem xa goc O nhat la: (%.2f , %.2f)",a[i][0],a[i][1]);
            break;
        }
}

int CountLine(int n)
{
    return n*(n-1)/2;
}

float MaxLen(int n, float **a)
{
    float max = 0;
    For(i,0,n-1)
        For(j,i+1,n)
        if(LineLen(a[i][0],a[i][1],a[j][0],a[j][1]) > max)
            max = LineLen(a[i][0],a[i][1],a[j][0],a[j][1]);
    return max;
}

void MaxLenLine(int n, float **a)
{
    For(i,0,n-1)
        For(j,i+1,n)
            if(LineLen(a[i][0],a[i][1],a[j][0],a[j][1]) == MaxLen(n,a))
                printf("\nDoan thang dai nhat la: (%.2f , %.2f) - (%.2f , %.2f)",a[i][0],a[i][1],a[j][0],a[j][1]);
}

int CountPnt(int n, float **a)
{
    int d = 0;
    For(i,0,n)
        if(a[i][0] > 0 && a[i][1] > 0)
            d++;
    return d;
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

    printf("Day diem:");
    op(n,a);
   
    FarthestPnt(n,a);

    printf("\nSo doan thang tao tu %d diem: %d",n,CountLine(n));

    MaxLenLine(n,a);

    printf("\nCo %d diem nam trong goc phan tu thu nhat!",CountPnt(n,a));

    fclose(file);
    free(a);
}