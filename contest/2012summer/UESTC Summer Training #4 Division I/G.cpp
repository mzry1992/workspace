#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct Edge
{
    int to,next,cost;
};

Edge edge[10000];
int head[1000],L;
int n,m,r,S,T;

void addedge(int u,int v,int c)
{
    edge[L].to = v;
    edge[L].next = head[u];
    edge[L].cost = c;
    head[u] = L++;
}

int a[1100],len;
map<int,int>::iterator it;

struct Trie
{
    map<int,int> next[21000];
    int fail[21000],end[21000];
    int L,root;

    int newnode()
    {
        next[L].clear();
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert()
    {
        int now = root,cost = 0;
        for (int i = 0; i < len; i++)
        {
            if (next[now].find(a[i]-1) == next[now].end())
                next[now][a[i]-1] = newnode();
            now = next[now][a[i]-1];
            cost += edge[a[i]-1].cost;
        }
        end[now] += cost;
    }
    void build()
    {
        queue<int> Q;
        for (it = next[root].begin(); it != next[root].end(); it++)
        {
            fail[it->second] = root;
            Q.push(it->second);
        }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            end[now] += end[fail[now]];
            for (it = next[now].begin(); it != next[now].end(); it++)
            {
                int ff = fail[now];
                while (ff != root && next[ff].find(it->first) == next[ff].end())
                    ff = fail[ff];
                if (next[ff].find(it->first) == next[ff].end())
                    fail[it->second] = root;
                else
                    fail[it->second] = next[ff][it->first];
                Q.push(it->second);
            }
        }
    }
    void debug()
    {
        for (int i = 0; i < L; i++)
        {
            printf("id = %2d, fail = %2d, end = %2d\n",i,fail[i],end[i]);
            printf("   ");
            for (it = next[i].begin(); it != next[i].end(); it++)
                printf("(%d,%d) ",it->first,it->second);
            printf("\n");
        }
    }
    int findnext(int now,int ch)
    {
        int ff = now;
        while (ff != root && next[ff].find(ch) == next[ff].end())
            ff = fail[ff];
        if (next[ff].find(ch) == next[ff].end())
            return root;
        else
            return next[ff][ch];
    }
};

Trie ac;
map<int,int> use[1100];
map<int,pair<int,int> > pre[1100];
map<int,int> dist[1100];
set<int> inq[1100];
int road[11000],tot;

void SPFA()
{
    queue<pair<int,int> > Q;
    pair<int,int> now;
    int ua,ub,cost,na,nb;

    dist[S][ac.root] = 0;
    inq[S].insert(ac.root);
    Q.push(make_pair(S,ac.root));
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        ua = now.first;
        ub = now.second;
        inq[ua].erase(ub);
        //printf("%d %d dist = %d\n",ua,ub,dist[ua][ub]);
        for (int i = head[ua]; i != -1; i = edge[i].next)
        {
            na = edge[i].to;
            nb = ac.findnext(ub,i);
            //printf("%d %d %d\n",i,edge[i].to,nb);
            //cout << "HI" << endl;
            cost = dist[ua][ub]+edge[i].cost+ac.end[nb];
            //printf("%d %d\n");
            if (dist[na].find(nb) == dist[na].end() ||
                dist[na][nb] > cost)
                {
                    pre[na][nb] = make_pair(ua,ub);
                    use[na][nb] = i;
                    dist[na][nb] = cost;
                    if (inq[na].find(nb) == inq[na].end())
                    {
                        inq[na].insert(nb);
                        Q.push(make_pair(na,nb));
                    }
                }
        }
    }
    int res = -1;
    ua = T;
    for (it = dist[T].begin();it != dist[T].end();it++)
        if (res == -1 || res > it->second)
        {
            res = it->second;
            ub = it->first;
        }
    printf("%d\n",res);
    if (res == -1)  return;
    tot = 0;
    while (ua != S)
    {
        road[tot++] = use[ua][ub];
        na = pre[ua][ub].first;
        nb = pre[ua][ub].second;
        ua = na;
        ub = nb;
    }
    printf("%d\n",tot);
    for (int i = tot-1;i >= 0;i--)
        printf("%d ",road[i]+1);
    printf("\n");
}

int main()
{
    scanf("%d%d%d%d%d",&n,&m,&r,&S,&T);
    S--;
    T--;
    for (int i = 0; i < n; i++)
        head[i] = -1;
    L = 0;
    for (int i = 0; i < m; i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        u--;
        v--;
        addedge(u,v,c);
    }
    ac.init();
    for (int i = 0; i < r; i++)
    {
        scanf("%d",&len);
        for (int j = 0; j < len; j++)
            scanf("%d",&a[j]);
        ac.insert();
    }
    ac.build();
    //ac.debug();
    SPFA();
    return 0;
}
