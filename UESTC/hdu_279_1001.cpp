#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n,root;
struct graph
{
       int to,wei,next;
}g[4000];
bool visit[2000];
int totg,ans;

void add(int ta,int tb,int tw)
{
     totg++;
     g[totg].to = tb;      g[totg].wei = tw;    g[totg].next = g[ta].next;
     g[ta].next = totg;
}

int dp(int now)
{
    int res,i,tdp;
    bool flag;
    visit[now] = true;
    res = 0;
    flag = false;
    for (i = g[now].next;i != -1;i = g[i].next)
    {
        if (visit[g[i].to] == false)
        {
            tdp = dp(g[i].to);
            if (tdp > g[i].wei)
               tdp = g[i].wei;
            res += tdp;
            flag = true;
        }
    }
    if (flag == false)  res = 19921005;
    return res;
}

int main()
{
    int i,j,ta,tb,tw;
    while (true)
    {
          scanf("%d%d",&n,&root);
          if ((n == 0) && (root) == 0)  break;
          for (i = 1;i <= n;i++)
          {
              visit[i] = false;
              g[i].next = -1;
          }
          totg = n;
          for (i = 1;i <= n-1;i++)
          {
              scanf("%d%d%d",&ta,&tb,&tw);
              add(ta,tb,tw);
              add(tb,ta,tw);
          }
          ans = dp(root);
          if (ans == 19921005)
             ans = 0;
          printf("%d\n",ans);
    }
    return 0;
}
