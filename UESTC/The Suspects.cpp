#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int f[32000];

int findf(int x)
{
    if (x != f[x])  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0;i < n;i++)
            f[i] = i;
        for (int i = 1;i <= m;i++)
        {
            int tot,first,mem,fa,fb;
            scanf("%d%d",&tot,&first);
            for (int j = 2;j <= tot;j++)
            {
                scanf("%d",&mem);
                fb = findf(mem);
                fa = findf(first);
                f[fa] = fb;
            }
        }
        int res = 0;
        for (int i = 0;i < n;i++)
        if (findf(i) == findf(0))
            res++;
        printf("%d\n",res);
    }
}
