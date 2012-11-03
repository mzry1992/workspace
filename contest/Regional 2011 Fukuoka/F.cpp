#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct Vertex
{
    int dist,id,oil;
    Vertex() {}
    Vertex(int _id,int _oil,int _dist)
    {
        dist=_dist;
        id=_id;
        oil=_oil;
    }
    bool operator<(const Vertex &a) const
    {
        return dist>a.dist;
    }
};
struct Edge
{
    int to,next,len;
} edge[3000*2];
map<string,int> name;
bool LPG[3000*2+2+300];
int n,m,cap,totname,L;
int head[3000*2+2+300];
int dist[3000*2+2+300][2001];
int dijkstra()
{
    Vertex s=Vertex(0,cap,0);
    priority_queue<Vertex,vector<Vertex> > que;
    dist[0][cap]=0;
    que.push(s);
    while (!que.empty())
    {
        Vertex u=que.top();
        que.pop();
        if (u.dist!=dist[u.id][u.oil])
            continue;
        if (u.id==1)
            return u.dist;
        for (int i=head[u.id]; i!=-1; i=edge[i].next)
        {
            if (u.oil<edge[i].len)
                continue;
            Vertex v=Vertex(edge[i].to,u.oil-edge[i].len,dist[edge[i].to][u.oil-edge[i].len]);
            if (LPG[v.id])
            {
                v.oil=cap;
                v.dist=dist[v.id][cap];
            }
            if (v.dist>u.dist+edge[i].len)
            {
                dist[v.id][v.oil]=v.dist=u.dist+edge[i].len;
                que.push(v);
            }
        }
    }
    return -1;
}

char tmpa[20],tmpb[20];

int getid(char s[])
{
    if (name.find(s) == name.end())
        name[s] = totname++;
    return name[s];
}

void init(int n)
{
    name.clear();
    L=totname = 0;
    memset(head,-1,4*n);
    memset(LPG,0,n);
    memset(dist,63,sizeof(dist));
}

void addedge(int u,int v,int len)
{
    edge[L].to=v;
    edge[L].len=len;
    edge[L].next=head[u];
    head[u]=L++;
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&cap)!=EOF,n||m||cap)
    {
        cap*=10;
        init(n*2+2+m);
        scanf("%s%s",tmpa,tmpb);
        getid(tmpa);
        getid(tmpb);
        for (int i = 0; i < n; i++)
        {
            int tcap;
            scanf("%s%s%d",tmpa,tmpb,&tcap);
            int u = getid(tmpa);
            int v = getid(tmpb);
            addedge(u,v,tcap);
            addedge(v,u,tcap);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%s",tmpa);
            LPG[getid(tmpa)] = true;
        }
        printf("%d\n",dijkstra());
    }
    return 0;
}
