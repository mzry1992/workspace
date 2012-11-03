#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000001;
const int MAXM=4000001;
int N,L;
int head[MAXN];
struct edges
{
    int to,next,cost;
}edge[MAXM];
int dist[MAXN];
class states
{
    public:
        int cost,id;
};
class cmp
{
    public:
       bool operator ()(const states &i,const states &j){
            return i.cost>j.cost;
       }
};
void init(int n)
{
    N=n;L=0;
    memset(head, -1 ,sizeof(head));
}
void add_edge(int x,int y,int cost)
{
    edge[L].to=y;
    edge[L].cost=cost;
    edge[L].next=head[x];
    head[x]=L++;
}

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


int n,m;
int g[1010][1010];


inline int getid(int x,int y)
{
    return y*1000+x;
}

bool go(states &p , int d)
    {
        int x = p.id% 1000;
        int y = p.id/1000;
        x += step[d][0];
        y += step[d][1];
        if(x >= 0 && x<n && y>=0 && y<m)
            {
                p.id = getid(x,y);
                return true;
            }
        return false;
    }
int dijkstra(int s,int t)
{
    memset(dist,63,sizeof(dist));
    states u;
    u.id=s;
    u.cost=0;
    dist[s]=g[u.id%1000][u.id/1000];
    priority_queue<states,vector<states>,cmp> q;
    q.push(u);
    while (!q.empty())
    {
        u=q.top();
        q.pop();
        if (u.id==t) return dist[t];
        for (int d = 0 ; d < 4 ;d++)
        {
            states v=u;
            if(go(v , d) == false) continue;
            if (dist[v.id]>dist[u.id]+g[v.id%1000][v.id/1000])
            {
                v.cost=dist[v.id]=dist[u.id]+g[v.id%1000][v.id/1000];
                q.push(v);
            }
        }
    }
    return -1;
}
inline int getval(char c)
{
    if (c == '.')   return 1;
    return 0;
}

int sx,sy,ex,ey;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init(n*m);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&g[i][j]);
        printf("%d\n",dijkstra(getid(0,0),getid(n-1,m-1)));
    }
    return 0;
}
