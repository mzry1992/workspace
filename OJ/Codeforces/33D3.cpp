#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<set>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct Circle
{
    int x,y,r;
} cirs[50010];
struct Node
{
    int id;
    int type;
    Node() {}
    Node(int _id ,int _tp)
    {
        id = _id ;
        type = _tp;
    }
};
struct Event
{
    int x,id,type;
} events[50010*2];
bool operator<(const Event &a ,const Event &b)
{
    return a.x < b.x;
}
int xline;

inline double getY(int x,int y ,int r ,int type)
{
    int dx = x-xline;
    return y +type*sqrt((double)r*r - (double)dx*dx);
}
bool operator<(const Node &a,const Node &b)  // type = 1 up //type = -1 down
{
    double ya =getY(cirs[a.id].x , cirs[a.id].y,cirs[a.id].r,a.type) ,
               yb = getY(cirs[b.id].x , cirs[b.id].y,cirs[b.id].r , b.type);
    if(fabs(ya - yb) < 1e-15) return a.type < b.type;
    else return ya < yb ;
}

set<Node> tree;
int dep[50010];
struct edges
{
    int to,next;
} edge[100000];
const int DEG=20;
struct trees
{

    int fa[DEG];
    int head,deg;
} TREE[50000];
int L,fa[100000];
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=TREE[u].head;
    TREE[u].head=L++;
    fa[v]=u;
}
struct states
{
    int u,fu,deg;
};


void BFS(int s)
{
    queue<states> que;
    states st;
    st.deg=0;
    st.fu=st.u=s;
    que.push(st);
    while(!que.empty())
    {
        states st=que.front();
        que.pop();
        TREE[st.u].deg = st.deg;
        TREE[st.u].fa[0] = st.fu;
        for (int i=1; i<DEG; i++)
            TREE[st.u].fa[i]=s;
        for (int tmp=st.fu,num=1; TREE[tmp].deg; tmp=TREE[st.u].fa[num++])
            TREE[st.u].fa[num]=TREE[tmp].fa[num-1];
        for(int i = TREE[st.u].head ; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            states nst;
            nst.u=v;
            nst.fu=st.u;
            nst.deg=st.deg+1;
            que.push(nst);
        }
    }
}
int LCA(int x, int y)
{
    if(TREE[x].deg > TREE[y].deg) swap(x,y);
    int hx=TREE[x].deg,hy=TREE[y].deg;
    int tx=x,ty=y;
    for (int det=hy-hx,i=0; det; det>>=1,i++)
        if (det&1) ty=TREE[ty].fa[i];
    if(tx == ty) return tx;
    for (int i=DEG-1; i>=0; i--)
    {
        if(TREE[tx].fa[i] == TREE[ty].fa[i])
            continue;
        tx = TREE[tx].fa[i];
        ty = TREE[ty].fa[i];
    }
    return TREE[tx].fa[0];
}
int n;
int sum[50000];
void dfs(int u,int now)
{
    sum[u]=now+(u>n);
    for (int i=TREE[u].head;i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v,sum[u]);
    }
}
int main()
{
    L=0;
    int m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<=n+m;i++)
        TREE[i].head=-1;
    tree.clear();
    int eL = 0;
    for(int i = 1; i <= n ; i++)
    {
        scanf("%d%d",&cirs[i].x,&cirs[i].y);
        cirs[i].r=0;
        dep[i] = 0;
        events[eL].id = i;
        events[eL].type = 0;
        events[eL].x = cirs[i].x -cirs[i].r;
        eL++;
    }
    for(int i = n+1; i <= n+m ; i++)
    {
        scanf("%d%d%d",&cirs[i].r,&cirs[i].x,&cirs[i].y);
        dep[i] = 0;
        events[eL].id = i;
        events[eL].type = 1;
        events[eL].x = cirs[i].x -cirs[i].r;
        eL++;
        events[eL].id = i;
        events[eL].type = -1;
        events[eL].x = cirs[i].x +cirs[i].r;
        eL++;
    }
    sort(events, events + eL);
    for(int i = 0 ; i < eL; i++)
    {
        xline = events[i].x;
        int id = events[i].id;
        if(events[i].type == -1)
        {
            tree.erase(Node(id,1));
            tree.erase(Node(id,-1));
            continue;
        }
        set<Node>::iterator itu = tree.insert(Node(id,1)).first;
        set<Node>::iterator tmp = itu , nxt;
        nxt = ++tmp;
        if(itu == tree.begin() || nxt == tree.end())
        {
            dep[id] = 1;
            add_edge(0,id);
        }
        else
        {
            --itu;
            if(itu->id == nxt->id)
            {
                dep[id] = dep[itu->id]+1;
                add_edge(itu->id,id);
            }
            else
            {
                if (dep[itu->id]>dep[nxt->id])
                {
                    dep[id]=dep[itu->id];
                    add_edge(fa[itu->id],id);
                }
                else
                {
                    dep[id]=dep[nxt->id];
                    add_edge(fa[nxt->id],id);
                }
            }
        }
        if (events[i].type)
            tree.insert(Node(id , -1));
        else
            tree.erase(Node(id,1));
    }
    BFS(0);
    dfs(0,0);
    for (int i=0; i<k; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",sum[u]+sum[v]-2*sum[LCA(u,v)]);
    }
    return 0;
}
