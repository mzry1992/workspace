#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[505][505][2];
int n;
int head[505],e;
const int inf = 1<<29;
int seg[505];
struct N
{
    int v,next;
    int len;
}edge[505];
void addedge(int u,int v,int l)
{
    edge[e].v=v;
    edge[e].len=l;
    edge[e].next=head[u];
    head[u]=e++;
}
int findseg(int x)
{
    if(seg[x]==x)
        return x;
    else
        return seg[x]=findseg(seg[x]);
}
void dfs(int s)
{
    int i,v;
    for(i=2;i<=n;i++)
    {
        dp[s][i][0]=inf;
        dp[s][i][1]=inf;
    }
    dp[s][1][0]=dp[s][1][1]=0;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        dfs(v);
        int j,k;
        for(j=n;j>0;j--)
            for(k=n-j;k>0;k--)
            {
                dp[s][j+k][0]=min(dp[s][j+k][0],dp[s][j][1]+dp[v][k][0]+edge[i].len);
                dp[s][j+k][0]=min(dp[s][j+k][0],dp[s][j][0]+dp[v][k][1]+2*edge[i].len);
            }
        for(j=n;j>0;j--)
            for(k=n-j;k>0;k--)
                dp[s][j+k][1]=min(dp[s][j+k][1],dp[s][j][1]+dp[v][k][1]+2*edge[i].len);
    }
}
int main()
{
    int cas=1;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0)
            break;
        memset(head,-1,sizeof(head));
        e=0;
        int i;
        for(i=0;i<n;i++)
            seg[i]=i;
        for(i=0;i<n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(b,a,c);
            seg[a]=b;
        }
        int root=findseg(0);
        dfs(root);
        int q,j;
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        for(i=0;i<q;i++)
        {
            int x;
            scanf("%d",&x);
            for(j=n;j>0;j--)
                if(x>=dp[root][j][0])
                {
                    printf("%d\n",j);
                    break;
                }
        }
	}
    return 0;
}

