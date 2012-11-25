#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,d[10000],l[10000],m;
int dp[10000];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d%d",&d[i],&l[i]);
        scanf("%d",&m);
        memset(dp,0,sizeof(dp));
        dp[0] = d[0];
        for (int i = 1;i < n;i++)
            for (int j = i-1;j >= 0;j--)
            {
                int holdlen = min(l[j],dp[j]);
                if (d[j]+holdlen >= d[i])
                    dp[i] = max(dp[i],d[i]-d[j]);
            }
        //for (int i = 0;i < n;i++)
        //    cout << dp[i] << ' ';
        //cout << endl;
        bool res = false;
        for (int i = 0;i < n;i++)
            if (d[i]+min(l[i],dp[i]) >= m)
                res = true;
        printf("Case #%d: ",cas);
        if (res == true)
            puts("YES");
        else
            puts("NO");
	}
	return 0;
}
