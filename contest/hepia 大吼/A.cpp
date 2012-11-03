#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int a[10],b[10];

int main()
{
	while (true)
	{
		scanf("%d%d",&n,&m);
		if (n == 0 && m == 0)	break;
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		for (int i = 0;i < m;i++)
			scanf("%d",&b[i]);
		int res = 0;
		sort(a,a+n);
		sort(b,b+m);
		int curi,curj;
		curi = curj = 0;
		while (curi < n || curj < m)
		{
			if (curi == n)
				res += b[curj++];
			else if (curj == m)
				res += a[curi++];
			else if (a[curi] == b[curj])
			{
				res += a[curi];
				curi++;
				curj++;
			}
			else if (a[curi] < b[curj])
				res += a[curi++];
			else
				res += b[curj++];
		}
		printf("%d\n",res);
	}
    return 0;
}

