#include<stdio.h>
#include<stdlib.h>

#define For(i,a,b) for(int i=a;i<b;++i)
#define endl fprintf(file,"\n")

struct NV{
    char hoten[20];
    int luong;
    int mcv;
};

void ip(NV *nv)
{
    printf("Nhap ten nhan vien: ");
    scanf("%s",&nv->hoten);
    printf("Nhap luong: ");
    scanf("%d",&nv->luong);
    printf("Nhap ma cong viec: ");
    scanf("%d",&nv->mcv);
}

void ip(int *n, NV **nv)
{
    printf("Nhap so nhan vien n = ");
    scanf("%d",n);
    *nv = (NV*) malloc(sizeof(NV) * (*n));
    printf("Nhap danh sach nhan vien:\n");
    For(i,0,*n)
        ip(*nv+i);
}

void op(FILE *file, NV nv)
{
    fprintf(file,"Ho ten: %s\nLuong: %d\nMa cong viec: %d",nv.hoten,nv.luong,nv.mcv);
}

void op(FILE *file, int n, NV *nv)
{
    fprintf(file,"Danh sach nhan vien:");
    For(i,0,n)
    {
        endl;
        op(file,*(nv+i));
    }
}

int SumSal(int n, NV *nv, int a)
{
    int s = 0;
    For(i,0,n)
        if(nv[i].mcv == a)
            s += nv[i].luong;
    return s;
}

int CountNoJob(int n, NV *nv, int a)
{
    int d = 0;
    For(i,0,n)
        if(nv[i].mcv == a)
            d++;
    return d;
}

float AveSal(int n, NV *nv, int a)
{
    if(CountNoJob(n,nv,a) == 0)
        return 0;
    return 1.0*SumSal(n,nv,a)/CountNoJob(n,nv,a);
}

int MaxNoJob(int n, NV *nv)
{
    int max = CountNoJob(n,nv,1);
    For(i,2,4)
        if(max < CountNoJob(n,nv,i))
            max = CountNoJob(n,nv,i);
    return max;
}

void FindJobMax(FILE *file, int n, NV *nv)
{
    fprintf(file,"\nCac cong viec co nhieu nhan vien tham gia nhat la: ");
    For(i,1,4)
        if(CountNoJob(n,nv,i) == MaxNoJob(n,nv))
            fprintf(file,"%d",i);
}

int main()
{
    FILE *file;
    int n;
    NV *nv;

    ip(&n,&nv);

    file = fopen("output.txt","w");

    fprintf(file,"%d\n",n);
    op(file,n,nv);

    endl;
    For(i,1,4)
        if(CountNoJob(n,nv,i) == 0)
            fprintf(file,"\nKhong co nhan vien nao co ma cong viec %d!",i);
        else
            fprintf(file,"\nLuong trung binh cua ma cong viec %d la: %.2f",i,AveSal(n,nv,i));

    endl;
    if(CountNoJob(n,nv,2) == 0)
        fprintf(file,"\nKhong co nhan vien nao co ma cong viec 2!");
    else
        fprintf(file,"\nTong luong cua ma cong viec 2 la: %d",SumSal(n,nv,2));    

    endl;
    FindJobMax(file,n,nv);

    fclose(file);
    free(nv);
}