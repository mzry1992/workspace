#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int dis[10002],head[10002],pre[10002];
bool inque[10002];
int N,L;
struct Edge
{
    int to,next;
}edge[240000];
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
    edge[L].to=u;
    edge[L].next=head[v];
    head[v]=L++;
}
void init(int n)
{
    N=n;
    L=0;
    memset(head,-1,4*n);
    memset(inque,0,n);
}
vector<int> ans;
void solve()
{
    queue<int> que;
    for (int i=head[0];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (dis[0]==dis[v]+1)
        {
            pre[v]=0;
            que.push(v);
            inque[v]=1;
        }
    }
    while (!que.empty())
    {
        int u=que.front();
        que.pop();
        for (int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if (dis[v]+1==dis[u] && !inque[v])
            {
                if (v==N-1)
                {
                    ans.push_back(u);
                    break;
                }
                pre[v]=u;
                que.push(v);
                inque[v]=1;
                break;
            }
        }
    }
}
int bfs()
{
    memset(dis,63,4*N);
    queue<int> que;
    dis[N-1]=0;
    que.push(N-1);
    while (!que.empty())
    {
        int u=que.front();
        que.pop();
        for (int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if (dis[v]==0x3f3f3f3f)
            {
                dis[v]=dis[u]+1;
                que.push(v);
            }
        }
    }
    return dis[0];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n+2);
    while (m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    scanf("%d",&m);
    while (m--)
    {
        int x;
        scanf("%d",&x);
        add_edge(0,x);
    }
    scanf("%d",&m);
    while (m--)
    {
        int x;
        scanf("%d",&x);
        add_edge(x,n+1);
    }
    int len=bfs()-2;
    solve();
    printf("%d %d\n",ans.size(),len);
    for (int i=0;i<ans.size();i++)
    {
        stack<int> st;
        for (int j=ans[i];j;j=pre[j])
            st.push(j);
        while (!st.empty())
        {
            printf("%d ",st.top());
            st.pop();
        }
        puts("");
    }
    return 0;
}
