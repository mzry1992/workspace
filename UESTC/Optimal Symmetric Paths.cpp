#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int n,g[100][100];

const int MAXN=100*100;
const int MAXM=100*100*4;

int N,L;
int head[MAXN];
struct edges
{
    int to,next,cost;
} edge[MAXM];
int dist[MAXN],difw[MAXN];
class states
{
public:
    int cost,id;
};
class cmp
{
public:
    bool operator ()(const states &i,const states &j)
    {
        return i.cost>j.cost;
    }
};
void init(int n)
{
    N=n;
    L=0;
    for (int i=0; i<n; i++)
        head[i]=-1;
}
void add_edge(int x,int y,int cost)
{
    edge[L].to=y;
    edge[L].cost=cost;
    edge[L].next=head[x];
    head[x]=L++;
}
const int mod =  1000000009;

int dijkstra(int s,int t)
{
    memset(dist,63,sizeof(dist));
    memset(difw,0,sizeof(difw));
    states u;
    u.id=s;
    u.cost=0;
    dist[s]=0;
    difw[s] = 1;
    priority_queue<states,vector<states>,cmp> q;
    q.push(u);
    while (!q.empty())
    {
        u=q.top();
        q.pop();
        if (u.id==t)
        {
            return difw[t];
        }
        if (u.cost!=dist[u.id]) continue;
        for (int i=head[u.id]; i!=-1; i=edge[i].next)
        {
            states v=u;
            v.id=edge[i].to;
            if (dist[v.id]>dist[u.id]+edge[i].cost)
            {
                v.cost=dist[v.id]=dist[u.id]+edge[i].cost;
                difw[v.id] = difw[u.id];
                q.push(v);
            }
            else if (dist[v.id]==dist[u.id]+edge[i].cost)
                difw[v.id] = (difw[v.id]+difw[u.id])%mod;
        }
    }
}
int id[100][100],totid,tx,ty;
int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            for (int j =0; j < n; j++)
            {
                scanf("%d",&g[i][j]);
                if (i+j <= n-1) continue;
                g[n-1-j][n-1-i] += g[i][j];
            }
        totid = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i+j <= n-1)
                    id[i][j] = totid++;
        init(totid+1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i+j <= n-1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        tx = i+step[k][0];
                        ty = j+step[k][1];
                        if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                        if (tx+ty > n-1)    continue;
                        add_edge(id[i][j],id[tx][ty],g[i][j]);
                    }
                    if (i+j == n-1)
                        add_edge(id[i][j],totid,g[i][j]);
                }
        printf("%d\n",dijkstra(0,totid));
    }
    return 0;
}
