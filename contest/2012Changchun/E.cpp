#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge
{
	int u,v,len;
	Edge(){}
	Edge(int _u,int _v,int _len)
	{
		u=_u;
		v=_v;
		len=_len;
	}
	bool operator<(const Edge &x)const
	{
		return len>x.len;
	}
}edge[199999];
int fa[200000],size[200000];
long long tot[200000];
int find(int x)
{
	if (x==fa[x])
		return x;
	else
		return fa[x]=find(fa[x]);
}
void unions(Edge e)
{
	int u=find(e.u),v=find(e.v),len=e.len;
	tot[u]=max(tot[u]+(long long)size[v]*len,tot[v]+(long long)size[u]*len);
	size[u]+=size[v];
	fa[v]=u;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0; i<n; i++)
        {
            fa[i]=i;
            size[i]=1;
            tot[i]=0;
        }
        for (int i=0;i<n-1;i++)
        {
        	int u,v,len;
        	scanf("%d%d%d",&u,&v,&len);
        	edge[i]=Edge(u-1,v-1,len);
        }
        sort(edge,edge+n-1);
        for (int i=0;i<n-1;i++)
			unions(edge[i]);
		printf("%lld\n",tot[find(0)]);
    }
    return 0;
}
