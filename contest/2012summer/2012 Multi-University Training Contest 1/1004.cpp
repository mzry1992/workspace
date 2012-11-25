#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")

struct edges
{
    int to,next,c;
} edge[299999*2];
int head[300000],L;
long long dp[300000];
int num[300000];
int a[300000];
long long ans=0;
void init(int n)
{
    L=0;
    memset(head,-1,4*n);
}
void add_edge(int u,int v,int c)
{
    edge[L].to=v;
    edge[L].c=c;
    edge[L].next=head[u];
    head[u]=L++;
}
void dfs(int u,int fu,int prec)
{
    map<int,long long> sumc,numc;
    dp[u]=num[u]=0;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu)
            continue;
        dfs(v,u,edge[i].c);
        if (edge[i].c!=prec)
        {
            dp[u]+=dp[v]+a[u]*num[v];
            num[u]+=num[v];
        }
        sumc[edge[i].c]+=dp[v];
        numc[edge[i].c]+=num[v];
    }
    dp[u]+=a[u];
    num[u]++;
    long long presum=0,prenum=0;
    for (map<int,long long>::iterator it=sumc.begin(),itn=numc.begin(); it!=sumc.end(); it++,itn++)
    {
        ans+=itn->second*prenum*a[u]+it->second*prenum+presum*itn->second;
        ans+=it->second+itn->second*a[u];
        presum+=it->second;
        prenum+=itn->second;
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        init(n);
        ans=0;
        for (int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for (int i=1; i<n; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add_edge(--u,--v,c);
            add_edge(v,u,c);
        }
        dfs(0,-1,-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
