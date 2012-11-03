#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Point
{
    int x,y;
};

Point c[1000],re[1000];
int n,m,q,u,v,r[1000],id[1000];
vector<int> E[1001];
int dis[1001][1001];
bool hascal[1001];

long long Sqr(int a)
{
    return (long long)a*(long long)a;
}

long long CalcDis(Point a,Point b)
{
    return Sqr(a.x-b.x)+Sqr(a.y-b.y);
}

queue<int> Q;
bool inq[1001];

void Gao(int s)
{
    hascal[s] = true;
    for (int i = 0;i < m;i++)
    {
        dis[s][i] = 19921005;
        inq[i] = false;
    }
    dis[s][s] = 0;
    inq[s] = true;
    Q.push(s);
    int now;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        inq[now] = false;
        for (int i = 0;i < E[now].size();i++)
            if (dis[s][E[now][i]] > dis[s][now]+1)
            {
                dis[s][E[now][i]] = dis[s][now]+1;
                if (inq[E[now][i]] == false)
                {
                    inq[E[now][i]] = true;
                    Q.push(E[now][i]);
                }
            }
    }
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&q) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&c[i].x,&c[i].y);
            id[i] = m;
        }
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&r[i],&re[i].x,&re[i].y);
            E[i].clear();
            hascal[i] = false;
        }
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < m;j++)
                if (i != j)
                {
                    if (r[i] > r[j])    continue;
                    if (CalcDis(re[i],re[j]) > Sqr(r[i]+r[j]))  continue;
                    if (E[i].size() == 0)
                        E[i].push_back(j); //i is in j
                    else if (r[E[i][0]] > r[j])
                        E[i][0] = j;
                }
            if (E[i].size() == 0)
                E[i].push_back(m);
        }
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
                if (CalcDis(c[i],re[j]) < Sqr(r[j]))
                {
                    if (id[i] == m)
                        id[i] = j;
                    else
                    {
                        if (r[id[i]] > r[j])
                        {
                            id[i] = j;
                        }
                    }
                }
        }
        m++;
        for (int i = 0;i < m;i++)
            for (int j = 0;j < E[i].size();j++)
                E[E[i][j]].push_back(i);
        for (int i = 0;i < q;i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            u = id[u];
            v = id[v];
            if (hascal[u] == false)
                Gao(u);
            printf("%d\n",dis[u][v]);
        }
    }
    return 0;
}
