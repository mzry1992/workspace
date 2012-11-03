#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=5000;
const int mod=1000000007;
int dp[2][5000];
int a[5000];
int tree[5001];
int read(int k)
{
	int sum=0;
	for (;k;k^=k&-k)
		sum=(sum+tree[k])%mod;
	return sum;
}
void update(int k,int v)
{
	for (;k<=MAXN;k+=k&-k)
		tree[k]=(tree[k]+v)%mod;
}
int solve(int x,int t)
{
	if (t==1)
		return 1;
	bool flag=0;
	for (int i=0;i<x;i++)
		dp[0][i]=1;
	for (int i=2;i<=t;i++,flag=!flag)
	{
		memset(tree,0,sizeof(tree));
		for (int j=0;j<x;j++)
		{
			dp[!flag][j]=read(a[j]);
			update(a[j],dp[flag][j]);
		}
	}
	return dp[flag][x-1];
}
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
		a[i]=5001-a[i];
	int k,x;
	scanf("%d%d",&k,&x);
	int ans=solve(k,t-x+1);
	reverse(a,a+n);
	for (int i=0;i<n;i++)
		a[i]=5001-a[i];
	k=n-k+1;
	ans=(long long)ans*solve(k,x)%mod;
	printf("%d\n",ans);
	return 0;
}
