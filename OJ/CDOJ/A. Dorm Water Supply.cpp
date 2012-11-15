#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,p,g[1001],m[1001],u,v,c,ind[1001],outd[1001];

int main()
{
    while (scanf("%d%d",&n,&p) != EOF)
    {
        for (int i = 1;i <= n;i++)
        {
            g[i] = -1;
            m[i] = 0;
            ind[i] = outd[i] = 0;
        }
        for (int i = 0;i < p;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            g[u] = v;
            m[u] = c;
            ind[v]++;
            outd[u]++;
        }
        int totres = 0;
        for (int i = 1;i <= n;i++)
            if (ind[i] == 0 && outd[i] == 1)
                totres++;
        printf("%d\n",totres);
        for (int i = 1;i <= n;i++)
            if (ind[i] == 0 && outd[i] == 1)
            {
                int curmax = 19921005;
                int cur = i;
                for (;g[cur] != -1;cur = g[cur])
                    curmax = min(curmax,m[cur]);
                printf("%d %d %d\n",i,cur,curmax);
            }
    }
    return 0;
}
