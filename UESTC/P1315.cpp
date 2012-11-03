#include <iostream>
#include <string>
using namespace std;

const int MAXN = 50;
const int MAX = 10000;
int tcase,fcase;
int n,m,i,j,x,y;
char map[MAXN][MAXN];
int val[MAXN*MAXN];
struct graphtype
{
       int to;
       int next;
}zg[MAX],fg[MAX];
int totn,totsc,totg;
int visit[MAX],dfsnow,dfsorder[MAX],scin[MAX];
int value[MAX];
int ans,tans;
int f[MAX];

void addpath(int u,int v)
{
     zg[totn].next = zg[u].next;    zg[totn].to = v;    zg[u].next = totn;
     fg[totn].next = fg[v].next;    fg[totn].to = u;    fg[v].next = totn;
     totn++;
}

void find(int u)
{
     int i,v,t;
     visit[u] = true;
     t = 0;
     for (i = fg[u].next;i != -1;i = fg[i].next)
     {
         v = fg[i].to;
         if (visit[v] == false)    find(v);
         if (f[v] > t) t = f[v];
     }
     f[u] = t+value[u];
}

void DFS1(int u)
{
     int i;
     visit[u] = true;
     for (i = zg[u].next;i != -1;i = zg[i].next)
         if (visit[zg[i].to] == false)          DFS1(zg[i].to);
     dfsorder[dfsnow++] = u;   
}

void DFS2(int u)
{
     int i;
     visit[u] = true;
     scin[u] = totsc;
     for (i = fg[u].next;i != -1;i = fg[i].next)
         if (visit[fg[i].to] == false)          DFS2(fg[i].to);
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        memset(zg,-1,sizeof(zg));
        memset(fg,-1,sizeof(fg));
        scanf("%d %d",&n,&m);
        for (i = 0;i < n;i++)
            scanf("%s",&map[i]);
        totn = n*m;
        for (i = 0;i < n;i++)
        for (j = 0;j < m;j++)
        if (map[i][j] != '#')
        {
                      if (j+1 < m)
                      if (map[i][j+1] != '#')
                         addpath(i*m+j,i*m+j+1);
                      if (i+1 < n)
                      if (map[i+1][j] != '#')
                         addpath(i*m+j,(i+1)*m+j);
                      if (map[i][j] == '*')
                      {
                                    val[i*m+j] = 0;
                                    scanf("%d %d",&x,&y);
                                    if (map[x][y] != '#')
                                       addpath(i*m+j,x*m+y);
                      }
                      else
                          val[i*m+j] = map[i][j]-'0';
        }
        else
            val[i*m+j] = 0;
        memset(visit,false,sizeof(visit));
        dfsnow = 0;
        for (i = 0;i < n*m;i++)
        if (visit[i] == false) DFS1(i);
        memset(visit,false,sizeof(visit));
        totsc = 0;
        for (i = n*m-1;i >= 0;i--)
        if (visit[dfsorder[i]] == false)
        {
                               totsc++;
                               DFS2(dfsorder[i]);
        }
        memset(fg,-1,sizeof(fg));
        totg = totsc+1;
        for (i = 0;i < n*m;i++)
        for (j = zg[i].next;j != -1;j = zg[j].next)
        {
            int v = zg[j].to;
            if (scin[v] != scin[i])
            {
                        fg[totg].next = fg[scin[i]].next;
                        fg[totg].to = scin[v];
                        fg[scin[i]].next = totg;
                        totg++;
            }
        }
        for (i = 1;i <= totsc;i++)
        {
            value[i] = 0;
            for (j = 0;j < n*m;j++)
            if (scin[j] == i) value[i] += val[j];
        }
        memset(visit,false,sizeof(visit));
        memset(f,0,sizeof(f));
        find(scin[0]);
        printf("%d\n",f[scin[0]]);
    }
}
