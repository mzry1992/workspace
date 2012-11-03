#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

bool am[110][110], use[110];
int pre[110];

bool check(int u)
{
	for (int v = 1; v <= n; v++)
		if (am[u][v] && !use[v])
		{
			use[v] = 1;
			if (pre[v] == -1 || check(pre[v]))
			{
				pre[v] = u;
				return 1;
			}
		}
	return 0;
}
int match()
{
	int ret = 0;
	memset(pre, -1, sizeof(pre));
	for (int u = 1; u <= n; u++)
	{
		memset(use, 0, sizeof(use));
		if (check(u))
			ret++;
	}
	return ret;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(am, false, sizeof(am));
		for (int i = 1; i <= n; i++)
		
			int tot;
			scanf("%d", &tot);
			for (int j = 0; j < tot; j++)
			{
				int to;
				scanf("%d", &to);
				am[i][to] = true;
			}
		}
		printf("%d\n", n - match());
	}
	return 0;
}
