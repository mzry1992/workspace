#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n,len[10],p[70],pnow,minlen,maxlen;
char s[10][70];
string res,tres;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%s",s[i]);
            len[i] = strlen(s[i]);
        }
        res = "";
        for (int i = 0;i < len[0];i++)
        {
            pnow = p[0] = -1;
            for (int j = 1;i+j < len[0];j++)
            {
                while (pnow >= 0 && s[0][i+pnow+1] != s[0][i+j])    pnow = p[pnow];
                if (s[0][i+pnow+1] == s[0][i+j])    pnow++;
                p[j] = pnow;
            }
            minlen = len[0]-i;
            for (int j = 1;j < n;j++)
            {
                pnow = maxlen = -1;
                for (int k = 0;k < len[j];k++)
                {
                    while (pnow >= 0 && s[0][i+pnow+1] != s[j][k])  pnow = p[pnow];
                    if (s[0][i+pnow+1] == s[j][k])  pnow++;
                    maxlen = max(maxlen,pnow);
                }
                minlen = min(minlen,maxlen);
            }
            tres = "";
            for (int j = 0;j <= minlen;j++)
                tres += s[0][i+j];
            if (tres.size() > res.size() || (tres.size() == res.size() && res > tres))
                res = tres;
        }
        if (res.size() < 3)
            res = "no significant commonalities";
        printf("%s\n",res.c_str());
    }
    return 0;
}
