#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-6;
const int MaxNode = 150;
const int MaxEdge = 550;
const int oo = 0x7f7f7f7f;

struct Edge
{
    int v;
    double C;
    Edge *next;
}e[MaxEdge];

struct Node
{
    Edge *e,*cur;
}adj[MaxNode];
int N,M,eCnt = 0;
int d[MaxNode],gap[MaxNode];

void addEdge(int u,int v,double C,bool bidirect)
{
    Edge &e1 = e[eCnt++],&e2 = e[eCnt++];
    e1.v = v; e1.next = adj[u].e; adj[u].e = &e1;
    e2.v = u; e2.next = adj[v].e; adj[v].e = &e2;
    e1.C = C; if (bidirect) e2.C = C;
}

inline Edge *otherE(Edge* p) { return &e[(p-e)^1];}

double sap(int u,double flow)
{
    if (u == N+1)   return flow;
    double ret = 0.0;
    int minDist = N+1;
    Edge *p;
    for (p = adj[u].cur;p;p = p->next)
    {
        if (p->C)
        {
            if (d[u] == d[p->v]+1)
            {
                adj[u].cur = p;
                ret = sap(p->v,min(p->C,flow));
                if (d[0] >= N+2)    return 0;
                if (fabs(ret) < EPS)    break;
            }
        }
    }
    if (!ret)
    {
        adj[u].cur = adj[u].e;
        for (p = adj[u].e;p;p = p->next)
            if (p->C && d[p->v] < minDist)
                minDist = d[p->v];
        gap[d[u]]--;
        if (!gap[d[u]])
            d[0] = N+2;
        d[u] = minDist+1;
        gap[d[u]]++;
        return 0;
    }
    else
    {
        Edge *q = otherE(p);
        p->C -= ret; q->C += ret;
        return ret;
    }
}

double maxFlow()
{
    double ret = 0;
    for (int i = 0;i <= N+1;i++)
    {
        adj[i].cur = adj[i].e;
        d[i] = gap[i] = 0;
    }
    gap[0] = N+2;
    while (d[0] < N+2)
        ret += sap(0,+oo);
    return ret;
}

int a[550],b[550];
double c[550];

int main()
{
    while (scanf("%d%d",&N,&M) != EOF)
    {
        double l,r,mid,flow;
        l = +oo;
        r = -oo;
        for (int i = 1;i <= M;i++)
        {
            scanf("%d%d%lf",&a[i],&b[i],&c[i]);
            if (c[i] < l)
                l = c[i];
            if (c[i] > r)
                r  = c[i];
        }
        while (l < r-EPS)
        {
            mid = (l+r)/2.0;
            eCnt = 0;
            for (int i = 0;i <= N+1;i++)
                adj[i].e = adj[i].cur = NULL;
            addEdge(0,1,+oo,true);
            addEdge(N,N+1,+oo,true);
            flow = 0.0;
            for (int i = 1;i <= M;i++)
            if (c[i] < mid)
                flow += c[i]-mid;
            else
                addEdge(a[i],b[i],c[i]-mid,true);
            flow += maxFlow();
            printf("%.2f\n",flow);
            if (flow > 0)
                r = mid;
            else
                l = mid;
        }
        printf("%.4lf\n",mid);
    }
}
