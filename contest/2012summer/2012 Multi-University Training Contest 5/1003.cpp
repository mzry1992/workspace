#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y,tim,val;
    bool operator < (const Point& b)const
    {
        if (x*b.y-y*b.x == 0)
            return x*x+y*y < b.x*b.x+b.y*b.y;
        return x*b.y-y*b.x < 0;
    }
    int operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
};

Point p[200];
int dp[201][40001];
int n,m;

int main()
{
    int cas = 1;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].tim,&p[i].val);
        sort(p,p+n);
        memset(dp,0,sizeof(dp));
        int pre = 0,cnt = 0;
        for (int i = 1;i <= n;i++)
            if (i == n || p[i-1]*p[i] != 0)
            {
                cnt++;
                for (int j = 0;j <= m;j++)
                    dp[cnt][j] = dp[cnt-1][j];

                int sumt,sumv;
                sumt = sumv = 0;
                for (int j = pre;j < i;j++)
                {
                    sumt += p[j].tim;
                    sumv += p[j].val;
                    for (int k = m;k >= sumt;k--)
                        dp[cnt][k] = max(dp[cnt][k],dp[cnt-1][k-sumt]+sumv);
                }
                pre = i;
            }
        printf("Case %d: %d\n",cas++,dp[cnt][m]);
    }
	return 0;
}
