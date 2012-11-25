#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k,b[13],like[13][13];
bool dp[13][1<<13],val[13][1<<13];

bool check(int pos,int msk)
{
    int res = 0;
    for (int i = 0;i < n;i++)
        if (((msk>>i)&1) == 1)
            if (like[pos][i])
                res += k;
            else
                res++;
    return res >= b[pos];
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0;i < m;i++)
            scanf("%d",&b[i]);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                scanf("%d",&like[i][j]);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < (1<<n);j++)
                val[i][j] = check(i,j);
        int full = (1<<n)-1;
        memset(dp,false,sizeof(dp));
        for (int i = 0;i < (1<<n);i++)
            dp[0][i] = val[0][i];
        for (int i = 0;i < m-1;i++)
            for (int j = 0;j <= full;j++)
                if (dp[i][j])
                    for (int k = full^j;k;k=(k-1)&(full^j))
                        dp[i+1][j|k] |= val[i+1][k];
        printf("Case #%d: ",cas);
        if (dp[m-1][(1<<n)-1])
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
