#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int u,v;
}edge[100000];

bool del[100000];
int n,m,q,a[100000],f[100000],tot,ans[100000];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < m;i++)
            scanf("%d%d",&edge[i].u,&edge[i].v);
        scanf("%d",&q);
        memset(del,false,sizeof(del));
        for (int i = 0;i < q;i++)
        {
            scanf("%d",&a[i]);
            a[i]--;
            del[a[i]] = true;
        }
        for (int i = 0;i < n;i++)
            f[i] = i;
        tot = n;
        for (int i = 0;i < m;i++)
            if (del[i] == false)
            {
                int fa = findf(edge[i].u);
                int fb = findf(edge[i].v);
                if (fa != fb)
                {
                    tot--;
                    f[fa] = fb;
                }
            }
        for (int i = q-1;i >= 0;i--)
        {
            ans[i] = tot;
            int fa = findf(edge[a[i]].u);
            int fb = findf(edge[a[i]].v);
            if (fa != fb)
            {
                tot--;
                f[fa] = fb;
            }
        }
        printf("%d",ans[0]);
        for (int i = 1;i < q;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
	return 0;
}
