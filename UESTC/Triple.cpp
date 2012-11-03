#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[800],g[800][800],tmp[800],tot;

int gcd(int a,int b)
{
    return (b == 0)?a:gcd(b,a%b);
}

int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    int t;
    t = readint();
    for (int ft = 1;ft <= t;ft++)
    {
        n = readint();
        for (int i = 0;i < n;i++)
            a[i] = readint();
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                g[i][j] = gcd(a[i],a[j]);
        int res = 0;
        for (int i = 0;i < n;i++)
        {
            tot = 0;
            for (int j = i+1;j < n;j++)
                if (g[i][j] == 1)
                    tmp[tot++] = j;
            for (int k = 0;k < tot;k++)
                for (int q = k+1;q < tot;q++)
                    if (g[tmp[k]][tmp[q]] == 1)
                        res++;
            tot = 0;
            for (int j = i+1;j < n;j++)
                if (g[i][j] != 1)
                    tmp[tot++] = j;
            for (int k = 0;k < tot;k++)
                for (int q = k+1;q < tot;q++)
                    if (g[tmp[k]][tmp[q]] != 1)
                        res++;
        }
        printf("%d\n",res);
    }
}
