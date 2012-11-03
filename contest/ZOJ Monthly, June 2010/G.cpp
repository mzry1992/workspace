#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int n,d,a[maxn],b[maxn];

int main()
{
	while (scanf("%d%d",&n,&d) != EOF)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			b[i] = a[i];
		}
		sort(b,b+n);
		int bn = unique(b,b+n)-b;

	}
	return 0;
}
