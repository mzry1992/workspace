#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1200],t[250];
bool map[1200][250];
int l[250];
long long dp[1200];
int n;
const long long MOD = 1000000007LL;

int max(int a,int b)
{
    if (a > b)  return a;
    return b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%s",s);
        int ls = strlen(s);
        scanf("%d",&n);
        memset(map,false,sizeof(map));
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",t);
            int lt = l[i] = strlen(t);
            for (int j = 0;j <= ls-lt;j++)
            {
                bool flag = true;
                for (int k = 0;k < lt;k++)
                if (s[j+k] != t[k])
                {
                    flag = false;
                    break;
                }
                map[j][i] = flag;
            }
        }
        dp[0] = 1;
        for (int i = 1;i < ls;i++)
        {
            dp[i] = 0;
            bool hasans = false;
            for (int j = max(0,i-199);j < i;j++)
                if (dp[j] > 0)
                    for (int k = 1;k <= n;k++)
                    {
                        int ways = 0;
                        if (map[j][k] == true && j+l[k]-1 >= i)
                            ways++;
                        if (ways > 0)   hasans = true;
                        dp[i] = (dp[i]+(dp[j]*ways)%MOD)%MOD;
                    }
        }
        printf("%lld\n",dp[ls-1]);
    }
}
