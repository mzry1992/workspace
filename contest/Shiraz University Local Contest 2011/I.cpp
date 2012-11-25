#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int s[100005],pos[100005];
int dp[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    int i;
	    for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        memset(pos,-1,sizeof(pos));
        dp[0]=0;
        pos[s[0]]=0;
        for(i=1;i<n;i++)
        {
            dp[i]=dp[i-1];
            if(pos[s[i]]!=-1)
                dp[i]=max(dp[i],dp[pos[s[i]]]+1);
            pos[s[i]]=i;
        }
        printf("%d\n",dp[n-1]);
	}
    return 0;
}

