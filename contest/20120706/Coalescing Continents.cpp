#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char mp[20][21];

int main()
{
	int totcas;
	scanf("%d",totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		for (int i = 0;i < 20;i++)
			scanf("%s",mp[i]);
		for (int i = 0;i < 20;i++)
			for (int j = 0;j < 20;j++)
				if (mp[i][j] == 'x')
				{
				}
	}
	return 0;
}
