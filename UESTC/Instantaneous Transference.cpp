#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,val[42*42],SCval[42*42],totg,dfsnow,tim[42*42],SC[42*42];
char map[42][42];
struct garph
{
    int to,next;
}g[42*42*42],rg[42*42*42];
bool visit[42*42];

void addedge(int u,int v)
{
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
    rg[totg].to = u;
    rg[totg].next = rg[v].next;
    rg[v].next = totg;
    totg++;
}

void DFS1(int now)
{
    visit[now] = true;
    for (int i = g[now].next;i != -1;i = g[i].next)
        if (visit[g[i].to] == false)
            DFS1(g[i].to);
    tim[dfsnow] = now;
    dfsnow++;
}

void DFS2(int now)
{
    visit[now] = true;
    SC[now] = dfsnow;
    for (int i = rg[now].next;i != -1;i = rg[i].next)
        if (visit[rg[i].to] == false)
            DFS2(rg[i].to);
}

void CalcSC()
{
    memset(visit,false,sizeof(visit));
    dfsnow = 0;
    for (int i = 0;i < n*m;i++)
        if (visit[i] == false)
            DFS1(i);
    memset(visit,false,sizeof(visit));
    dfsnow = 0;
    for (int i = n*m-1;i >= 0;i--)
        if (visit[tim[i]] == false)
        {
            DFS2(tim[i]);
            dfsnow++;
        }
}

void BuildTree()
{
    for (int i = 0;i < dfsnow;i++)  rg[i].next = -1;
    totg = dfsnow;
    for (int i = 0;i < n*m;i++)
        for (int j = g[i].next;j != -1;j = g[j].next)
            if (SC[i] != SC[g[j].to])
            {
                rg[totg].to = g[j].to;
                rg[totg].next = i;
                rg[i].next = totg;
                totg++;
            }
    memset(SCval,0,sizeof(SCval));
    for (int i = 0;i < n*m;i++)
        SCval[SC[i]] += val[i];
}

int Calc(int now)
{
    visit[now] = true;
    int res = 0;
    for (int i = rg[now].next;i != -1;i = rg[i].next)
        if (visit[rg[i].to] == false)
        {
            int tmp = Calc(rg[i].to);
            if (res < tmp)  res = tmp;
        }
    return res+SCval[now];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)   scanf("%s",map[i]);
        totg = n*m;
        for (int i = 0;i < totg;i++)    g[i].next = rg[i].next = -1;
        memset(val,0,sizeof(val));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (map[i][j] != '#')
                {
                    if (i+1 < n)
                        if (map[i+1][j] != '#')
                            addedge(i*m+j,(i+1)*m+j);
                    if (j+1 < m)
                        if (map[i][j+1] != '#')
                            addedge(i*m+j,i*m+j+1);
                    if (map[i][j] == '*')
                    {
                        int u,v;
                        scanf("%d%d",&u,&v);
                        if (map[u][v] != '#')   addedge(i*m+j,u*m+v);
                    }
                    else    val[i*m+j] = map[i][j]-'0';
                }
        CalcSC();
        BuildTree();
        memset(visit,false,sizeof(visit));
        printf("%d\n",Calc(SC[0]));
    }
}
