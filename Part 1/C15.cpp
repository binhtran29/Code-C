#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i,a,b) for(int i=a;i<b;++i)
#define endl printf("\n");
struct SV{
    char msv[9];
    char ten[20];
    int birth;
    float toan,ly,hoa;
    float dtb; 
};
void ip(SV *sv)
{
    printf("Ma sinh vien: ");
    fflush(stdin);
    gets(sv->msv);
    printf("Ho va ten: ");
    fflush(stdin);
    gets(sv->ten);
    printf("Nam sinh: ");
    scanf("%d",&sv->birth);
    printf("Diem Toan: ");
    scanf("%f",&sv->toan);
    printf("Diem Ly: ");
    scanf("%f",&sv->ly);
    printf("Diem Hoa: ");
    scanf("%f",&sv->hoa);
    sv->dtb = (sv->toan+sv->ly+sv->hoa)/3;
}
void ip(int n, SV *sv)
{
    For(i,0,n)
    {
        printf("Sinh vien thu %d:\n",i);
        ip(sv+i);
    }
}
void op(SV sv)
{
    printf("%9s %10s %5d %4.1f %4.1f %4.1f %4.1f",sv.msv,sv.ten,sv.birth,sv.toan,sv.ly,sv.hoa,sv.dtb);
}
void op(int n, SV *sv)
{
    For(i,0,n)
    {
        op(*(sv+i));
        endl;
    }
}
SV MaxDTB(int n, SV *sv)
{
    SV tmp;
    float max = sv->dtb;
    For(i,1,n)
        if((sv+i)->dtb>max)
            max = (sv+i)->dtb;
    For(i,0,n)
        if((sv+i)->dtb==max)
            tmp = *(sv+i);
    return tmp;
}
void SortSV(int n, SV *sv)
{
    SV tmp;
    For(i,0,n-1)
        For(j,i+1,n)
            if((sv+i)->dtb>(sv+j)->dtb)
            {
                tmp = *(sv+i);
                *(sv+i) = *(sv+j);
                *(sv+j) = tmp;
            }
    printf("\nDanh sach lop sau khi sap xep:\n");
    op(n,sv);
}
SV *SrchSV(int n, SV *sv, int *d)
{
    SV *tmp = (SV*) malloc(sizeof(SV) * n);
    *d = 0;
    For(i,0,n)
        if((sv+i)->dtb>5 && (sv+i)->toan>=3 && (sv+i)->ly>=3 && (sv+i)->hoa>=3 )
        {
            tmp[*d] = *(sv+i);
            *d+=1;
        }
    return tmp;
}
int MaxAge(int n, SV *sv)
{
    int max=sv->birth;
    For(i,0,n)
        if((sv+i)->birth<max)
            max = (sv+i)->birth;
    return max;
}
SV *SVOldest(int n, SV *sv, int *d)
{
    SV *tmp = (SV*) malloc(sizeof(SV) * n);
    *d = 0;
    For(i,0,n)
        if((sv+i)->birth==MaxAge(n,sv))
        {
            tmp[*d] = *(sv+i);
            *d+=1;
        }
    return tmp;
}
SV MSVSrch(int n, SV *sv, char a[9])
{
    SV tmp;
    For(i,0,n)
        if(strcmp((sv+i)->msv,a)==0)
            tmp=*(sv+i);
    return tmp;
}
int main()
{
    int n;
    printf("Nhap so sinh vien n = ");
    scanf("%d",&n);

    SV *sv = (SV*) malloc(sizeof(SV) * n);
    printf("Nhap danh sach sinh vien:\n");
    ip(n,sv);
    printf("Danh sach vua nhap:\n");
    op(n,sv);

    printf("Sinh vien co diem cao nhat la:\n");
    op(MaxDTB(n,sv));

    SortSV(n,sv);

    int d;
    SV *tmp = SrchSV(n,sv,&d);
    if(d==0)
        printf("Khong co sinh vien nao co dtb > 5 va khong co mon nao duoi 3\n");
    else{
        printf("Cac sinh vien co dtb > 5 va khong co mon nao duoi 3:\n");
        op(d,tmp);
    }

    tmp = SVOldest(n,sv,&d);
    printf("Cac sinh vien co tuoi lon nhat la:\n");
    op(d,tmp);
    
    char a[9];
    printf("Nhap ma sinh vien:\n");
    fflush(stdin);
    gets(a);
    printf("Sinh vien co ma %s la:\n",a);
    op(MSVSrch(n,sv,a));

    free(sv);
    free(tmp);
}