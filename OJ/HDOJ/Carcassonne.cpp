#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int mod = 1000000007;
int n,m;
char buf[5];
int mp[12][12][8];
int dp[2][1594323];
bool inq[2][1594323];
queue<int> Q[2];
int ss[15];

int getid(char ch)
{
    if (ch == 'C')  return 0;
    if (ch == 'R')  return 1;
    return 2;
}

inline int getbit(int sta,int pos)
{
    return (sta/ss[pos])%3;
}

void setbit(int& sta,int pos,int val)
{
    sta = sta/ss[pos+1]*ss[pos+1]+val*ss[pos]+sta%ss[pos];
}

inline bool check(int x,int y,int q,int sta)
{
    int ca,cb;
    ca = getbit(sta,y);
    cb = getbit(sta,y+1);
    if (x == 0) cb = mp[x][y][q+1];
    if (y == 0) ca = mp[x][y][q];
    return ca == mp[x][y][q] && cb == mp[x][y][q+1];
}

int main()
{
    ss[0] = 1;
    for (int i = 1; i < 15; i++)
        ss[i] = ss[i-1]*3;
    memset(inq,false,sizeof(inq));
    for (int i = 0; i < 2; i++)
        while (!Q[i].empty())
            Q[i].pop();
    memset(dp,0,sizeof(dp));
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%s",buf);
                for (int k = 0; k < 4; k++)
                    mp[i][j][k] = mp[i][j][k+4] = getid(buf[k]);
            }
        dp[0][0] = 1;
        inq[0][0] = true;
        Q[0].push(0);
        bool flag = 0;
        int upd;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            while (!Q[!flag].empty())
            {
                int k = Q[!flag].front();
                Q[!flag].pop();
                inq[!flag][k] = false;
                upd = k*3%ss[m+1];
                dp[flag][upd] = (dp[flag][upd]+dp[!flag][k])%mod;
                if (!inq[flag][upd])
                {
                    inq[flag][upd] = true;
                    Q[flag].push(upd);
                }
                dp[!flag][k] = 0;
            }
            for (int j = 0; j < m; j++,flag = !flag)
            {
                while (!Q[flag].empty())
                {
                    int k = Q[flag].front();
                    Q[flag].pop();
                    inq[flag][k] = false;
                    for (int q = 0; q < 4; q++)
                        if (check(i,j,q,k) == true)
                        {
                            upd = k;
                            setbit(upd,j,mp[i][j][q+3]);
                            setbit(upd,j+1,mp[i][j][q+2]);
                            dp[!flag][upd] = (dp[!flag][upd]+dp[flag][k])%mod;
                            if (!inq[!flag][upd])
                            {
                                inq[!flag][upd] = true;
                                Q[!flag].push(upd);
                            }
                        }
                    dp[flag][k] = 0;
                }
            }
        }
        int res = 0;
        while (!Q[!flag].empty())
        {
            int k = Q[!flag].front();
            Q[!flag].pop();
            inq[!flag][k] = false;
            res = (res+dp[!flag][k])%mod;
            dp[!flag][k] = 0;
        }
        printf("Case %d: %d\n",ft,res);
    }
    return 0;
}

