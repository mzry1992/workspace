#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,g[16][16],u,v;
long long y,dif[1<<16];

long long Gao(int sta)
{
    if (dif[sta] != -1) return dif[sta];
    dif[sta] = 0;
    bool flag;
    for (int i = 0;i < n;i++)
        if (((sta>>i)&1) == 1)
        {
            flag = true;
            for (int j = 0;j < n;j++)
                if (((sta>>j)&1) == 1)
                    if (g[j][i] == 1)
                    {
                        flag = false;
                        break;
                    }
            if (flag == false)  continue;
            dif[sta] += Gao(sta&(~(1<<i)));
        }
    return dif[sta];
}

void Ji(int sta,long long kth)
{
    bool flag;
    long long tot = 0;
    long long pretot = 0;
    for (int i = 0;i < n;i++)
        if (((sta>>i)&1) == 1)
        {
            flag = true;
            for (int j = 0;j < n;j++)
                if (((sta>>j)&1) == 1)
                    if (g[j][i] == 1)
                    {
                        flag = false;
                        break;
                    }
            if (flag == false)  continue;
            tot = pretot+Gao(sta&(~(1<<i)));
            if (tot >= kth)
            {
                printf("%d ",i+1);
                Ji(sta&(~(1<<i)),kth-pretot);
                return;
            }
            pretot = tot;
        }
}

int main()
{
    while (scanf("%d%I64d%d",&n,&y,&m) != EOF)
    {
        memset(g,0,sizeof(g));
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            g[u][v] = 1;
        }
        for (int i = 0;i < 1<<n;i++)
            dif[i] = -1;
        dif[0] = 1;
        y -= 2000;
        if (Gao((1<<n)-1) < y)
            printf("The times have changed");
        else
            Ji((1<<n)-1,y);
        printf("\n");
    }
    return 0;
}
