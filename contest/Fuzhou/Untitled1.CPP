#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
long long dp[2][1<<12];

void setbit(int& a,int pos,int val)
{
    if (val == 1)
        a = a|(1<<pos);
    else
        a = a&~(1<<pos);
}

queue<int> Q[2];
bool inq[2][1<<12];

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 || m == 0)   break;
        if (n < m)  swap(n,m);
        memset(inq,false,sizeof(inq));
        memset(dp,0,sizeof(dp));
        for (int i = 0;i < 2;i++)
            while (!Q[i].empty())
                Q[i].pop();
        Q[0].push(0);
        inq[0][0] = true;
        dp[0][0] = 1;
        bool flag = 0;
        int ca,cb;
        int upd;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < m; j++,flag = !flag)
            {
                memset(dp[!flag],0,sizeof(dp[!flag]));
                while (!Q[flag].empty())
                {
                    int k = Q[flag].front();
                    Q[flag].pop();
                    inq[flag][k] = false;
                    ca = (k>>j)&1;
                    cb = (k>>(j+1))&1;
                    if (ca == 1 && cb == 1) continue;
                    if (ca == 0 && cb == 0)
                    {
                        upd = k;
                        setbit(upd,j,0);
                        setbit(upd,j+1,1);
                        dp[!flag][upd] += dp[flag][k];
                        if (inq[!flag][upd] == false)
                        {
                            inq[!flag][upd] = true;
                            Q[!flag].push(upd);
                        }
                        upd = k;
                        setbit(upd,j,1);
                        setbit(upd,j+1,0);
                        dp[!flag][upd] += dp[flag][k];
                        if (inq[!flag][upd] == false)
                        {
                            inq[!flag][upd] = true;
                            Q[!flag].push(upd);
                        }
                    }
                    else
                    {
                        upd = k;
                        setbit(upd,j,0);
                        setbit(upd,j+1,0);
                        dp[!flag][upd] += dp[flag][k];
                        if (inq[!flag][upd] == false)
                        {
                            inq[!flag][upd] = true;
                            Q[!flag].push(upd);
                        }
                    }
                    dp[flag][k] = 0;
                }
            }
            if (i+1 == n)   break;
            while (!Q[flag].empty())
            {
                int j = Q[flag].front();
                Q[flag].pop();
                inq[flag][j] = false;
                ca = (j>>m)&1;
                if (ca == 0)
                {
                    upd = j*2;
                    dp[!flag][upd] += dp[flag][j];
                    if (inq[!flag][upd] == false)
                    {
                        inq[!flag][upd] = true;
                        Q[!flag].push(upd);
                    }
                }
                dp[flag][j] = 0;
            }
        }
        printf("%lld\n",dp[flag][0]);
    }
    return 0;
}
