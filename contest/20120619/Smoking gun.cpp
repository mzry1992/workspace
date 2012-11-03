#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

const double eps = 1e-8;
struct info
{
    int x,y;
};
info a[111];
int n,m;

char name[111][30],sa[30],sb[30],sc[30];
map<string,int> nameid;
int ida,idb,idc;

double dis[111][111],d[111],dd[111][111];

bool fire[111],visit[111];
int intime[111];

int head[111];
struct edges
{
    int to,next;
    double dis;
}edge[2000];
int L;

double sqr(int a)
{
    return (double)a*(double)a;
}

void init()
{
    for (int i = 0;i < n;i++)
    {
        intime[i] = 0;
        head[i] = -1;
        fire[i] = visit[i] = false;
        d[i] = 1e100;
        for (int j = 0;j < n;j++)
            dd[i][j] = 1e100;
    }
    L = 0;
}

void addedge(int u,int v,double dis)
{
    dd[u][v] = min(dd[u][v],dis);
    //printf("addedge : %d %d %.6f\n",u,v,dis);
    edge[L].to = v;
    edge[L].dis = dis;
    edge[L].next = head[u];
    head[u] = L++;
}

bool spfa(int s)
{
    queue<int> Q;
    Q.push(s);
    visit[s] = true;
    d[s] = 0;
    intime[s]++;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        visit[now] = false;
        if (intime[now] > n)    return false;
        for (int i = head[now];i != -1;i = edge[i].next)
            if (d[edge[i].to] > d[now]+edge[i].dis)
            {
                d[edge[i].to] = d[now]+edge[i].dis;
                if (visit[edge[i].to] == false)
                {
                    Q.push(edge[i].to);
                    visit[edge[i].to] = true;
                    intime[edge[i].to]++;
                }
            }
    }
    return true;
}

pair<double,int> res[111];
int tot;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n,&m);
        nameid.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%s%d%d",name[i],&a[i].x,&a[i].y);
            nameid[name[i]] = i;
        }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                dis[i][j] = sqrt(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y));
        n++;
        init();
        for (int i = 0;i < m;i++)
        {
            scanf("%s heard %s firing before %s",sa,sb,sc);
            ida = nameid[sa];
            idb = nameid[sb];
            idc = nameid[sc];
            fire[idb] = fire[idc] = true;
            addedge(idc,idb,-(dis[ida][idb]-dis[ida][idc]));
        }
        for (int i = 0;i < n-1;i++)
            addedge(n-1,i,0);
        if (spfa(n-1) == false)
            puts("IMPOSSIBLE");
        else
        {
            for (int k = 0;k < n;k++)
                if (fire[k] == true)
                    for (int i = 0;i < n;i++)
                        if (fire[i] == true)
                            for (int j = 0;j < n;j++)
                                if (fire[j] == true)
                                    if (dd[i][j] > dd[i][k]+dd[k][j])
                                        dd[i][j] = dd[i][k]+dd[k][j];
            bool check = true;
            for (int i = 0;i < n;i++)
                if (fire[i])
                    for (int j = i+1;j < n;j++)
                        if (fire[j])
                            if (dd[i][j] >= 0 && dd[j][i] >= 0)
                                check = false;
            if (check == false)
                puts("UNKNOWN");
            else
            {
                tot = 0;
                for (int i = 0;i < n;i++)
                    if (fire[i] == true)
                        res[tot++] = make_pair(d[i],i);
                sort(res,res+tot);
                for (int i = 0;i+1 < tot;i++)
                    printf("%s ",name[res[i].second]);
                printf("%s\n",name[res[tot-1].second]);
            }
        }
    }
    return 0;
}
