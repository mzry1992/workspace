#include <cstdio>
const int mod=1000000007;
int a[5000];
int fac[5001],inv[5001];
int getInv(int a)
{
	int ret=1;
	for (int j=mod-2;j;j>>=1,a=(long long)a*a%mod)
		if (j&1)
			ret=(long long)ret*a%mod;
	return ret;
}
int c(int a,int b)
{
	return (long long)fac[b]*inv[a]%mod*inv[b-a]%mod;
}
int main()
{
	fac[0]=1;
	for (int i=1;i<=5000;i++)
		fac[i]=(long long)fac[i-1]*i%mod;
	for (int i=0;i<=5000;i++)
		inv[i]=getInv(fac[i]);
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int k,x;
	scanf("%d%d",&k,&x);
	int les=0,equ=0,mor=0;
	for (int i=0;i<n;i++)
		if (a[i]<a[k])
			les++;
		else if (a[i]==a[k])
			equ++;
		else
			mor++;
	int ans=0;
	for (int i=0;i<x && i<=les;i++)
		for (int j=0;j+x<=t && j<=mor;j++)
			if (i+j+equ>=t)
				ans=(ans+(long long)c(i,les)*c(j,mor)%mod*c(t-i-j-1,equ-1)%mod)%mod;
	printf("%d\n",ans);
}
