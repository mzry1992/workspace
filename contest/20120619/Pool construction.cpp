#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXM = 30000;
const int MAXN = 6000;
const int inf = 0x3fffffff;
struct edges
{
    int to,next,cap,flow;
} edge[MAXM];
struct nodes
{
    int head,label,pre,cur;
} node[MAXN];
int L,N,K;
int gap[MAXN];

void init(int n)
{
    N = n;
    L = 0;
    for (int i = 0; i < N; i++)
        node[i].head = -1;
}

void add_edge(int x,int y,int z,int w)
{
    //printf("%d %d %d\n",x,y,z);
    edge[L].cap=z;
    edge[L].flow=0;
    edge[L].to=y;
    edge[L].next=node[x].head;
    node[x].head=L++;
    edge[L].cap=w;
    edge[L].flow=0;
    edge[L].to=x;
    edge[L].next=node[y].head;
    node[y].head=L++;
}

int maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    gap[0] = N;
    int u,ans = 0;
    for (int i = 0; i < N; i++)
    {
        node[i].cur = node[i].head;
        node[i].label = 0;
    }
    u = s;
    node[u].pre = -1;
    while (node[s].label < N)
    {
        //cout << u << endl;
        if (u == t)
        {
            int minf = inf;
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
                minf = min(minf,edge[i].cap-edge[i].flow);
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
            {
                edge[i].flow += minf;
                edge[i^1].flow -= minf;
            }
            u = s;
            ans += minf;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = node[u].cur; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap-edge[i].flow && node[v].label+1 == node[u].label)
            {
                flag = true;
                node[u].cur = node[v].pre = i;
                break;
            }
        }
        if (flag)
        {
            u = v;
            continue;
        }
        node[u].cur = node[u].head;
        int minf = N;
        for (int i = node[u].head; i != -1; i = edge[i].next)
            if (edge[i].cap-edge[i].flow)
                minf = min(minf,node[edge[i].to].label);
        gap[node[u].label]--;
        if (!gap[node[u].label])    return ans;
        node[u].label = minf+1;
        gap[node[u].label]++;
        if (u != s) u = edge[node[u].pre^1].to;
    }
    return ans;
}

const int step[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
int w,h,d,f,b;
char mp[60][60];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d%d%d%d",&w,&h,&d,&f,&b);
        for (int i = 0; i < h; i++)
            scanf("%s",mp[i]);
        init(2+w*h);
        int tmp = w*h;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                if (i == 0 || i == h-1 || j == 0 || j == w-1)
                {
                    int aaa = 0;
                    if (mp[i][j] == '.')    aaa = f;
                    add_edge(tmp,i*w+j,aaa,0);
                    add_edge(i*w+j,tmp+1,inf,0);
                }
                else
                {
                    if (mp[i][j] == '#')
                    {
                        add_edge(tmp,i*w+j,0,0);
                        add_edge(i*w+j,tmp+1,d,0);
                    }
                    else
                    {
                        add_edge(tmp,i*w+j,f,0);
                        add_edge(i*w+j,tmp+1,0,0);
                    }
                }
                for (int k = 0; k < 2; k++)
                {
                    int tx = i+step[k][0];
                    int ty = j+step[k][1];
                    if (tx < 0 || tx >= h || ty < 0 || ty >= w) continue;
                    add_edge(i*w+j,tx*w+ty,b,b);
                }
            }
        printf("%d\n",maxflow(tmp,tmp+1));
    }
    return 0;
}
