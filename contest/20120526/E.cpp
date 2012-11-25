#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next;
}edge[20000];
int head[10000],L;
int n,m;
int visit2[10000],visit[10000],tot,maxdeep,maxdeepid;
struct Point
{
    int x,y;
    bool operator < (const Point& b)const
    {
        if (x == b.x)   return y < b.y;
        return x < b.x;
    }
};

Point a[10000],p[10000];
int top;

void init(int n)
{
    for (int i = 0;i < n;i++)
        head[i] = -1;
    L = 0;
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

void DFS(int now,int deep)
{
    visit[now] = tot;
    if (deep > maxdeep)
    {
        maxdeep = deep;
        maxdeepid = now;
    }
    for (int i = head[now];i != -1;i = edge[i].next)
        if (visit[edge[i].to] == -1)
            DFS(edge[i].to,deep+1);
}

void DFS2(int now,int deep)
{
    visit2[now] = tot;
    if (deep > maxdeep)
    {
        maxdeep = deep;
        maxdeepid = now;
    }
    for (int i = head[now];i != -1;i = edge[i].next)
        if (visit2[edge[i].to] == -1)
            DFS2(edge[i].to,deep+1);
}

int q;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d%d",&n,&m);
        init(n);
        for (int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(u,v);
            addedge(v,u);
        }
        memset(visit,-1,sizeof(visit));
        memset(visit2,-1,sizeof(visit2));
        tot = 0;
        for (int i = 0;i < n;i++)
            if (visit[i] == -1)
            {
                maxdeep = 0;
                maxdeepid = i;
                DFS(i,0);
                maxdeep = 0;
                DFS2(maxdeepid,1);
                a[tot].x = 0;
                a[tot++].y = maxdeep;
            }
        for (int i = 0;i < n;i++)
            a[visit[i]].x++;
        sort(a,a+tot);
        top = 0;
        for (int i = 0;i < tot;i++)
        {
            while (top > 0 && p[top-1].x <= a[i].x && p[top-1].y <= a[i].y) top--;
            p[top++] = a[i];
        }
        scanf("%d",&q);
        printf("Case %d:\n",cas);
        for (int i = 0;i < q;i++)
        {
            int K;
            scanf("%d",&K);
            if (K > p[top-1].x)
            {
                puts("impossible");
                continue;
            }
            Point tmp;
            tmp.x = K;
            tmp.y = 0;
            int pos = upper_bound(p,p+top,tmp)-p;
            int res = (K-p[pos].y)*2+(p[pos].y-1);
            if (K <= p[pos].y)
                res = K-1;
            printf("%d\n",res);
        }
	}
	return 0;
}
