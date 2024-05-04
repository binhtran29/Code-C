#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define For(i,a,b) for(int i=a;i<b;++i)
#define endl printf("\n")

struct SV{
    char hoten[20];
    char que[10];
    char hocluc;
};

void ip(FILE *file, SV *sv)
{
    fscanf(file,"%s\n%s\n%c",&sv->hoten,&sv->que,&sv->hocluc);
}

void ip(FILE *file, int n, SV **sv)
{
    *sv = (SV*) malloc(sizeof(SV) * n);
    For(i,0,n)
        ip(file,*sv+i);
}

void op(SV sv)
{
    printf("%20s %10s %3c",sv.hoten,sv.que,sv.hocluc);
}

void op(int n, SV *sv)
{
    For(i,0,n)
    {
        endl;
        op(*(sv+i));
    }
}

SV SearchName(int n, SV *sv, char s[20])
{
    SV tmp;
    For(i,0,n)
        if(strcmp(sv[i].hoten,s) == 0)
            tmp = sv[i];
    return tmp;
}

bool NameExist(int n, SV *sv, char s[20])
{
    For(i,0,n)
        if(strcmp(sv[i].hoten,s) == 0)
            return true;
    return false;
}

int Count(int n, SV *sv, char a)
{
    int d = 0;
    For(i,0,n)
        if(sv[i].hocluc == a)
            d++;
    return d;
}

SV *Search(int n, SV *sv, char a, int *d)
{
    SV *tmp = (SV*) malloc(sizeof(SV) * n);
    *d = 0;
    For(i,0,n)
        if(sv[i].hocluc == a)
        {
            tmp[*d] = sv[i];
            *d += 1;
        }
    return tmp;
}

int main()
{
    int n;
    FILE *file;
    SV *sv;

    file = fopen("input.txt","r");

    fscanf(file,"%d\n",&n);

    ip(file,n,&sv);

    op(n,sv);

    char s[20];
    printf("\nNhap ten sinh vien:\n");
    gets(s);

    if(NameExist(n,sv,s))
    {
        printf("Sinh vien can tim la:\n");
        op(SearchName(n,sv,s));
    }
    else
        printf("Khong co ten sinh vien trong danh sach!");

    if(Count(n,sv,'A') == 0)
        printf("\nKhong co sinh vien nao dat hoc luc loai A!");
    else
        printf("\nCo %d sinh vien dat hoc luc loai A!",Count(n,sv,'A'));

    char a;
    printf("\nNhap hoc luc: ");
    scanf("%c",&a);
    int d;
    SV *tmp = Search(n,sv,a,&d);
    if(d == 0)
        printf("Khong co sinh vien nao co hoc luc dat loai %c!",a);
    else{
        printf("Cac sinh vien dat hoc luc loai %c la:",a);
        op(d,tmp);
    }

    fclose(file);
    free(sv);
    free(tmp);
}