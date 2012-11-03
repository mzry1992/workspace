#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int u,v,w;
    bool operator <(const Edge& b)const
    {
        return w > b.w;
    }
};

Edge edge[12497500];
int n,m;
int f[5000],size[5000],last[5000];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

bool flag[5000][5000];
int main()
{
    //freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);

	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d%d",&n,&m);
	    memset(flag,false,sizeof(flag));
	    for (int i = 0;i < m;i++)
	    {
	        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	        edge[i].u--;
	        edge[i].v--;
	        if (edge[i].u > edge[i].v)
                swap(edge[i].u,edge[i].v);
	        while (flag[edge[i].u][edge[i].v] == true)
                puts("fuck");
            flag[edge[i].u][edge[i].v] = true;
	    }
	    sort(edge,edge+m);
        for (int i = 0;i < n;i++)
        {
            f[i] = i;
            size[i] = 1;
            last[i] = -1;
        }
        long long ans = 0;
        for (int i = 0;i < m;i++)
        {
            int fa = findf(edge[i].u);
            int fb = findf(edge[i].v);
            if (fa != fb)
            {
                if (last[fa] == edge[i].w)  ans -= size[fa];
                if (last[fb] == edge[i].w)  ans -= size[fb];
                ans += size[fa]+size[fb];
                size[fa] += size[fb];
                f[fb] = fa;
                last[fa] = edge[i].w;
            }
        }

        printf("%lld\n",ans);

	}
    return 0;
}

