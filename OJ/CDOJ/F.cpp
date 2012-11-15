#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int n,m,tim,id[15][15],rid[15*15][2],dis[15*15][15*15];
char mp[15][15];
struct node
{
    int x,y,step;
    node(){}
    node(int _x,int _y,int _step)
        {
            x = _x;
            y = _y;
            step = _step;
        }
};
queue<node> Q;
node now,updata;
bool visit[15][15];
const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void BFS(int x,int y)
{
    while (!Q.empty())  Q.pop();
    Q.push(node(x,y,0));
    memset(visit,false,sizeof(visit));
    visit[x][y] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (mp[now.x][now.y] == 'E')
        {
            dis[id[x][y]][id[now.x][now.y]] = now.step;
            continue;
        }
        for (int i = 0;i < 4;i++)
        {
            updata.x = now.x+step[i][0];
            updata.y = now.y+step[i][1];
            updata.step = now.step+1;
            if (updata.x >= 0 && updata.x < n && updata.y >= 0 && updata.y < m)
                if (mp[updata.x][updata.y] != 'X')
                    if (visit[updata.x][updata.y] == false)
                    {
                        visit[updata.x][updata.y] = true;
                        Q.push(updata);
                    }
        }
    }
}

const int MAXEDGE=20400000;
const int MAXN=400000;
const int inf=0x3fffffff;
struct edges
{
    int cap,to,next,flow;
} edge[MAXEDGE+100];
struct nodes
{
    int head,label,pre,cur;
} node[MAXN+100];
int L,N;
int gap[MAXN+100];
void init(int n)
{
    L=0;
    N=n;
    for (int i=0; i<N; i++)
        node[i].head=-1;
}
void add_edge(int x,int y,int z,int w)
{
    edge[L].cap=z;
    edge[L].flow=0;
    edge[L].to=y;
    edge[L].next=node[x].head;
    node[x].head=L++;
    edge[L].cap=w;
    edge[L].flow=0;
    edge[L].to=x;
    edge[L].next=node[y].head;
    node[y].head=L++;
}
int maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    gap[0]=N;
    int u,ans=0;
    for (int i=0; i<N; i++)
    {
        node[i].cur=node[i].head;
        node[i].label=0;
    }
    u=s;
    node[u].pre=-1;
    while (node[s].label<N)
    {
        if (u==t)
        {
            int min=inf;
            for (int i=node[u].pre; i!=-1; i=node[edge[i^1].to].pre)
                if (min>edge[i].cap-edge[i].flow)
                    min=edge[i].cap-edge[i].flow;
            for (int i=node[u].pre; i!=-1; i=node[edge[i^1].to].pre)
            {
                edge[i].flow+=min;
                edge[i^1].flow-=min;
            }
            u=s;
            ans+=min;
            continue;
        }
        bool flag=false;
        int v;
        for (int i=node[u].cur; i!=-1; i=edge[i].next)
        {
            v=edge[i].to;
            if (edge[i].cap-edge[i].flow && node[v].label+1==node[u].label)
            {
                flag=true;
                node[u].cur=node[v].pre=i;
                break;
            }
        }
        if (flag)
        {
            u=v;
            continue;
        }
        node[u].cur=node[u].head;
        int min=N;
        for (int i=node[u].head; i!=-1; i=edge[i].next)
            if (edge[i].cap-edge[i].flow && node[edge[i].to].label<min) min=node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label]) return ans;
        node[u].label=min+1;
        gap[node[u].label]++;
        if (u!=s) u=edge[node[u].pre^1].to;
    }
    return ans;
}
bool check(int lim)
{
    init(n*m*lim+2);
    int tot=0;
    for (int i=0;i<n*m;i++)
    {
        int x=rid[i][0],y=rid[i][1];
        if (mp[x][y]!='.') continue;
        tot++;
        add_edge(n*m*lim,i*lim,1,0);
        for (int j=0;j<n*m;j++)
            if (dis[i][j] && dis[i][j]<lim)
                add_edge(i*lim,j*lim+dis[i][j],1,0);
    }
    for (int i=0;i<n*m;i++)
    {
        int x=rid[i][0],y=rid[i][1];
        if (mp[x][y]=='E')
        {
            for (int j=1;j<lim;j++)
                add_edge(i*lim+j-1,i*lim+j,inf,0);
            for (int j=0;j<lim;j++)
                add_edge(i*lim+j,n*m*lim+1,1,0);
        }
    }
    return maxflow(n*m*lim,n*m*lim+1)==tot;
}
int main()
{
    while (scanf("%d%d%d",&n,&m,&tim) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                id[i][j] = i*n+j;
                rid[i*n+j][0] = i;
                rid[i*n+j][1] = j;
            }
        memset(dis,0,sizeof(dis));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (mp[i][j] == '.')
                    BFS(i,j);
        int l=1,r=tim+1;
        while (l<r)
        {
            int mid=l+r>>1;
            if (check(mid))
                r=mid;
            else
                l=mid+1;
        }
        if (l==tim+1 && !check(tim+1))
            puts("impossible");
        else
            printf("%d\n",l-1);
    }
    return 0;
}
