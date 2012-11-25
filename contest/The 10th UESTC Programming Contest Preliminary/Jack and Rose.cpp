#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10000][10000],a[10000],n;
bool flg[10000][10000];
bool fir;
int calc(int l,int r)
{
    if (flg[l][r] == true)  return dp[l][r];
    flg[l][r]=1;
    int &ret=dp[l][r]=0;
    if (r==l)
        return 0;
    if (fir==((r-l)&1))
        return ret=min(calc(l,r-1)-a[r-1],calc(l+1,r)-a[l+1]);
    else
        return ret=max(calc(l,r-1)+a[r-1],calc(l+1,r)+a[l+1]);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        fir=n&1;
        memset(flg,false,sizeof(flg));
        int res = calc(0,n-1)+a[0]-a[n-1];
        printf("Case #%d: ",ft);
        if (res > 0)
            puts("win");
        else if (res == 0)
            puts("tie");
        else
            puts("lose");
    }
	return 0;
}
