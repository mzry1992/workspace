#include <iostream>
#include <queue>
using namespace std;

typedef bool[60][60] sta;
const int maxv = 1<<30;
int n,m,q,i;
int u,v,d,cap;
int ans;
int price[1000];
struct node {
     int now, gas, cost;
     node(int no, int ga, int co): now(no), gas(ga), cost(co) { };
     bool operator < (const node &temp) const 
     {
          return cost > temp.cost;
     }
};
int totq;
struct graphtype
{
       int next;
       int tail;
       int tonode;
       int edge;
}graph[30000];
int totg;

void addroad(int u,int v,int d)
{
     int now;
     totg++;
     graph[totg].next = -1;
     graph[totg].tonode = v;
     graph[totg].edge = d;
     now = graph[u].tail;
     if (now == -1)
        graph[u].next = graph[u].tail = totg;
     else
     {
         graph[u].tail = totg;
         graph[now].next = totg;
     }
}

int BFS(int cap,int u,int v)
{
    int i,j,k;
    int tnow,tgas,tcost;
    int dp[1000][100];
    priority_queue<node> Q;
    for (i = 0;i < n;i++)
    for (j = 0;j <= cap;j++)
        dp[i][j] = maxv;
    dp[u][0] = 0;
    Q.push(node(u,0,0));
    while (!Q.empty())
    {
          node now = Q.top();
          Q.pop();
          tnow = now.now;
          tgas = now.gas;
          tcost = now.cost;
          if (tcost != dp[tnow][tgas]) continue;
          if (tnow == v) break;
          if (tgas+1 <= cap)
          if (dp[tnow][tgas+1] > dp[tnow][tgas]+price[tnow])
          {
                             dp[tnow][tgas+1] = dp[tnow][tgas]+price[tnow];
                             Q.push(node(tnow,tgas+1,dp[tnow][tgas+1]));
          }
          for (i = graph[tnow].next;i != -1;i = graph[i].next)
          {
              j = graph[i].tonode;
              k = graph[i].edge;
              if (tgas >= k)
              if (dp[j][tgas-k] > dp[tnow][tgas])
              {
                           dp[j][tgas-k] = dp[tnow][tgas];
                           Q.push(node(j,tgas-k,dp[j][tgas-k]));
              }
          }
    }
    return dp[v][0];     
}

int main()
{
    scanf("%d %d",&n,&m);
    totg = -1;
    for (i = 0;i < n;i++)
    {
        scanf("%d",&price[i]);
        totg++;
        graph[totg].next = -1;
        graph[totg].tail = -1;
    }
    for (i = 1;i <= m;i++)
    {
        scanf("%d %d %d",&u,&v,&d);
        addroad(u,v,d);
        addroad(v,u,d);
    }
    scanf("%d",&q);
    for (i = 1;i <= q;i++)
    {
        scanf("%d %d %d",&cap,&u,&v);
        ans = BFS(cap,u,v);
        if (ans == maxv)
           printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
