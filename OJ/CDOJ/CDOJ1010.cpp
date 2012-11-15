#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct edges
{
    int to,key;
    edges* next;
}edge[200010];
edges* head[1001];
edges* cur;
int dis[1001],vst[1001];
void add_edge(int x,int y,int z)
{
    cur->to=y;
    cur->key=z;
    cur->next=head[x];
    head[x]=cur++;
}
void spfa(int s,int t)
{
    memset(dis,63,sizeof(dis));
    memset(vst,0,sizeof(vst));
    queue<int>q;
    dis[s]=0;
    q.push(s);
    vst[s]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        vst[u] = 0;
        for (edges* i=head[u];i;i=i->next)
        {
            int v=i->to;
            if (dis[v]>dis[u]+i->key)
            {
                dis[v]=dis[u]+i->key;
                if (!vst[v])
                {
                    vst[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m),n&&m)
    {
        for (int i=1;i<=n;i++)
            head[i]=NULL;
        cur=edge;
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(x,y,z);
            add_edge(y,x,z);
        }
        spfa(1,n);
        printf("%d\n",dis[n]);
    }
    return 0;
}
