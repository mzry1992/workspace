#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1000],a[3000];
int p[3000],len,l,pnow,pid,res,resid;

int main()
{
    while (scanf("%s",s) != EOF)
    {
        len = strlen(s);
        l = 0;
        a[l++] = '.';
        a[l++] = ',';
        for (int i = 0;i < len;i++)
        {
            a[l++] = s[i];
            a[l++] = ',';
        }
        pnow = 0;
        res = 0;
        for (int i = 1;i < l;i++)
        {
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
            if (p[i] > res)
            {
                res = p[i];
                resid = i;
            }
        }
        for (int i = resid-res+2;i < resid+res-1;i += 2)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
