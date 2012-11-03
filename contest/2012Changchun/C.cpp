#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[5];
int cc[3];

bool check()
{
	int sum = 0;
	for (int i = 0;i < 3;i++)
		if (cc[i] == -1)
			return true;
		else
			sum += cc[i];
	return sum%1024 == 0;
}

int calc()
{
	int sum = 0;
	for (int i = 0;i < 2;i++)
		if (cc[i] == -1)
			return 1024;
		else
			sum += cc[i];
	if (sum % 1024 == 0 && sum!=0)	return 1024;
	return sum%1024;
}

int main()
{
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 0;i < 5;i++)
			a[i] = -1;
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		int res = 0;
		for (int sta = (1<<3)-1,u = 1<<5;sta < u;)
		{
			int cnt = 0;
			for (int i = 0;i < 5;i++)
				if (((sta>>i)&1) == 1)
					cc[cnt++] = a[i];
			if (check())
			{
				cnt = 0;
				for (int i = 0;i < 5;i++)
					if (((sta>>i)&1) == 0)
						cc[cnt++] = a[i];
				res = max(res,calc());
			}

			int b = sta&-sta;
			sta = (sta+b)|(((sta^(sta+b))>>2)/b);
		}
		printf("%d\n",res);
	}
    return 0;
}

