#include <iostream>
using namespace std;
int prime[1000000];
bool notPrime[1000001];
int N;
long long fac[40];
int L;
void getPrime(int x)
{
	for (int i=2;i<=x;i++)
		if (!notPrime[i])
		{
			prime[N++]=i;
			for (int j=i+i;j<=x;j+=i)
				notPrime[j]=1;
		}
}
void getFactor(long long a)
{
	for (int i=0;i<N && (long long)prime[i]*prime[i]<=a;i++)
		if (a%prime[i]==0)
		{
			fac[L++]=prime[i];
			while (a%prime[i]==0)
				a/=prime[i];
		}
	if (a>1)
		fac[L++]=a;
}
long long count0(long long a,long long n)
{
	getFactor(a);
	int full=1<<L;
	n/=2;
	long long tot=0;
	for (int i=1;i<full;i++)
	{
		bool flag=0;
		long long pro=1;
		for (int j=0;j<L;j++)
			if (i>>j&1)
			{
				flag=!flag;
				pro*=fac[j];
			}
		if (flag)
			tot+=n/pro;
		else
			tot-=n/pro;
	}
	return tot;
}
long long count1(long long a,long long n)
{
	getFactor(a);
	int full=1<<L;
	long long tot=0;
	for (int i=1;i<full;i++)
	{
		bool flag=0;
		long long pro=1;
		for (int j=0;j<L;j++)
			if (i>>j&1)
			{
				flag=!flag;
				pro*=fac[j];
			}
		if (flag)
			tot+=n/pro;
		else
			tot-=n/pro;
	}
	return tot;
}
int main()
{
	getPrime(1000000);
	long long a,n;
	cin>>a>>n;
	if (a==1)
	{
		cout<<(n+1)/2<<endl;
		return 0;
	}
	long long ans;
	if (a&1)
		ans=n+1>>1;
	else
		ans=n/2;
	if (a&1)
		cout<<(n+1)/2+count0(a,n)<<endl;
	else
		cout<<count1(a,n)<<endl;
	return 0;
}
