#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod[2] = {107,50007};
char s[110000 ],a[210000];
int p[210000],len,l,pnow,pid,rk[210000][2];

int getval(char ch)
{
    if (ch == ',')  return 0;
    return ch-'a'+1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",s);
        len = strlen(s);
        l = 0;
        a[l++] = '.';
        a[l++] = ',';
        for (int i = 0;i < len;i++)
        {
            a[l++] = s[i];
            a[l++] = ',';
        }
        pnow = rk[0] = 0;
        for (int i = 1;i < l;i++)
        {
            for (int j = 0;j < 2;j++)
                rk[i][j] = (rk[i-1][j]*27+getval(s[i]))%mod[j];
            if (pnow > i)
                p[i] = min(p[2*pid-i],pnow-i);
            else
                p[i] = 1;
            for (;a[i-p[i]] == a[i+p[i]];p[i]++);
            if (i+p[i] > pnow)
            {
                pnow = i+p[i];
                pid = i;
            }
        }
        for (int i = 1;i < l;i++)
            printf("%d ",p[i]);
        printf("\n");
    }
    return 0;
}
