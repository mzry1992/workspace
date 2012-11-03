#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int dp[11000],pre[11000];
bool isfirst;

void output(int now)
{
    if (now == -1)  return;
    output(pre[now]);
    if (isfirst == false)   printf(" ");
    isfirst = false;
    printf("%d",now);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        int u,v;
        int s;
        scanf("%d",&u);
        s = v = u;
        for (int i = 1;i <= 10000;i++)
            dp[i] = 19921005;
        dp[s] = 0;
        pre[s] = -1;
        for (int i = 2;i <= n;i++)
        {
            scanf("%d",&v);
            if (dp[v] > dp[u]+1)
            {
                dp[v] = dp[u]+1;
                pre[v] = u;
            }
            u = v;
        }
        isfirst = true;
        output(v);
        puts("");
    }
}
