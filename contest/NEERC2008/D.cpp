#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
const int inf= 1<<30;
bool vis[1005];
int C[1005];
struct N
{
	int c1,c2;
	int val;
	bool used;
}edge[10005];
struct M
{
	int country;
	int money;
	int c;
}city[1005];
bool cmp(N a,N b)
{return a.val<b.val;}
bool arr(M a,M b)
{return a.money<b.money;}
int main()
{
	while(scanf("%d",&n)==1)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&city[i].country,&city[i].money);
			city[i].c=i+1;
			C[i+1]=city[i].country;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&edge[i].c1,&edge[i].c2,&edge[i].val);
			edge[i].used=false;
		}
		sort(edge,edge+m,cmp);
		sort(city,city+n,arr);
		memset(vis,false,sizeof(vis));
		for(i=0;i<n;i++)
		{
			int j,mi=inf,ma=-1,p1,p2;
			for(j=0;j<m;j++)
				if(!edge[j].used&&edge[j].c2!=city[i].c&&C[edge[j].c2]==city[i].country)
				{
					if(edge[j].c1==city[i].c)
					{
						if(ma<edge[j].val)
						{
							ma=edge[j].val;
							p1=j;
						}
					}
					else
					{
						if(mi>edge[j].val)
						{
							mi=edge[j].val;
							p2=j;
						}
					}
				}
			if(ma==-1&&city[i].money>=mi)
			{
				vis[city[i].c]=true;
				edge[p2].used=true;
			}
			else if(ma!=-1)
			{
				vis[city[i].c]=true;
				if(mi<=ma || mi == inf)
					edge[p1].used=true;
				else
					edge[p2].used=true;
			}
		}
		int ans=0;
		for(i=1;i<=n;i++)
			if(vis[i])
				ans++;
		printf("%d\n",ans);
	}
    return 0;
}

