#include <iostream>
using namespace std;

int n,m;
int map[200][200],b[200][200],c[200][200],pre[200],d[200],pig[2000];
int ans;

bool find()
{
     int i,j,k;
     bool visit[2000];
     int head,tail;
     head = tail = 1;
     d[head] = pre[1] = 1;
     memset(visit,false,sizeof(visit));
     visit[1] = true;
     while (head <= tail)
     {
           for (i = 2;i <= 1+n+1;i++)
           if (c[d[head]][i] > 0)
           if (visit[i] == false)
           {
                             visit[i] = true;
                             tail++;
                             d[tail] = i;
                             pre[i] = d[head];
                             if (i == 1+n+1)
                                return true;
           }
           head++;
     }
     return false;
}

void solve()
{
     int i,j,k;
     while (find() == true)
     {
           int min = 0x7fffffff;
           for (i = 1+n+1;i != 1;i = pre[i])
           if (min > c[pre[i]][i])
              min = c[pre[i]][i];
           for (i = 1+n+1;i != 1;i = pre[i])
           {
               b[pre[i]][i] += min;
               b[i][pre[i]] = -b[pre[i]][i];
               c[pre[i]][i] = map[pre[i]][i]-b[pre[i]][i];
               c[i][pre[i]] = b[pre[i]][i];
           }
     }
     ans = 0;
     for (i = 2;i <= 1+n;i++)
         ans += b[1][i];
}

int main()
{
    int i,j,k,ta,tb;
    memset(map,0,sizeof(map));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d%d",&m,&n);
    for (i = 1;i <= m;i++)
    {
        pre[i] = 1;
        scanf("%d",&pig[i]);
    }
    for (i = 1;i <= n;i++)
    {
        scanf("%d",&ta);
        for (j = 1;j <= ta;j++)
        {
            scanf("%d",&tb);
            if (pre[tb] == 1)
               map[1][i+1] += pig[tb];
            else
                map[pre[tb]][i+1] = 0x7fffffff;
            pre[tb] = i+1;
        }
        scanf("%d",&tb);
        map[i+1][1+n+1] = tb;
    }
    for (i = 1;i <= 1+n+1;i++)
        for (j = 1;j <= 1+n+1;j++)
            c[i][j] = map[i][j];
    solve();
    printf("%d\n",ans);
    return 0;
}
