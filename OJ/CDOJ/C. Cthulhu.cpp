#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,f[101],lc;

int findf(int x)
{
    if (x != f[x])  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= n;i++)
            f[i] = i;
        lc = 0;
        for (int i = 0;i < m;i++)
        {
            int x,y,fa,fb;
            scanf("%d%d",&x,&y);
            fa = findf(x);
            fb = findf(y);
            if (f[fa] == fb)
                lc++;
            else
                f[fa] = fb;
        }
        for (int i = 1;i <= n;i++)
            if (findf(i) != findf(1))
                lc = 0;
        if (n < 3)  lc = 0;
        if (lc == 1)
            printf("FHTAGN!\n");
        else
            printf("NO\n");
    }
    return 0;
}
