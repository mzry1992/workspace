#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 55;
bool g[MaxN][MaxN];
int n;
int list[MaxN][MaxN],s[MaxN],degree[MaxN],behide[MaxN];
int found,curmax;

void sortdegree()
{
	for (int i = 1;i <= n;i++)
	{
		int k = i;
		for (int j = i+1;j <= n;j++)
			if (degree[j] < degree[k])
				k = j;
		if (k != i)
		{
			swap(degree[i],degree[k]);
			for (int l = 1;l <= n;l++)
				swap(g[i][l],g[k][l]);
			for (int l = 1;l <= n;l++)
				swap(g[l][i],g[l][k]);
		}
	}
}

void dfs(int d)
{
	if (d-1 > curmax)
	{
		found = 1;
		return;
	}
	for (int i = 1;i < list[d-1][0]-curmax+d;i++)
		if (!found && d+behide[list[d-1][i]+1] > curmax && (list[d-1][0] == i || d+behide[list[d-1][i+1]] > curmax))
		{
			list[d][0] = 0;
			for (int j = i+1;j <= list[d-1][0];j++)
				if (g[list[d-1][j]][list[d-1][i]])
					list[d][++list[d][0]] = list[d-1][j];
			if (list[d][0] == 0 || d+behide[list[d][1]] > curmax)
				dfs(d+1);
		}
}

int solve()
{
	for (int i = 1;i <= n;i++)
	{
		degree[i] = 0;
		for (int j = 1;j <= n;j++)
			degree[i] += g[i][j];
	}
	sortdegree();
	behide[n+1] = 0;
	behide[n] = 1;
	for (int i = n-1;i > 0;i--)
	{
		curmax = behide[i+1];
		found = list[1][0] = 0;
		for (int j = i+1;j <= n;j++)
			if (g[j][i])
				list[1][++list[1][0]] = j;
		dfs(2);
		behide[i] = curmax+found;
	}
	return behide[1];
}

int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (n == 0)	break;

		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				scanf("%d",&g[i][j]);

		printf("%d\n",solve());
	}
	return 0;
}
