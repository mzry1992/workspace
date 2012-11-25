#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
    int to,next,from;
}edge[400*400];
int head[400],in[400],tin[400],out[400];
bool flag[400];
int n,L;
void init()
{
    memset(in,0,4*n);
    memset(out,0,4*n);
    memset(head,-1,4*n);
    L=0;
}
void add_edge(int u,int v)
{
    in[v]++;
    out[u]++;
    edge[L].to=v;
    edge[L].next=head[u];
    edge[L].from=u;
    head[u]=L++;
}
bool topsort(int s)
{
    memset(flag,0,sizeof(flag));
    flag[s]=1;
    queue<int> que;
    que.push(s);
    int m=0;
    for (int i=0;i<n;i++)
        tin[i]=in[i];
    while (!que.empty())
    {
        int u=que.front();
        m++;
        que.pop();
        int tot=0;
        for (int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            tin[v]--;
            if (!tin[v] && !flag[v])
            {
                tot++;
                flag[v]=1;
                que.push(v);
            }
        }
        if (tot>1)
            return 0;
    }
    return m==n;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int m;
        scanf("%d%d",&n,&m);
        init();
        for (int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        bool flag=0;
        for (int i=0;i<m && !flag;i++)
            if (in[edge[i].to]==1 && out[edge[i].from]==1)
                flag=topsort(edge[i].to);
        if (flag)
            puts("Yeah, I'm superman");
        else
            puts("Your DAGy was initially defected!");
    }
    return 0;
}
