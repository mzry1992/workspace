#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[100],b[100];
int p[100],la,lb;

void GaoP()
{
    int j;
    p[0] = j = -1;
    for (int i = 1; i < lb; i++)
    {
        while (j >= 0 && b[j+1] != b[i]) j = p[j];
        if (b[j+1] == b[i]) j++;
        p[i] = j;
    }
    for (int i = 0; i < lb; i++)
        printf("%4d",p[i]);
    printf("\n");
}

void Gao()
{
    int j;
    j = -1;
    for (int i = 0;i < la;i++)
    {
        while (j >= 0 && b[j+1] != a[i])    j = p[j];
        if (b[j+1] == a[i]) j++;
        if (j == lb-1)
        {
            printf("pos = %d\n",i-j);
            j = -1;
        }
    }
}

int main()
{
    while (scanf("%s%s",a,b) != EOF)
    {
        la = strlen(a);
        lb = strlen(b);
        GaoP();
        Gao();
    }
    return 0;
}
