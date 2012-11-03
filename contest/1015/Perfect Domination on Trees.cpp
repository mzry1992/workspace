#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x7fffffff;
const int MAXN=1000;
const int MAXM=999;
struct edges
{
    int to,next;
}edge[MAXM*2];
int head[MAXN];
int L;
void init(int n)
{
    L=0;
    memset(head,-1,4*n);
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
int dp[1001][3];//0 没选没覆盖 1 没选已覆盖 2 已选
void dfs(int u,int fu)
{
    int sum0=0,sum1=0,d=5000;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu)
            continue;
        dfs(v,u);
        sum0+=min(dp[v][0],dp[v][2]);
        sum1+=dp[v][1];
        d=min(dp[v][2]-dp[v][1],d);
    }
    dp[u][0]=sum1;
    dp[u][1]=d+sum1;
    dp[u][2]=sum0+1;
}
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        init(n+1);
        for (int i=0;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(--u,--v);
            add_edge(v,u);
        }
        dfs(0,-1);
        printf("%d\n",min(dp[0][1],dp[0][2]));
    }
    return 0;
}
