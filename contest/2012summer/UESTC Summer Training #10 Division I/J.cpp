#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,S;
struct N
{
    int u,v;
    int len;
}e[400005];
int mp[1005][1005];
int dis[1005];
bool flag[1005];
bool dijkstra(int s)
{
    memset(dis,63,sizeof(dis));
    memset(flag,0,sizeof(flag));
    dis[s]=0;
    for (int i=0;i<n;i++)
    {
        int idx=-1,mindis=0x7fffffff;
        for (int j=0;j<n;j++)
            if (!flag[j] && dis[j]<mindis)
            {
                idx=j;
                mindis=dis[j];
            }
        if (idx==-1)
            return 0;
        flag[idx]=1;
        for (int j=0;j<n;j++)
            dis[j]=min(dis[j],dis[idx]+mp[idx][j]);
    }
    for (int i=0;i<n;i++)
        if (dis[i]>=0x3f3f3f3f)
            return 0;
    return 1;
}
int u,v,l;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&S);
        int i,j;
        memset(mp,63,sizeof(mp));
        for(i=0; i<m; i++)
        {
            //scanf("%d%d%d",&u,&v,&l);
            //e[i].u = u;
            //e[i].v = v;
            //e[i].len = l;
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].len);
            mp[e[i].v][e[i].u]=mp[e[i].u][e[i].v]=min(mp[e[i].u][e[i].v],e[i].len);
        }
		if(dijkstra(S))
		{
			double ans=0;
			for(i=0; i<m; i++)
				ans=max(ans,(e[i].len+dis[e[i].u]+dis[e[i].v])*0.5);
            printf("%.2f\n",ans);
		}
        else
            printf("Sorry Amoo, your domino does not complete!\n");
    }
    return 0;
}
