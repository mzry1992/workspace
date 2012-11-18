#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int mod = 1000000000+7;
int n;
char buf[20];
int a,f0,f1,g0,g1;

int power(int x,int y)
{
	int res = 1;
	for (;y;y>>=1, x = (long long)x*x%mod)
		if (y&1)
			res = (long long)res*x%mod;
	return res;
}

int getInv(long long x)
{
	return power(x%mod,mod-2);
}

int main()
{
	scanf("%d",&n);
	f0 = f1 = 0;
	for (int i = 0;i < n;i++)
	{
		scanf("%s%d",buf,&a);
		if (buf[0] == 'i')
		{
			g0 = ((long long)f1*a%mod+f0)%mod;
			g1 = ((long long)f0*a%mod+f1+a)%mod;
		}
		else
		{
			g1 = (((long long)f0*a%mod-f1)%mod+a+mod)%mod;
			g1 = (long long)g1*getInv((long long)a*a-1)%mod;
			g0 = ((f0-((long long)g1*a%mod))%mod+mod)%mod;
		}
		printf("%d\n",g1);
		f0 = g0;
		f1 = g1;
	}
	return 0;
}
