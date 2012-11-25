#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

pair<int,long long> dp[110000];
pair<int,long long> a[110000];
int n,m,mid;
long long cnow,suml,sumr;
pair<int,long long> now;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d%d",&n,&m);
	    for (int i = 1;i <= n;i++)
            scanf("%d%lld",&a[i].first,&a[i].second);
        sort(a+1,a+1+n);
        dp[0] = make_pair(0,0);
        for (int i = 1;i <= n;i++)
        {
            cnow = suml = 0;
            sumr = a[i].second;
            mid = i;
            dp[i] = make_pair(dp[i-1].first+1,dp[i-1].second);
            for (int j = 2;j <= m && j <= i;j++)
            {
                cnow += a[i-j+1].second*(a[mid].first-a[i-j+1].first);
                suml += a[i-j+1].second;
                while (mid > i-j+1 && suml >= sumr)
                {
                    cnow = cnow+(sumr-suml)*(a[mid].first-a[mid-1].first);
                    mid--;
                    suml -= a[mid].second;
                    sumr += a[mid].second;
                }
                now = make_pair(dp[i-j].first+1,dp[i-j].second+cnow);
                if (dp[i].first > now.first || (dp[i].first == now.first && dp[i].second > now.second))
                    dp[i] = now;
            }
        }
        printf("%d %lld\n",dp[n].first,dp[n].second);
	}
	return 0;
}
