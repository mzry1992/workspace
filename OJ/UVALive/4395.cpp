#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

struct circle
{
    int x,y,r,v;
};

struct event
{
    int typ,x,id;
    event() {}
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

struct Edge
{
    int to,next;
};
circle c[50001];

inline double getY(int x,int y ,int r ,int type)
{
    int dx = x-xline;
    return y +type*sqrt((double)r*r - (double)dx*dx);
}

struct node
{
    int typ,id;
    node() {}
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

int n,k;
event e[100002];
set<node> tree;
Edge edge[50001];
int head[50001],fa[50001],dep[50001],L,tote;

void init(int n)
{
    L = 0;
    for (int i = 0; i < n; i++)
        head[i] = fa[i] = -1;
    dep[0] = tote = 0;
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
    fa[v] = u;
    dep[v] = dep[u]+1;
}

void build()
{
    sort(e,e+tote);
    for (int i = 0; i < tote; i++)
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
}

int res,f[50001][101][2];
const int inf = 1111111111;

void Gao(int now)
{
    for (int i = 0; i <= k; i++)
    {
        f[now][i][0] = inf;
        f[now][i][1] = -inf;
    }
    f[now][0][0] = f[now][0][1] = c[now].v;
    for (int i = head[now]; i != -1; i = edge[i].next)
    {
        int to = edge[i].to;
        Gao(to);
        for (int j = 0; j < k && f[to][j][0] != inf; j++)
        {
            f[now][j+1][0] = min(f[now][j+1][0],f[to][j][0]);
            f[now][j+1][1] = max(f[now][j+1][1],f[to][j][1]);
        }
    }
    int ed = k,op = 0;
    if (now == 0)
    {
        op = 1;
        ed = k-1;
    }
    for (; f[now][ed][0] == inf; ed--);
    int curmin = f[now][op][0];
    int a = ed;
    int b = min(ed,k-ed);
    for (int i = op; i <= b; i++)
        curmin = min(curmin,f[now][i][0]);
    for (; a >= op; a--)
    {
        curmin = min(curmin,f[now][b][0]);
        res = max(res,abs(f[now][a][1]-curmin));
        if (b < ed) b++;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&k);
        init(n+1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d",&c[i].x,&c[i].y,&c[i].r,&c[i].v);
            e[tote++] = event(1,c[i].x-c[i].r,i);
            e[tote++] = event(-1,c[i].x+c[i].r,i);
        }
        build();
        res = 0;
        Gao(0);
        printf("Case %d: %d\n",ft,res);
    }
    return 0;
}
