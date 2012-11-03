#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int g[30][30];
int f[30],a[30];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    //freopen("F.in","r",stdin);
    //freopen("F2.out","w",stdout);

	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    memset(g,63,sizeof(g));
	    scanf("%d%d",&n,&m);
	    for (int i = 0;i < m;i++)
	    {
	        int u,v,w;
	        scanf("%d%d%d",&u,&v,&w);
	        u--;
	        v--;
	        g[u][v] = g[v][u] = w;
	    }

        long long ans = 0;
        for (int sta = 1;sta < (1<<n);sta++)
        {
            int cnt = 0;
            for (int i = 0;i < n;i++)
                if (((sta>>i)&1) == 1)
                    a[cnt++] = i;
            if (cnt < 2)    continue;

            for (int i = 0;i < cnt;i++)
                f[i] = i;
            for (int i = 0;i < cnt;i++)
                    for (int j = 0;j < cnt;j++)
                        if (g[a[i]][a[j]] != 0x3f3f3f3f)
                            f[findf(i)] = findf(j);

            bool flag = true;
            for (int i = 0;i < cnt;i++)
                if (findf(i) != findf(0))
                    flag = false;
            if (!flag)  continue;

            int mine = 0x3f3f3f3f;
            for (int i = 0;i < cnt;i++)
                for (int j = 0;j < cnt;j++)
                    mine = min(mine,g[a[i]][a[j]]);

            flag = true;
            for (int i = 0;i < n;i++)
                if (((sta>>i)&1) == 0)
                    for (int j = 0;j < cnt;j++)
                        if (g[i][a[j]] != 0x3f3f3f3f)
                        {
                            if (g[i][a[j]] >= mine)
                                flag = false;
                        }
            if (flag)
                ans += cnt;
        }
        printf("%lld\n",ans);
	}
    return 0;
}

