#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char mp[10][10];
int n,m;

int main()
{
	n = m = 0;	
	while (gets(mp[n]))
	{
		m = max(m,strlen(mp[n]));
		n++;
	}
	
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			if (mp[i][j] == '+')
			{
				mp[i][j] == '.';
				sx = i;
				sy = j;
			}
	
	return 0;
}
