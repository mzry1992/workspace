#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
char mp[15][15];
long long dp[2][1594323];
int bit[15],oth[15],s[15],top;
queue<int> Q[2];
bool inq[2][1594323],flag;
int k,l,u,upd;

inline int getbit(int sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline int setbit(int sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

void updata(int a,int b,long long v)
{
    dp[a][b] += v;
    if (inq[a][b] == false)
    {
        inq[a][b] = true;
        Q[a].push(b);
    }
}

void extand(int sta)
{
    top = 0;
    for (int i = 0; i < m+1; i++)
        if (getbit(sta,i) == 1)
            s[top++] = i;
        else if (getbit(sta,i) == 2)
        {
            oth[s[top-1]] = i;
            oth[i] = s[top-1];
            top--;
        }
}

int lasx,lasy;
int fisx,fisy;

int main()
{
    freopen("in.txt","r",stdin);
    bit[0] = 1;
    for (int i = 1; i < 15; i++)
        bit[i] = bit[i-1]*3;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        lasx = lasy = fisx = fisy = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] != '*')
                    lasx = i,lasy = j;
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >= 0; j--)
                if (mp[i][j] != '*')
                    fisx = i,fisy = j;
        long long res = 0;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < m; j++,flag = !flag)
            {
                //cout << i << ' ' << j << ' ' << Q[flag].size() << endl;
                if (i == fisx && j == fisy)
                {
                    Q[flag].push(0);
                    inq[flag][0] = true;
                    dp[flag][0] = 1;
                }
                while (!Q[flag].empty())
                {
                    k = Q[flag].front();
                    Q[flag].pop();
                    inq[flag][k] = false;
                    l = getbit(k,j);
                    u = getbit(k,j+1);
                    if (mp[i][j] == '*')
                    {
                        if (l == 0 && u == 0)
                            updata(!flag,k,dp[flag][k]);
                    }
                    else
                    {
                        if (l == 0 && u == 0)
                        {
                            //新建插头
                            upd = setbit(setbit(k,j,1),j+1,2);
                            updata(!flag,upd,dp[flag][k]);
                        }
                        else if (l != 0 && u != 0)
                        {
                            //合并插头
                            upd = setbit(setbit(k,j,0),j+1,0);
                            if (l == u)
                            {
                                extand(k);
                                if (l == 1)
                                    upd = setbit(upd,oth[j+1],1);
                                else
                                    upd = setbit(upd,oth[j],2);
                                updata(!flag,upd,dp[flag][k]);
                            }
                            else
                            {
                                if (l == 2)
                                    updata(!flag,upd,dp[flag][k]);
                                else if (i == lasx && j == lasy)
                                {
                                    if (upd == 0)
                                        res += dp[flag][k];
                                }
                            }
                        }
                        else
                        {
                            //保持插头
                            upd = setbit(setbit(k,j,0),j+1,l+u);
                            updata(!flag,upd,dp[flag][k]);
                            upd = setbit(setbit(k,j+1,0),j,l+u);
                            updata(!flag,upd,dp[flag][k]);
                        }
                    }
                    dp[flag][k] = 0;
                }
            }
            if (i+1 == n)   break;
            while (!Q[flag].empty())
            {
                k = Q[flag].front();
                Q[flag].pop();
                inq[flag][k] = false;
                l = getbit(k,m);
                if (k != 0 && l == 0)
                    updata(!flag,k*3,dp[flag][k]);
                dp[flag][k] = 0;
            }
        }
        printf("%lld\n",res);
        while (!Q[flag].empty())
        {
            k = Q[flag].front();
            Q[flag].pop();
            inq[flag][k] = false;
            dp[flag][k] = 0;
        }
    }
    return 0;
}
