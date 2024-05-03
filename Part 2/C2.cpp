#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)
#define endl fprintf(file,"\n")

struct NV{
    int mnv;
    char hoten[20];
    int luong;
    char phong;
};

void ip(FILE *file, NV *nv)
{
    fscanf(file,"%d\n%s%d\n%c",&nv->mnv,&nv->hoten,&nv->luong,&nv->phong);
}

void ip(FILE *file, int n, NV **nv)
{
    *nv = (NV*) malloc(sizeof(NV) * n);
    For(i,0,n)
        ip(file,*nv+i);
}

void op(FILE *file, NV nv)
{
    fprintf(file,"%5d %20s %5d %2c",nv.mnv,nv.hoten,nv.luong,nv.phong);
}

void op(FILE *file, int n, NV *nv)
{
    For(i,0,n)
    {
        endl;
        op(file,*(nv+i));
    }
}

float AveSal(int n, NV *nv, char a)
{
    int s = 0;
    int d = 0;
    For(i,0,n)
        if(nv[i].phong == a)
        {
            s += nv[i].luong;
            d++;
        }
    if(d == 0)
        return 0;
    else
        return 1.0*s/d;
}

void opAveSal(FILE *file, int n, NV *nv, char a)
{
    if(AveSal(n,nv,a) != 0)
        fprintf(file,"\nLuong trung binh cua phong %c la: %.2f",a,AveSal(n,nv,a));
    else
        fprintf(file,"\nKhong co nhan vien nao thuoc phong %c",a);
}

void SortBySal(int n, NV *nv)
{
    NV tmp;
    For(i,0,n-1)
        For(j,i+1,n)
            if(nv[i].luong > nv[j].luong)
            {
                tmp = nv[i];
                nv[i] = nv[j];
                nv[j] = tmp;
            }
}

int main()
{
    int n;
    NV *nv;
    FILE *file;

    file = fopen("input.txt","r");

    fscanf(file,"%d",&n);

    ip(file,n,&nv);

    file = fopen("kq.txt","w");

    fprintf(file,"Danh sach nhan vien:");
    op(file,n,nv);

    endl;

    opAveSal(file,n,nv,'A');
    opAveSal(file,n,nv,'B');
    opAveSal(file,n,nv,'C');

    SortBySal(n,nv);

    fprintf(file,"\n\nDanh sach sau sap xep:");
    op(file,n,nv);

    fclose(file);
    free(nv);
}