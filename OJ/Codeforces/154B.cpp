#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[100000];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int ans = n-1;
		for (int i = 0;i < n;i++)
		{
			int pos = upper_bound(a,a+n,2*a[i])-a;
			ans = min(ans,i+n-pos);
		}
		printf("%d\n",ans);
	}
	return 0;
}
