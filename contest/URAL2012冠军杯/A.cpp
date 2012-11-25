#include <cstdio>
#include <cstring>
int a[500][501];
int dp[501][501],pre[501][501];
inline int count(int l,int r)
{
	return a[r-1][r]-a[l-1][r];
}
void print(int i,int j)
{
	if (pre[i][j]!=-1)
	{
		print(pre[i][j],j-1);
		printf("%d ",i-1);
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<n;i++)
		for (int j=n-1;j;j--)
			a[i][j]+=a[i][j+1];
	for (int j=2;j<=n;j++)
		for (int i=2;i<=j;i++)
			a[i][j]+=a[i-1][j];
	memset(dp,-1,sizeof(dp));
	dp[1][0]=0;
	memset(pre,-1,sizeof(pre));
	for (int i=2;i<=n;i++)
		for (int k=1;k<i;k++)
			for (int j=1;j<i;j++)
				if (dp[j][k-1]!=-1 && dp[i][k]<dp[j][k-1]+count(j,i))
				{
					dp[i][k]=dp[j][k-1]+count(j,i);
					pre[i][k]=j;
				}
	int ans=-1,idx;
	for (int i=1;i<=n;i++)
		if (ans<dp[i][k])
		{
			ans=dp[i][k];
			idx=i;
		}
	printf("%d\n",ans);
	print(idx,k);
	puts("");
	return 0;
}
