#include<cstdio>
#include<cstring>
const int DEG=20;
struct edges
{
    int to,next;
} edge[99998];
int head[50000];
int fa[50000][DEG],deg[50000];
int right[50000],left[50000];
int a[50000],b[100000];
int N,L,Lab;
int tree[400000];
void init(int n)
{
    L=Lab=0;
    N=n;
    for (int i=0; i<n; i++)
        memset(fa[i],0,sizeof(fa[i]));
    memset(head,-1,4*n);
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
void dfs(int u,int fu,int degr)
{
    deg[u]=degr;
    fa[u][0]=fu;
    left[u]=Lab++;
    int idx=u,num=1;
    while (deg[idx])
    {
        fa[u][num]=fa[idx][num-1];
        idx=fa[u][num++];
    }
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu) continue;
        dfs(v,u,degr+1);
    }
    right[u]=Lab++;
}
void swap(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
int LCA(int x, int y)
{
    if(deg[x] > deg[y]) swap(x,y);
    int hx=deg[x],hy=deg[y];
    int tx=x,ty=y;
    for (int det=hy-hx,ci=0; det; det>>=1,ci++)
        if (det&1) ty=fa[ty][ci];
    if(tx == ty) return tx;
    for (int ci=DEG-1; ci>=0; ci--)
    {
        if(fa[tx][ci] == fa[ty][ci])
            continue;
        tx = fa[tx][ci];
        ty = fa[ty][ci];
    }
    return fa[tx][0];
}
void build(int x,int l,int r)
{
    if (l==r)
    {
        tree[x]=b[l];
    }
    else
    {
        tree[x]=0;
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
    }
}
void update(int x,int l,int r,int s,int t,int v)
{
    if (s<=l && r<=t)
    {
        tree[x]+=v;
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(x*2,l,mid,s,t,v);
    if (t>mid)
        update(x*2+1,mid+1,r,s,t,v);
}
int read(int x,int l,int r,int p)
{
    if (l==r)
        return tree[x];
    else
    {
        int mid=l+r>>1;
        if (p>mid)
            return tree[x]+read(x*2+1,mid+1,r,p);
        else
            return tree[x]+read(x*2,l,mid,p);
    }
}
int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m;
    while (scanf("%d%*d%d",&n,&m)!=EOF)
    {
        for (int i=0; i<n; i++)
            a[i]=readint();
        init(n);
        for (int i=1; i<n; i++)
        {
            int x,y;
            x=readint()-1;
            y=readint()-1;
            add_edge(x,y);
            add_edge(y,x);
        }
        dfs(0,-1,0);
        memset(b,0,8*N);
        for (int i=0; i<n; i++)
            b[left[i]]=a[i];
        N<<=1;
        build(1,0,N-1);
        for (int i=0; i<m; i++)
        {
            char c;
            scanf(" %c",&c);
            if (c=='I')
            {
                int u,v,p;
                u=readint()-1;
                v=readint()-1;
                p=readint();
                int lca=LCA(u,v);
                update(1,0,N-1,left[lca],left[u],p);
                update(1,0,N-1,left[lca],left[v],p);
                update(1,0,N-1,left[lca],left[lca],-p);
            }
            else if (c=='D')
            {
                int u,v,p;
                u=readint()-1;
                v=readint()-1;
                p=readint();
                int lca=LCA(u,v);
                update(1,0,N-1,left[lca],left[u],-p);
                update(1,0,N-1,left[lca],left[v],-p);
                update(1,0,N-1,left[lca],left[lca],p);
            }
            else
            {
                int u;
                u=readint()-1;
                printf("%d\n",read(1,0,N-1,left[u])-read(1,0,N-1,right[u]));
            }
        }
    }
    return 0;
}

анвн  22:34:41
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int NSIZE = 50000;
const int DEG = 20;
struct trees
{

    int fa[DEG];
    int head,deg;
} tree[NSIZE];
struct edges
{
    int to , next;
} edge[NSIZE];
struct states
{
    int u,fu,deg;
};
int L;
void add_edge(int x, int y)
{
    edge[L].to = y;
    edge[L].next = tree[x].head;
    tree[x].head = L++;
}
int Root;
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
        tree[st.u].deg = st.deg;
        tree[st.u].fa[0] = st.fu;
        int tmp = st.fu, num = 1;
        while(tree[tmp].deg)
        {
            tree[st.u].fa[num] = tree[tmp].fa[num-1];
            tmp = tree[st.u].fa[num++];
        }
        for(int i = tree[st.u].head ; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (v == st.fu) continue;
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
    if(tree[x].deg > tree[y].deg) swap(x,y);
    int hx=tree[x].deg,hy=tree[y].deg;
    int tx=x,ty=y;
    for (int det=hy-hx,ci=0; det; det>>=1,ci++)
        if (det&1) ty=tree[ty].fa[ci];
    if(tx == ty) return tx;
    for (int ci=DEG-1; ci>=0; ci--)
    {
        if(tree[tx].fa[ci] == tree[ty].fa[ci])
            continue;
        tx = tree[tx].fa[ci];
        ty = tree[ty].fa[ci];
    }
    return tree[tx].fa[0];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        L = 0;
        for(int i = 0 ; i < n ; i++)
            tree[i].head = -1;
        for(int i = 0 ; i < n-1 ; i++)
        {
            int a,b;
            scanf("%d%d",&a ,&b);
            add_edge(a-1,b-1);
            add_edge(b-1,a-1);
        }
        Root=0;
        for (int i=0; i<n; i++)
            for (int j=0; j<DEG; j++)
                tree[i].fa[j]=Root;
        BFS(Root);
        int a,b;
        scanf("%d%d",&a,&b);
        int lca=LCA(a-1,b-1)+1;
        printf("%d\n",lca);
    }
    return 0;
}
