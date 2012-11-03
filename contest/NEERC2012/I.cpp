#include <cstdio>
const int mod=1000000007;
int f[5001];
int main()
{
	int n;
	scanf("%d",&n);
	f[1]=1;
	for (int i=2;i<=n;i++)
	{
		int nn=i;
		for (int j=1;j<i;j++,nn=(long long)nn*i%mod)
		{
			f[i]-=(long long)nn*f[i-j]%mod;
			if (f[i]<0)
				f[i]+=mod;
		}
		f[i]=(f[i]+nn)%mod;
	}
	printf("%d\n",f[n]);
	return 0;
}
