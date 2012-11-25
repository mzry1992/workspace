#include<cstdio>
#include<cstring>
const int inf=0x3f3f3f3f;
struct edges
{
    int cap,to,next,flow;
} edge[5000*50*10];
struct nodes
{
    int head,label,pre,cur;
} node[50000];
int gap[50000],p[50000],x[50000],y[50000];
bool ma[50][50];
bool flag1[50],flag2[50];
int L,N;
void init(int n)
{
    L=0;
    N=n;
    for (int i=0; i<N; i++)
        node[i].head=-1;
}
int maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    gap[0]=N;
    int u,ans=0;
    for (int i=0; i<N; i++)
    {
        node[i].cur=node[i].head;
        node[i].label=0;
    }
    u=s;
    node[u].pre=-1;
    while (node[s].label<N)
    {
        if (u==t)
        {
            int min=inf;
            for (int i=node[u].pre; i!=-1; i=node[edge[i^1].to].pre)
                if (min>edge[i].cap-edge[i].flow)
                    min=edge[i].cap-edge[i].flow;
            for (int i=node[u].pre; i!=-1; i=node[edge[i^1].to].pre)
            {
                edge[i].flow+=min;
                edge[i^1].flow-=min;
            }
            u=s;
            ans+=min;
            continue;
        }
        bool flag=false;
        int v;
        for (int i=node[u].cur; i!=-1; i=edge[i].next)
        {
            v=edge[i].to;
            if (edge[i].cap-edge[i].flow && node[v].label+1==node[u].label)
            {
                flag=true;
                node[u].cur=node[v].pre=i;
                break;
            }
        }
        if (flag)
        {
            u=v;
            continue;
        }
        node[u].cur=node[u].head;
        int min=N;
        for (int i=node[u].head; i!=-1; i=edge[i].next)
            if (edge[i].cap-edge[i].flow && node[edge[i].to].label<min)
                min=node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label])
            return ans;
        node[u].label=min+1;
        gap[node[u].label]++;
        if (u!=s)
            u=edge[node[u].pre^1].to;
    }
    return ans;
}
void add_edge(int u,int v,int cap,int rcap)
{
    edge[L].to=v;
    edge[L].cap=cap;
    edge[L].flow=0;
    edge[L].next=node[u].head;
    node[u].head=L++;
    edge[L].cap=rcap;
    edge[L].flow=0;
    edge[L].to=u;
    edge[L].next=node[v].head;
    node[v].head=L++;
}
int check(int x,int n,int m)
{
    init(x*m*2+2*m+3);
    for (int i=0; i<m; i++)
        for (int j=0; j<=x; j++)
            add_edge(2*j*m+i*2,2*j*m+i*2+1,p[i],0);
    for (int i=0;i<m;i++)
        for (int j=1;j<=x;j++)
            add_edge(2*j*m-2*m+i*2,2*j*m+i*2,inf,0);
    for (int i=0;i<m;i++)
        for (int j=1;j<=x;j++)
            add_edge(2*j*m-2*m+i*2+1,2*j*m+i*2+1,inf,0);
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            if (ma[i][j])
                for (int k=1; k<=x; k++)
                    add_edge(2*k*m-2*m+i*2+1,2*k*m+j*2,inf,0);
    for (int i=0; i<m; i++)
        if (flag2[i])
            add_edge(2*x*m+i*2+1,2*x*m+2*m+1,inf,0);
    for (int i=0; i<m; i++)
        if (flag1[i])
            add_edge(2*x*m+2*m+2,i*2,inf,0);
    add_edge(2*x*m+2*m,2*x*m+2*m+2,n,0);
    //for (int i=0;i<2*x*m+2;i++)
    //   for (int j=node[i].head;j!=-1;j=edge[j].next)
    //        printf("%d %d\n",i,edge[j].to);
    int flow=maxflow(2*x*m+2*m,2*x*m+2*m+1);
    return flow==n;
}
int dis(int a,int b)
{
    return ((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main()
{
    int n,m,d,w;
    scanf("%d%d%d%d",&m,&n,&d,&w);
    for (int i=0; i<m; i++)
        scanf("%d%d%d",&x[i],&y[i],&p[i]);
    if (d>=w)
    {
        puts("1");
        return 0;
    }
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (dis(i,j)<=d*d)
                ma[i][j]=1;
            else
                ma[i][j]=0;
    for (int i=0; i<m; i++)
    {
        if (y[i]+d>=w)
            flag2[i]=1;
        if (y[i]<=d)
            flag1[i]=1;
    }
    if (!check(n+m,n,m))
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    int l=0,r=n+m;
    while (l<r)
    {
        int mid=l+r>>1;
        if (check(mid,n,m))
            r=mid;
        else
            l=mid+1;
    }
    printf("%d\n",l+2);
    return 0;
}
