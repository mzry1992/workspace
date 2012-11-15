#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define Max 2139062143
using namespace std;

int head[5500],L,pre[5500],dis[5500],visit[5500];
struct Maps
{
    int to,flow,capacity,cost,next;
}Map[78000];

void add_edge(int x,int y,int f,int c)
{
    L++;
    Map[L].to = y;
    Map[L].capacity = f;
    Map[L].cost = c;
    Map[L].flow = 0;
    Map[L].next = head[x];
    head[x] = L;
    L++;
    Map[L].to = x;
    Map[L].capacity = 0;
    Map[L].cost = -c;
    Map[L].flow = 0;
    Map[L].next = head[y];
    head[y] = L;
}

void spfa(int s)
{
    int u,i;
    memset(dis,127,sizeof(dis));
    memset(visit,0,sizeof(visit));
    memset(pre,255,sizeof(pre));
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    visit[s] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        visit[u] = 0;
        for (i = head[u];i != -1;i = Map[i].next)
        if (dis[Map[i].to] > dis[u]+Map[i].cost && Map[i].capacity > Map[i].flow)
        {
            dis[Map[i].to] = dis[u]+Map[i].cost;
            pre[Map[i].to] = i;
            if (!visit[Map[i].to])
            {
                visit[Map[i].to] = 1;
                q.push(Map[i].to);
            }
        }
    }
}

int mcmf(int s,int t)
{
    int i,ans = 0,max;
    while (1)
    {
        spfa(s);
        if (pre[t] == -1)   return ans;
        max = Max;
        for (i = pre[t];i != -1;i = pre[Map[i^1].to])
            if (max > Map[i].capacity-Map[i].flow)
                max = Map[i].capacity-Map[i].flow;
        for (i = pre[t];i != -1;i = pre[Map[i^1].to])
        {
            Map[i].flow += max;
            Map[i^1].flow -= max;
            ans += Map[i].cost*max;
        }
    }
}

int n,k;
struct task
{
    int s,t,v;
}t[2100];
int ls[4200];
bool hash[250000];
int totls;
int ys[250000];

int main()
{
    while (scanf("%d%d",&n,&k) != EOF)
    {
        memset(hash,false,sizeof(hash));
        totls = 0;
        for (int i = 1;i <= n;i++)
        {
            int aa,bb,cc,dd,ee,ff,gg;
            scanf("%d:%d:%d %d:%d:%d %d",&aa,&bb,&cc,&dd,&ee,&ff,&gg);
            if (hash[aa*10000+bb*100+cc] == false)
            {
                totls++;
                ls[totls] = aa*10000+bb*100+cc;
                hash[aa*10000+bb*100+cc] = true;
            }
            if (hash[dd*10000+ee*100+ff] == false)
            {
                totls++;
                ls[totls] = dd*10000+ee*100+ff;
                hash[dd*10000+ee*100+ff] = true;
            }
            t[i].s = aa*10000+bb*100+cc;
            t[i].t = dd*10000+ee*100+ff;
            t[i].v = gg;
        }
        sort(ls+1,ls+1+totls);
        memset(ys,0,sizeof(ys));
        for (int i = 1;i <= totls;i++)
            ys[ls[i]] = i;
        for (int i = 1;i <= n;i++)
        {
            t[i].s = ys[t[i].s];
            t[i].t = ys[t[i].t];
            //cout << i << ' ' << t[i].s << ' ' << t[i].t << endl;
        }
        for (int i = 0;i <= totls+1;i++)
            head[i] = -1;
        for (int i = 0;i <= totls+1+n;i++)
            Map[i].next = -1;
        L = -1;
        add_edge(0,1,k,0);
        add_edge(totls,totls+1,k,0);
        for (int i = 1;i < totls;i++)
            add_edge(i,i+1,19930703,0);
        for (int i = 1;i <= n;i++)
            add_edge(t[i].s,t[i].t,1,-t[i].v);
        printf("%d\n",-mcmf(0,totls+1));
    }
}
