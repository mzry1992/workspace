#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000];

int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		int maxsum,res;
		maxsum = -1;
		for (int i = 1;i < n-1;i++)
			if (a[i-1]+a[i]+a[i+1] > maxsum)
			{
				maxsum = a[i-1]+a[i]+a[i+1];
				res = i;
			}
		printf("%d %d\n",maxsum,res+1);
	}
    return 0;
}

