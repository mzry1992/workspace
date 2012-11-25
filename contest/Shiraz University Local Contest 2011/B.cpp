#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100010];
int p[100010];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        s[0] = '$';
        scanf("%s",s+1);
        int len = strlen(s);
        len = unique(s,s+len)-s;
        s[len] = 0;
        //puts(s);
        int pnow = 0;
        int res = 0;
        int pid = 0;
        for (int i = 1;i < len;i++)
        {
            if (pnow > i)
                p[i] = min(p[2*pid-i],pnow-i);
            else
                p[i] = 1;
            for (;s[i-p[i]] == s[i+p[i]];p[i]++);
            if (i+p[i] > pnow)
            {
                pnow = i+p[i];
                pid = i;
            }
            if (p[i] > res)
                res = p[i];
        }
        printf("%d\n",res);
    }
    return 0;
}

