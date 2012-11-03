#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n,a[10];

int check(int x)
{
	for (int i = 0;i < n;i++)
		x = abs(x-a[i]);
	return x;
}

int l[2000],r[2000],cnt;

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	cnt = 0;
	for (int x = -12000;x <= 12000;x++)
		if (check(x) <= 1)
		{
			l[cnt] = x;
			while (check(x+1) <= 1)
				x++;
			r[cnt++] = x;
		}
	printf("%d\n",cnt);
	for (int i = 0;i < cnt;i++)
		printf("%d %d\n",l[i],r[i]);
    return 0;
}

