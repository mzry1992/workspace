#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int head[100],eva[100];
bool inque[100];
vector<int> path;
struct Edge
{
    int to,next,dis;
} edge[10000];
int n,L,s,t,k;
void add_edge(int u,int v,int dist)
{
    edge[L].to=v;
    edge[L].dis=dist;
    edge[L].next=head[u];
    head[u]=L++;
}
void init()
{
    memset(eva,63,4*n);
    memset(inque,0,n);
    eva[t]=0;
    queue<int> que;
    que.push(t);
    while (!que.empty())
    {
        int u=que.front();
        que.pop();
        inque[u]=0;
        for (int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if (eva[v]>eva[u]+edge[i].dis)
            {
                eva[v]=eva[u]+edge[i].dis;
                if (!inque[v])
                {
                    inque[v]=1;
                    que.push(v);
                }
            }
        }
    }
}
int tot,bound,ans;
bool flag[100];
bool dfs(int u,int length)
{
    if (u==t)
    {
        tot++;
        if (ans)
            if (length==bound)
                return 1;
            else
                return 0;
        else if (tot>=k)
            return 1;
        else
            return 0;
    }
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if (flag[v] || length+edge[i].dis+eva[v]>bound)
            continue;
        flag[v]=1;
        if (ans)
            path.push_back(v);
        if (dfs(v,length+edge[i].dis))
            return 1;
        if (ans)
            path.pop_back();
        flag[v]=0;
    }
    return 0;
}
bool check(int _bound)
{
    bound=_bound;
    tot=0;
    ans=0;
    memset(flag,0,n);
    flag[s]=1;
    return dfs(s,0);
}
int main()
{
    freopen("145in.txt","r",stdin);
    freopen("145out2.txt","w",stdout);
    int m;
    while (scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        L=0;
        memset(head,-1,4*n);
        for (int i=0; i<m; i++)
        {
            int u,v,dis;
            scanf("%d%d%d",&u,&v,&dis);
            add_edge(--u,--v,dis);
            add_edge(v,u,dis);
        }
        scanf("%d%d",&s,&t);
        --t;
        --s;
        while (s==t) ;
        init();
        int l=0,r=1000000;
        while (l<r)
        {
            int mid=l+r>>1;
            if (check(mid))
                r=mid;
            else
                l=mid+1;
        }
        ans=bound=l;
        path.clear();
        path.push_back(s);
        memset(flag,0,n);
        flag[s]=1;
        dfs(s,0);//这一句为什么必须要加
        printf("%d %d\n",l,path.size());
        for (int i=0; i<path.size(); i++)
            printf("%d ",path[i]+1);
        printf("\n");
    }
    return 0;
}
