#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge
{
    int to,next;
};

Edge edge[1000000];
int head[1000],L;
int n,s,f;
double la,lb,x[1000],y[1000];

double dist(double xa,double ya,double xb,double yb)
{
    return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

bool visit[1000];
int dis[1000];

int BFS()
{
    queue<int> Q;
    memset(visit,false,sizeof(visit));
    memset(dis,63,sizeof(dis));
    dis[s] = 0;
    visit[s] = true;
    Q.push(s);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        //printf("now = %d %d\n",now,dis[now]);
        if (now == f)
            return dis[now];
        for (int i = head[now]; i != -1; i = edge[i].next)
            if (visit[edge[i].to] == false)
            {
                dis[edge[i].to] = dis[now]+1;
                visit[edge[i].to] = true;
                Q.push(edge[i].to);
            }
    }
    return -1;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d%d%lf%lf",&n,&s,&f,&la,&lb);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            head[i] = -1;
        }
        s--,f--;
        L = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (dist(x[i],y[i],x[j],y[j]) <= (la+lb)*(la+lb))
                {
                    //printf("aa %d %d\n",i,j);
                    addedge(i,j);
                    addedge(j,i);
                }
        int res = BFS();
        if (res == -1)
            puts("Impossible");
        else
            printf("%d\n",res);
    }
    return 0;
}
