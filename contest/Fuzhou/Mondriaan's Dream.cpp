#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
long long dp[2][1<<12];

void setbit(int& a,int pos,int val)
{
    if (val == 1)
        a = a|(1<<(pos-1));
    else
        a = a&~(1<<(pos-1));
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 || m == 0)   break;
        if (n < m)  swap(n,m);
        memset(dp,0,sizeof(dp));
        dp[0][1<<(m+1)] = 1;
        bool flag = 0,ca,cb;
        int upd;
        for (int i = 0;i < n;i++)
        {
            memset(dp[!flag],0,sizeof(dp[!flag]));
            for (int j = 0;j < m;j++)
                for (int k = 0;k < 1<<(1+m);k++)
                    if (dp[flag][k])
                    {
                        ca = (((k>>j)&1) == 1);
                        cb = (((k>>(j+1))&1) == 1);
                        if (ca == 1 && cb == 1)
                        {
                            upd = k;
                            setbit(upd,j,0);
                            setbit(upd,j+1,1);
                            dp[!flag][upd] = dp[!flag][upd]+dp[flag][k];
                            upd = k;
                            setbit(upd,j,1);
                            setbit(upd,j+1,0);
                            dp[!flag][upd] = dp[!flag][upd]+dp[flag][k];
                        }
                        else if (ca == 0 && cb == 1)
                        {
                            upd = k;
                            setbit(upd,j,1);
                            setbit(upd,j+1,1);
                            dp[!flag][upd] = dp[!flag][upd]+dp[flag][k];
                        }
                        else if (ca == 1 && cb == 0)
                        {
                            upd = k;
                            setbit(upd,j,1);
                            setbit(upd,j+1,1);
                            dp[!flag][upd] = dp[!flag][upd]+dp[flag][k];
                        }
                    }
        }
    }
    return 0;
}
