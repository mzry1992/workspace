#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const long long mod = 1000000007;
int n,f,b;
long long dp[2001][2001];
int main()
{
    int i;
    for(i=0;i<=2000;i++)
        dp[i][0]=1;
    int j;
    for(i=1;i<=2000;i++)
        for(j=1;j<=i;j++)
            dp[i][j]=(dp[i-1][j]+(dp[i-1][j-1]*i)%mod)%mod;
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d%d",&n,&f,&b);
	    if(f+b-1>n||(f==1&&b==1&&n>1))
	    {
            printf("0\n");
            continue;
	    }
	    int k1,k2;
	    k1=max(f,b);
	    k2=min(f,b);
	    long long ans=dp[n-2][n-k1-k2+1];
	    if(f!=1&&b!=1)
            ans*=2;
	    printf("%I64d\n",ans%mod);
	}
	return 0;
}
