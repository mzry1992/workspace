#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

struct circle
{
    int x,y,r;
};
struct event
{
    int typ,x,id;
    event(){}
    event(int _typ,int _x,int _id)
    {
        typ = _typ;
        x = _x;
        id = _id;
    }
    friend bool operator < (const event &a ,const event &b)
    {
        return a.x < b.x;
    }
};
int xline;
int n,m,q,tote;
circle c[4000];
event e[4000];
inline double getY(int x,int y ,int r ,int type)
{
    int dx = x-xline;
    return y +type*sqrt((double)r*r - (double)dx*dx);
}
struct node
{
    int typ,id;
    node(){}
    node(int _typ,int _id)
    {
        typ = _typ;
        id = _id;
    }
    friend bool operator < (const node& a,const node& b)
    {
        double ya =getY(c[a.id].x , c[a.id].y,c[a.id].r,a.typ) ,
               yb = getY(c[b.id].x , c[b.id].y,c[b.id].r , b.typ);
        if(fabs(ya - yb) < 1e-15) return a.typ < b.typ;
        else return ya < yb ;
    }
};
set<node> tree;
struct Edge
{
    int to,next;
};
Edge edge[4000];
int head[4000],fa[4000],dep[4000],L;

void init(int n)
{
    L = 0;
    for (int i = 0;i < n;i++)
        head[i] = fa[i] = -1;
    dep[0] = 0;
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
    fa[v] = u;
    dep[v] = dep[u]+1;
}

void output(int now,int deep)
{
    for (int i = 0;i < deep;i++)
        printf("  ");
    printf("id = %d",now);
    printf("\n");
    for (int i = head[now];i != -1;i = edge[i].next)
        output(edge[i].to,deep+1);
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    init(n+m+1);
    tote = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&c[i].x,&c[i].y);
        c[i].r = 0;
        e[tote++] = event(0,c[i].x,i);
    }
    for (int i = n+1; i <= n+m; i++)
    {
        scanf("%d%d%d",&c[i].r,&c[i].x,&c[i].y);
        e[tote++] = event(1,c[i].x-c[i].r,i);
        e[tote++] = event(-1,c[i].x+c[i].r,i);
    }
    sort(e,e+tote);
    for (int i = 0;i < tote;i++)
    {
        xline = e[i].x;
        int id = e[i].id;
        if (e[i].typ == -1)
        {
            tree.erase(node(-1,id));
            tree.erase(node(1,id));
        }
        else
        {
            set<node>::iterator now,nxt;
            nxt = now = tree.insert(node(1,id)).first;
            nxt++;
            if (now == tree.begin() || nxt == tree.end())
                addedge(0,id);
            else
            {
                --now;
                if (now->typ == -1)
                    addedge(now->id,id);
                else
                    addedge(fa[now->id],id);
            }
            if (e[i].typ == 1)
                tree.insert(node(-1,id));
            else
                tree.erase(node(1,id));
        }
    }
    //output(0,0);
    for (int i = 0;i < q;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int mindep = min(dep[u],dep[v]);
        int res = 0;
        while (dep[u] != mindep)
        {
            res += (u > n);
            u = fa[u];
        }
        while (dep[v] != mindep)
        {
            res += (v > n);
            v = fa[v];
        }
        while (u != v)
        {
            res += (u > n)+(v > n);
            u = fa[u];
            v = fa[v];
        }
        printf("%d\n",res);
    }
    return 0;
}
