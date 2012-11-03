#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 205
#define MAXM 40005
using namespace std;
int mp[205][205],pre[205][205],n;
struct Edge
{
	int from,to,next;
};
Edge edge[MAXM];
int box[MAXN],cnt;
void add_edge(int from,int to)
{
	edge[cnt].from=from;
	edge[cnt].to=to;
	edge[cnt].next=box[from];
	box[from]=cnt++;
}
int low[MAXN],id[MAXN],state[MAXN],top,t,clr,bel[MAXN],stack[MAXN];
void dfs(int u)
{
	id[u]=low[u]=t++;
	state[u]=1;//标记为已访问
	stack[top++]=u;
	int v;
	for(int p=box[u];p!=-1;p=edge[p].next)
	{
		v=edge[p].to;
		if(!state[v])
		{
			dfs(v);
			//看是不是能回到更先访问的节点
			low[u]=min(low[u],low[v]);
		}
		else if(state[v]==1)//同上
			low[u]=min(low[u],low[v]);
	}
	if(low[u]==id[u])// 连通分量的根节点
	{
		clr++;
		do
		{
			v=stack[--top];
			bel[v]=clr;
			state[v]=-1;
		}while(v!=u);
	}
}
void tarjan()
{
	//state[i]==0:i节点还没有访问到
	memset(state,0,sizeof(state));
	t=0;clr=0;//记录时间戳和属于那个强连通分量
	for(int i=1;i<=n;i++)//节点从1开始
		if(!state[i])//未访问
		{
			top=0;//weidfs中的压栈做准备
			dfs(i);
		}
	memset(mp,0,sizeof(mp));
	int ans=0;
	for(int i=1;i<=clr;i++)
	{
		int tmp=0;
		for(int j=1;j<=n;j++)
		{
			if(bel[j]==i) tmp++;
		}
		if(tmp>1) ans+=tmp;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(bel[i]!=bel[j]&&pre[i][j]&&mp[bel[i]][bel[j]]==0)
			{
				mp[bel[i]][bel[j]]=1;
				ans++;
			}
		}
	for(int i=1;i<=clr;i++)
		for(int j=1;j<=clr;j++)
		{
			if(i!=j&&mp[i][j])
			{
				for(int k=1;k<=clr;k++)
				{
					if(k!=i&&k!=j&&mp[i][k]&&mp[k][j])
					{
						ans--;
						break;
					}
				}
			}
		}
	printf("%d\n",ans);
}
int main()
{
    int ft = 0;
    freopen("DINFA.txt","r",stdin);
    freopen("DINFA1.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		memset(box,-1,sizeof(box));
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&pre[i][j]);
				if(pre[i][j]&&i!=j) add_edge(i,j);
			}
		}
		ft++;
		if (ft == 114)
		{
		    printf("%d\n",n);
		    for (int i = 1;i <= n;i++)
            {
                for (int j = 1;j <= n;j++)
                    printf("%d ",pre[i][j]);
                printf("\n");
            }
		}
		printf("%d ",ft);
		tarjan();
	}
	return 0;
}
