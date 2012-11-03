#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=2+40+20;
const int MAXM=40*20+20+40*20+40;
const double inf=1e100;
int L,N;
struct Edge
{
    int to,next,flow;
    double cost;
    int flag;
} edge[MAXM<<4];
struct Vertex
{
    double dis;
    int pre,head;
    bool visit;
} vertex[MAXN*10];
void init(int n)
{
    L=0;
    N=n;
    for (int i=0; i<N; i++)
        vertex[i].head=-1;
}
void add_edge(int u,int v,int flow,double cost,int flag)
{
    //printf("%d %d %d %f\n",u,v,flow,cost);
    edge[L].to=v;
    edge[L].flow=flow;
    edge[L].flag=flag;
    edge[L].cost=cost;
    edge[L].next=vertex[u].head;
    vertex[u].head=L++;
    edge[L].to=u;
    edge[L].flow=0;
    edge[L].flag=flag;
    edge[L].cost=-cost;
    edge[L].next=vertex[v].head;
    vertex[v].head=L++;
}
double calc(int x)
{
    return 4-(double)3*(100-x)*(100-x)/1600;
}
double  DEL[101];
inline double del(int x)
{
    return DEL[x];
}
double del2(int x)
{
    return calc(x+1)-calc(x);
}
double dist(int i)
{
    if (!edge[i].flag)
        return edge[i].cost;
    else if (edge[i].cost>0)
        return -del(edge[i].cost)*edge[i].flag;
    else
        return del(-edge[i].cost-1)*edge[i].flag;
}
bool check(int i)
{
    if (!edge[i].flag)
        return edge[i].flow;
    else if (edge[i].cost>0)
        return edge[i].cost<100;
    else
        return -edge[i].cost>60;
}
bool spfa(int s,int t)
{
    queue<int> q;
    for (int i=0; i<N; i++)
    {
        vertex[i].dis=inf;
        vertex[i].pre=-1;
        vertex[i].visit=0;
    }
    vertex[s].dis=0;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        vertex[u].visit=0;
        for (int i=vertex[u].head; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if (check(i) && vertex[v].dis>vertex[u].dis+dist(i))
            {
                vertex[v].dis=vertex[u].dis+dist(i);
                vertex[v].pre=i;
                if (!vertex[v].visit)
                {
                    vertex[v].visit=1;
                    q.push(v);
                }
            }
        }
    }
    return vertex[t].pre!=-1;
}
double mcmf(int s,int t)
{
    double ret=0;
    while (spfa(s,t))
    {
        int flow=10000;
        for (int i=vertex[t].pre; i!=-1; i=vertex[edge[i^1].to].pre)
        {
            //puts("---------");
            int tmp=edge[i^1].to;
            //printf("%d %d\n",i,edge[i^1].to);
            if (!edge[i].flag)
                flow=min(flow,edge[i].flow);
            else
                flow=1;
            //printf("%d %d\n",i,edge[i^1].to);
            //puts("----------");
            if (edge[i^1].to==s)
                break;
        }
        for (int i=vertex[t].pre; i!=-1; i=vertex[edge[i^1].to].pre)
        {
            if (edge[i].flag)
            {
                if (edge[i].cost>0)
                    ret+=dist(i);
                edge[i].cost++;
                edge[i^1].cost--;
                continue;
            }
            edge[i].flow-=flow;
            edge[i^1].flow+=flow;
            ret+=edge[i].cost*flow;
            if (edge[i^1].to==s)
                break;
        }
    }
    return ret;
}
int a[400];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    //n = 40,k = m = 20;
    for (int i=60; i<100; i++)
        DEL[i]=del2(i);
    int n,k,m;
    while (true)
    {
        scanf("%d%d%d",&n,&k,&m);
        if (n == 0 && k == 0 && m == 0) break;
        init(n+m+2);
        int w=0;
        for (int i=0; i<m; i++)
        {
            scanf("%d",&a[i]);
            w+=a[i];
        }
        int sum=0;
        double tot=0;
        for (int i=0; i<m; i++)
        {
            int x;
            scanf("%d",&x);
            if (x<60)
            {
                add_edge(n+i,n+m+1,60-x,-10000,0);
                sum+=60-x;
            }
            x=max(60,x);
            tot+=a[i]*(4-(double)3*(100-x)*(100-x)/1600);
            add_edge(n+i,n+m+1,0,x,a[i]);
        }
        for (int i=0; i<n; i++)
            add_edge(n+m,i,k,0,0);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
            {
                int x;
                scanf("%d",&x);
                if (x)
                    add_edge(i,n+j,k,0,0);
            }
        if (sum>k*n)
        {
            puts("0.000000");
            continue;
        }
        double ret=mcmf(n+m,n+m+1);
        if (-ret<sum*10000)
            puts("0.000000");
        else
            printf("%.6f\n",(-ret-sum*10000+tot)/w);
    }
    return 0;
}
