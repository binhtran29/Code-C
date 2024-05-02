#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define For(i,a,b) for(int i = a; i<b; ++i)
#define endl printf("\n")

void ip(char s[1000])
{
    printf("Nhap chuoi:\n");
    gets(s);
}

void op(char s[])
{
    printf("%s",s);
}

void SepWord(char s[])
{
    char tmp[1000];
    strcpy(tmp,s);
    printf("Cac tu phan biet trong chuoi la:\n");
    char *token = strtok(tmp," ");
    while (token != NULL)
    {
        op(token);
        token = strtok(NULL," ");
        endl;
    }
}

char *MaxLenWord(char s[])
{
    char tmp[1000];
    strcpy(tmp,s);
    char *token = strtok(tmp," ");
    char *max = token;
    while (token != NULL)
    {
        if(strlen(token) > strlen(max))
            max = token;
        token = strtok(NULL," ");
    }
    return max;
}

char *ReverseWord(char s[])
{
    char tmp[1000];
    strcpy(tmp,s);
    char *token = strtok(tmp," ");
    char *s1 = (char*) malloc(sizeof(char) * strlen(s));
    while (token != NULL)
    {
        strcat(s1,strrev(token));
        strcat(s1," ");
        token = strtok(NULL, " ");
    }
    return s1;
}

void Replace(char s[])
{
    char tmp[1000];
    strcpy(tmp,s);
    char *token = strtok(tmp," ");
    while (token != NULL)
    {
        if(token[0] == 't')
            token = "NewWord";
        printf("%s ",token);
        token = strtok(NULL, " ");
    }
}

int *Frequence(char s[])
{
    int *a = (int*) malloc(sizeof(int) * 256);
    For(i,0,256)
        a[i] = 0;
    For(i,0,strlen(s))
        a[(int)s[i]]++;
    return a;
}

void opFrequence(char s[])
{
    int *a = Frequence(s);
    For(i,0,256)
        if(a[i] > 0)
            printf("\nKy tu %c: %d lan",(char)i,a[i]);
}

void Sort(char s[])
{
    char tmp[1000];
    strcpy(tmp,s);
    char *token = strtok(tmp," ");
    char *word[100];
    int d = 0;
    char *a;
    while (token != NULL)
    {
        word[d++] = token;
        token = strtok(NULL, " ");
    }
    For(i,0,d-1)
        For(j,i+1,d)
            if(strcmp(word[i],word[j]) == 1)
            {
                a = word[j];
                word[j] = word[i];
                word[i] = a;
            }
    For(i,0,d)
        printf("%s ",word[i]);
}

int main()
{
    char s[1000];
    ip(s);

    SepWord(s);

    printf("Tu co do dai lon nhat la: %s",MaxLenWord(s));

    char *s1 = ReverseWord(s);
    printf("\nChuoi s1 = %s",s1);
    
    printf("\nChuoi sau khi thay the la:\n");
    Replace(s1);

    opFrequence(s);

    printf("\nChuoi sau sap xep:\n");
    Sort(s);
}