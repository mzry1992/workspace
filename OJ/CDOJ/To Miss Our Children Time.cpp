#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool flag[1000];
int head[1000],L;
long long dp[1000];
struct edges
{
    int to,next;
}edge[1000000];
struct items
{
    int a,b,type;
    long long c;
}item[1000];
void init(int n)
{
    memset(flag,1,n);
    memset(head,-1,n*4);
    memset(dp,-1,n*sizeof(dp[0]));
    L=0;
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
void check(int u,int v)
{
    if (item[v].a>=item[u].a && item[v].b>=item[u].b)
    {
        if (!item[v].type)
            add_edge(u,v);
        else if (item[v].type==1 && (item[v].a>item[u].a || item[v].b>item[u].b))
            add_edge(u,v);
        else if (item[v].a>item[u].a && item[v].b>item[u].b)
            add_edge(u,v);
    }
}
long long calc(int x)
{
    if (dp[x]!=-1) return dp[x];
    long long max=0;
    for (int i=head[x];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (max<calc(v))
            max=calc(v);
    }
    return dp[x]=max+item[x].c;
}
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%I64d%d",&item[i].a,&item[i].b,&item[i].c,&item[i].type);
            if (item[i].a < item[i].b)
                swap(item[i].a,item[i].b);
        }
        init(n);
        for (int i=0;i<n;i++)
            if (!item[i].type && flag[i])
                for (int j=i+1;j<n;j++)
                    if (!item[j].type && item[i].a==item[j].a && item[i].b==item[j].b && flag[j])
                    {
                        flag[j]=0;
                        item[i].c+=item[j].c;
                    }
        for (int i=0;i<n;i++)
            if (flag[i])
                for (int j=0;j<n;j++)
                    if (i!=j && flag[j])
                        check(i,j);
        long long ans=0;
        for (int i=0;i<n;i++)
            if (flag[i] && ans<calc(i))
                ans=dp[i];
        printf("%I64d\n",ans);
    }
    return 0;
}
