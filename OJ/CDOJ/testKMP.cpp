#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[200],c[200];
int nxt[1000];

void get_next(char b[])
{
    int j = -1,i,len = strlen(b);
    nxt[0] = -1;
    for (i=1;i<len;i++)
    {
        while(j>-1 && b[i]!= b[j+1])    j=nxt[j];
        if (b[i] == b[j+1]) j++;
        nxt[i]=j;
    }
}

int kmp(char a[],char b[])
{
    get_next(b);
    int i,j,len=strlen(a),lenb=strlen(b);
    j=-1;
    for (i=0;i<len;i++)
    {
        while(j>-1&&a[i]!=b[j+1])j=nxt[j];
        if(a[i]==b[j+1])j++;
        if(j==lenb-1)return i-j;
    }
    return -1;
}

int main()
{
    while (scanf("%s%s",a,c) != EOF)
        printf("%d\n",kmp(a,c));
}
