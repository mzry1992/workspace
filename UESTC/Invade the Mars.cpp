#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct edges
{
    int to,key,next;
}edge[9000000];
bool ma[3000][3000];
int head[3000];
long long dis[3000],dp[3000];
bool flag[3000];
int N,L;
void add_edge(int x,int y,int z)
{
    edge[L].to=y;
    edge[L].key=z;
    edge[L].next=head[x];
    head[x]=L++;
}
void init(int n)
{
    N=n;L=0;
    for (int i=0;i<n;i++)
        head[i]=-1;
}
void spfa(int s)
{
    memset(dis,63,sizeof(dis));
    memset(flag,0,sizeof(flag));
    dis[s]=0;
    queue<int>que;
    que.push(s);
    while (!que.empty())
    {
        int u=que.front();
        flag[u]=0;
        for (int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if (dis[v]>dis[u]+edge[i].key)
            {
                dis[v]=dis[u]+edge[i].key;
                if (!flag[v])
                {
                    flag[v]=1;
                    que.push(v);
                }
            }
        }
        que.pop();
    }
}
long long solve(int x)
{
    if (flag[x]) return dp[x];
    flag[x]=1;
    long long max=dis[x];
    for (int i=head[x];i!=-1;i=edge[i].next)
        if (max<solve(edge[i].to))
            max=solve(edge[i].to);
    return dp[x]=max;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                ma[i][j]=0;
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(x-1,y-1,z);
        }
        spfa(0);
        init(n);
        for (int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            for (int j=0;j<k;j++)
            {
                int x;
                scanf("%d",&x);
                ma[i][x-1]=1;
            }
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (ma[i][j])
                    add_edge(i,j,0);
        memset(flag,0,sizeof(flag));
        printf("%I64d\n",solve(n-1));
    }
    return 0;
}
