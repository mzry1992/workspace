#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
const int mod = 1000000007LL;
int dp[10000011];

int pos,val,prepos,preval;
char ch;

pair<int,int> kn[15];

long long res;

int tres;

inline int modadd(int a,int b)
{
    return (a+b)%mod;
}

int main()
{
    memset(dp,0,sizeof(dp));
    dp[1] = 1;
    for (int i = 2;i <= 10000010;i++)
    {
        if (i%2 == 1)
            dp[i] = modadd(modadd(dp[i-1]+1,dp[i-1]+1),dp[i-1]+1);
        else
            dp[i] = modadd(modadd(dp[i-1]-1,dp[i-1]-1),dp[i-1]-1);
    }
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < m;i++)
        {
            scanf("%d %c",&pos,&ch);
            kn[i] = make_pair(pos,ch-'A');
        }
        kn[m++] = make_pair(0,4);
        kn[m++] = make_pair(n+1,4);
        sort(kn,kn+m);
        res = 1;
        for (int i = 1;i < m;i++)
        {
            pos = kn[i].first;
            val = kn[i].second;
            prepos = kn[i-1].first;
            preval = kn[i-1].second;
            if (prepos+1 == pos)
            {
                if (val == preval)  res = 0;
                continue;
            }
            tres = 0;
            for (int j = 0;j < 4;j++)
                if (j != preval)
                    for (int k = 0;k < 4;k++)
                        if (k != val)
                            if (j == k)
                                tres = modadd(tres,dp[pos-prepos-1]);
                            else
                            {
                                if ((pos-prepos-1)%2 == 1)
                                    tres = modadd(tres,dp[pos-prepos-1]-1);
                                else
                                    tres = modadd(tres,dp[pos-prepos-1]+1);
                            }
            res = (res*(long long)tres)%mod;
        }
        printf("%lld\n",res);
    }
    return 0;
}
