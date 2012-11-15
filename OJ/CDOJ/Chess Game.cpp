#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct map
{
    int typ,mov;
}m[200];
double dp[1000][200];

int getnewpos(int now)
{
    int cur = now;
    if (cur > n)
        cur = 2*n-cur;
    if (m[cur].typ == 0)    return cur;
    if (m[cur].typ == 3)    return cur;
    if (m[cur].typ == 1)
    {
        cur += m[cur].mov;
        if (cur > n)
            cur = 2*n-cur;
        return cur;
    }
    if (m[cur].typ == 2)
    {
        cur -= m[cur].mov;
        if (cur < 0)
            cur = -cur;
        return cur;
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(m,0,sizeof(m));
        int t;
        scanf("%d",&t);
        for (int i = 1;i <= t;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            m[a].typ = 1;
            m[a].mov = b;
        }
        scanf("%d",&t);
        for (int i = 1;i <= t;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            m[a].typ = 2;
            m[a].mov = b;
        }
        scanf("%d",&t);
        for (int i = 1;i <= t;i++)
        {
            int a,b;
            scanf("%d",&a);
            m[a].typ = 3;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1.0;
        double ans = 0;
        for (int i = 0;i <= 500;i++)
        {
            for (int j = 0;j < n;j++)
                dp[i+1][j] = 0.0;
            for (int j = 0;j <= n;j++)
            {
                if (m[j].typ == 0)
                {
                    for (int k = 1;k <= 6;k++)
                        dp[i+1][getnewpos(j+k)] += dp[i][j]/6;
                    continue;
                }
                if (m[j].typ == 3)
                if (i >= 1)
                {
                    for (int k = 1;k <= 6;k++)
                        dp[i+1][getnewpos(j+k)] += dp[i-1][j]/6;
                    continue;
                }
            }
            if (dp[i+1][n]*(i+1) > 0.001)
                ans += dp[i+1][n]*(i+1);
        }
        for (int i = 0;i <= 20;i++)
        {
            for (int j = 0;j <= n;j++)
                cout << dp[i][j] << ' ';
            cout << endl;
        }
        printf("%.2lf\n",ans);
    }
}
