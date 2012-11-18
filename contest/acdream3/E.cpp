#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int flag[1<<20];
int a[20][20];
int n,mod;

int solve(int pos,int sta)
{
	if (flag[sta] != -1)	return flag[sta];
	int& ans = flag[sta];
	ans = 0;
	for (int i = 0;i < n;i++)
		if (((sta>>i)&1) == 0)
			ans = (ans+(long long)a[pos][i]*solve(pos+1,sta|(1<<i))%mod+mod)%mod;
	return ans;
}

int main()
{
	scanf("%d%d",&n,&mod);
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			scanf("%d",&a[i][j]);
	memset(flag,-1,sizeof(flag));
	flag[(1<<n)-1] = 1;
	printf("%d\n",solve(0,0));
	return 0;
}
