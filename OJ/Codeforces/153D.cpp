#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long a[100000];
pair<long long,long long> dp[60];

int main()
{
	while (scanf("%d",&n) != EOF)
	{
		long long xorsum = 0;
		for (int i = 0;i < n;i++)
		{
			//@TODO I64D!!!
			scanf("%lld",&a[i]);
			xorsum ^= a[i];
		}
		sort(a,a+n);
		reverse(a,a+n);
		int tn = 0;
		for (int i = 59;i >= 0;i--)
		{
			for (int j = tn;j < n;j++)
				if (((a[j]>>i)&1) == 1)
				{
					swap(a[j],a[tn]);
					break;
				}
			if (tn == n || ((a[tn]>>i)&1) == 0)
				continue;
			for (int j = 0;j < n;j++)
				if (tn != j && (((a[j]>>i)&1) == 1))
					a[j] ^= a[tn];
			tn++;
		}
		printf("%lld\n",xorsum);
		for (int i = 0;i < tn;i++)
		{
			for (int j = 59;j >= 0;j--)
				printf("%d",((a[i]>>j)&1) == 1);
			printf("\n");
		}
	}
}
