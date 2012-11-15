#include <iostream>
using namespace std;

int n,m;
int map[300][300],c[300][300],b[300][300],pre[300],d[300];//b保存当前流量，c保存残量，map保存图，pre保存前驱边，d保存队列 
int ans;

bool find()//寻找增广路 
{
     int head,tail;
     int i,j,k;
     int visit[300];
     memset(visit,false,sizeof(visit));
     visit[1] = true;
     head = tail = 1;
     d[1] = 1;
     pre[1] = 1;
     while (head <= tail)//BFS
     {
           for (i = 2;i <= n;i++)
           if (visit[i] == false)
           if (c[d[head]][i] > 0)
           {
                             visit[i] = true;
                             pre[i] = d[head];
                             tail++;
                             d[tail] = i;
                             if (i == n)
                                return true;
           }
           head++;
     }
     return false;
}

void solve()
{
     int i,j,k;
     while (find() == true)//如果有增广路 
     {
           int min = 0x7fffffff;
           for (i = n;i != 1;i = pre[i])//找到增量 
           if (min > c[pre[i]][i])
              min = c[pre[i]][i];
           for (i = n;i != 1;i = pre[i])//沿增广路修改 
           {
               b[pre[i]][i] += min;//正向 
               b[i][pre[i]] = -b[pre[i]][i];//反向 
               c[pre[i]][i] = map[pre[i]][i]-b[pre[i]][i];//正向 
               c[i][pre[i]] = b[pre[i]][i];//反向 
           }
     }
     ans = 0;
     for (i = 1;i < n;i++)
     if (map[i][n] != 0)
        ans += b[i][n];
}

int main()
{
    int i,j,ta,tb,tc;
    while (scanf("%d%d",&m,&n) == 2)
    {
          memset(c,0,sizeof(c));
          memset(b,0,sizeof(b));
          memset(map,0,sizeof(map));
          for (i = 1;i <= m;i++)
          {
              scanf("%d%d%d",&ta,&tb,&tc);
              map[ta][tb] += tc;
              c[ta][tb] = map[ta][tb];
          }
          solve();
          printf("%d\n",ans);
    }
    return 0;   
}
