#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct Edge
{
    int to,next,len;
} edge[3000*2];
struct Vertex
{
    int dist,id;
    Vertex() {}
    Vertex(int _id,int _dist)
    {
        dist=_dist;
        id=_id;
    }
    bool operator<(const Vertex &a) const
    {
        return dist>a.dist;
    }
};

map<string,int> name;
int n,m,cap,totname,L;
int head[3000*2+2+300],dist[3000*2+2+300];
char tmpa[20],tmpb[20];
int ma[302][302];
int ids[3000*2+2+300],idx[3000*2+2+300];
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
}

void addedge(int u,int v,int len)
{
    edge[L].to=v;
    edge[L].len=len;
    edge[L].next=head[u];
    head[u]=L++;
}

void dijkstra(int si)
{
    memset(dist,63,sizeof(dist));
    Vertex s=Vertex(si,0);
    priority_queue<Vertex,vector<Vertex> > que;
    dist[si]=0;
    que.push(s);
    while (!que.empty())
    {
        Vertex u=que.top();
        que.pop();
        if (u.dist!=dist[u.id])
            continue;
        for (int i=head[u.id]; i!=-1; i=edge[i].next)
        {
            Vertex v=Vertex(edge[i].to,dist[edge[i].to]);
            if (v.dist>u.dist+edge[i].len)
            {
                dist[v.id]=v.dist=u.dist+edge[i].len;
                que.push(v);
            }
        }
    }
}
void solve(int id)
{
    dijkstra(idx[id]);
    for (int i=0; i<m+2; i++)
        ma[id][i]=dist[idx[i]];
}
const int inf=0x3f3f3f3f;
int main()
{
    while(scanf("%d%d%d",&n,&m,&cap)!=EOF,n||m||cap)
    {
        cap*=10;
        init(n*2+2+m);
        scanf("%s%s",tmpa,tmpb);
        getid(tmpa);
        getid(tmpb);
        idx[0]=0;
        idx[1]=1;
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
            int u = getid(tmpa);
            idx[i+2]=u;
        }
        for (int i=0; i<m+2; i++)
            solve(i);
        for (int i=0; i<m+2; i++)
            for (int j=0; j<m+2; j++)
                if (ma[i][j]>cap)
                    ma[i][j]=inf;
        for (int k=0; k<m+2; k++)
            for (int i=0; i<m+2; i++)
                for (int j=0; j<m+2; j++)
                    ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
        if (ma[0][1]==inf)
            ma[0][1]=-1;
        printf("%d\n",ma[0][1]);
    }
    return 0;
}
