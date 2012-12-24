#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,d,x[100000];

int main()
{
	while (scanf("%d%d",&n,&d) != EOF)
	{
		for (int i = 0;i < n;i++)
			scanf("%d",&x[i]);
		sort(x,x+n);
		long long ans = 0;
		for (int i = 0,j = 0;i < n;i++)
		{
			while (j+1 < n && x[j+1]-x[i] <= d)
				j++;
			if (j-i+1 >= 3)
			{
				int dis = j-i-1;
				ans += (long long)dis*(dis+1)/2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
