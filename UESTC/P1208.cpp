#include <iostream>
using namespace std;

const int MAXN = 20000;
const int MAXM = 200000;
int n,m;
struct graph
{
       int next;
       int to;
}g[MAXN+2*MAXM];
int totg;
int visit[MAXN];
int low[MAXN];
int pre[MAXN];
int father[MAXN];
int key[MAXN];
int cnt,bcnt;
int bic[MAXN];
int bicnt;
int node[MAXN];
int path[MAXN];
int ans;
int s[MAXN][2];
int top;

int find(int u,int v)
{
    int i;
    for (i = g[u].next;i != -1;i = g[i].next)
        if (g[i].to == v)   return true;
    return false;
}

void addpath(int u,int v)
{
     if (find(u,v) == true)  return;
     totg++;
     g[totg].to = v;   g[totg].next = g[u].next;    g[u].next = totg;
}

void readin()
{
     int i,u,v;
     memset(g,-1,sizeof(g));
     totg = n;
     for (i = 1;i <= m;i++)
     {
         scanf("%d %d",&u,&v);
         addpath(u+1,v+1);
         addpath(v+1,u+1);
     }
}

void bridgeR(int now)
{
     int i,v;
     cnt++;
     pre[now] = low[now] = cnt;     
     visit[now] = true;
     for (i = g[now].next;i != -1;i = g[i].next)
     {
         v = g[i].to;
                      top++;
                      s[top][1] = now;
                      s[top][2] = v;
                      cout << "In" << endl;
                      for (int j = 1;j <= top;j++)
                          cout << s[j][1] << ' ' << s[j][2] << endl;
                      cout << "---------------" << endl;
         if (visit[v] == false)
         {
                      father[v] = now;
                      bridgeR(v);
         }
         if ((low[now] > low[v]) && (father[now] != v))       low[now] = low[v];
         if (low[v] > pre[now])     bcnt++;
         if (low[v] >= pre[now])    
         {
                    key[now] = true;
                    bicnt++;
                    while (!((s[top][1] == now) && (s[top][2] == v)) && (top > 0))
                          top--;
                    cout << "Out" << endl;
                    for (int j = 1;j <= top;j++)
                        cout << s[j][1] << ' ' << s[j][2] << endl;
                    cout << "-----------------" << endl;
                    
         }
     }
}

void DFS(int now)
{
     int i,v;
     bic[now] = bicnt;
     visit[now] = true;
     for (i = g[now].next;i != -1;i = g[i].next)
     {
         v = g[i].to;
         if (visit[v] == false)
            DFS(v);
     }
}

void work()
{
     int i,j,v;
     memset(visit,false,sizeof(visit));
     memset(pre,0,sizeof(pre));
     memset(low,0,sizeof(low));
     memset(key,false,sizeof(key));
     memset(bic,0,sizeof(bic));
     cnt = bcnt = bicnt = top = 0;
     for (i = 1;i <= n;i++)
     if (visit[i] == false)
     {
                  father[i] = 0;
                  bridgeR(i);
     }
     ans = 0;
     memset(node,0,sizeof(node));
     memset(path,0,sizeof(path));
     for (i = 1;i <= n;i++)
     {
         node[bic[i]]++;
         for (j = g[i].next;j != -1;j = g[j].next)
         {
             v = g[j].to;
             if (bic[v] == bic[i])
                path[bic[v]]++;
         }
     }
     for (i = 1;i <= bicnt;i++)
     {
         j = path[i]/2;
         if (node[i] < j)
            ans += j;
     }
}

void output()
{
     printf("%d %d\n",bcnt,ans);
}

int main()
{
    scanf("%d %d",&n,&m);
    while (!((n == 0) && (m == 0)))
    {
          readin();
          work();
          output();
          scanf("%d %d",&n,&m);
    }
    return 0;
}
