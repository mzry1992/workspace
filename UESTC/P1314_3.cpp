#include <iostream>
using namespace std;

const int maxv = 1<<30;
int n,m,q,i;
int u,v,d,cap;
int ans;
int price[1000];
struct node {
     int now, gas, cost;
     int fat,lson,rson;
}heap[4000000];
int totheap;
struct graphtype
{
       int next;
       int tail;
       int tonode;
       int edge;
}graph[30000];
int totg;

void swap(int s,int t)
{
     node temp;
     temp = heap[s]; heap[s] = heap[t]; heap[t] = temp;
}

void sift_up(int i)
{
     int done;
     done = false;
     if (i != 1)
        while ((done == false) && (i != 1))
        {
              if (heap[i].cost < heap[heap[i].fat].cost) swap(i,heap[i].fat);
              else
                  done == true;
              i = heap[i].fat;
        }
}

void sift_down(int i)
{
     int done,temp;
     done = false;
     if (heap[i].lson != -1)
        while ((done == false) && (heap[i].lson != -1))
        {
              temp = i;
              i = heap[i].lson;
              if ((heap[temp].rson <= n) and (heap[heap[temp].rson].cost < heap[i].cost ))  i = heap[temp].rson;
              if (heap[heap[i].fat].cost > heap[i].cost ) swap(i,heap[i].fat);
              else
                  done == true;
        }
}

void push(int tnow,int tgas,int tcost)
{
     totheap++;
     heap[totheap].cost = tcost;
     heap[totheap].gas = tgas;
     heap[totheap].now = tnow;
     heap[totheap].fat = totheap-1;
     heap[totheap].lson = heap[totheap].rson = -1;
     sift_up(totheap);
}

void dele(int i)
{
     node x,y;
     x = heap[i];
     y = heap[totheap];
     totheap--;
     if (i <= totheap)
     {
           heap[i] = y;
           if (y.cost <= x.cost) sift_up(i);
           else
               sift_down(i);
     }
}

node gettop()
{
     node x;
     x = heap[1];
     dele(1);
     return x;
}

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
    for (i = 0;i < n;i++)
    for (j = 0;j <= cap;j++)
        dp[i][j] = maxv;
    dp[u][0] = 0;
    totheap = 0;
    push(u,0,0);
    while (totheap > 0)
    {
          node now = gettop();
          tnow = now.now;
          tgas = now.gas;
          tcost = now.cost;
          if (tcost != dp[tnow][tgas]) continue;
          if (tnow == v) break;
          if (tgas+1 <= cap)
          if (dp[tnow][tgas+1] > dp[tnow][tgas]+price[tnow])
          {
                             dp[tnow][tgas+1] = dp[tnow][tgas]+price[tnow];
                             push(tnow,tgas+1,dp[tnow][tgas+1]);
          }
          for (i = graph[tnow].next;i != -1;i = graph[i].next)
          {
              j = graph[i].tonode;
              k = graph[i].edge;
              if (tgas >= k)
              if (dp[j][tgas-k] > dp[tnow][tgas])
              {
                           dp[j][tgas-k] = dp[tnow][tgas];
                           push(j,tgas-k,dp[j][tgas-k]);
              }
          }
    }
    return dp[v][0];     
}

int main()
{
    /*scanf("%d %d",&n,&m);
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
    }*/
    scanf("%d",&q);
    for (i = 1;i <= q;i++)
    {
        scanf("%d",&v);
        push(0,0,v);
        /*ans = BFS(cap,u,v);
        if (ans == maxv)
           printf("impossible\n");
        else
            printf("%d\n",ans);*/
    }
    for (i = 1;i <= q;i++)
    {
        node now;
        now = gettop();
        int tnow,tgas,tcost;
        tnow = now.now;
        tgas = now.gas;
        tcost = now.cost;
        printf("%d %d %d\n",tnow,tgas,tcost);
    }        
    system("pause");

    return 0;
}
