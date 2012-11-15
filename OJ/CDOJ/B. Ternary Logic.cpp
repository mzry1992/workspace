#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a,b,c,sa[100],sb[100],sc[100],la,lc,l;

void cov(int a,int sa[],int& la)
{
    memset(sa,0,sizeof(sa));
    la = 0;
    while (a)
    {
        sa[la++] = a%3;
        a /= 3;
    }
}

int main()
{
    while (scanf("%d%d",&a,&c) != EOF)
    {
        cov(a,sa,la);
        cov(c,sc,lc);
        l = max(la,lc);
        memset(sb,0,sizeof(sb));
        for (int i = 0;i < l;i++)
            for (sb[i] = 0;sb[i] < 3;sb[i]++)
                if ((sa[i]+sb[i])%3 == sc[i])
                    break;
        b = 0;
        for (int i = l-1;i >= 0;i--)
            b = b*3+sb[i];
        printf("%d\n",b);
    }
    return 0;
}

