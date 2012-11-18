#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000000+7;
int a[100000],b[100000],suma[100000],sumb[100000];
int n;

int main()
{
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		for (int i = 0;i < n;i++)
			scanf("%d",&b[i]);
		suma[0] = a[0];
		sumb[0] = b[0];
		for (int i = 1;i < n;i++)
		{
			suma[i] = (suma[i-1]+a[i])%mod;
			sumb[i] = (sumb[i-1]+b[i])%mod;
		}
		for (int i = 0;i < n;i++)
		{
			int ret = 0;
			ret = (ret+(long long)a[i]*sumb[i]%mod)%mod;
			ret = (ret+(long long)b[i]*suma[i]%mod)%mod;
			ret = ((ret-(long long)a[i]*b[i]%mod)%mod+mod)%mod;
			printf("%d",ret);
			if (i != n-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
