#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char a[3001],b[3001];
int la,lb;
int dp[1501][26],nxta[3001][26],nxtb[3001][26];

int main()
{
	while (scanf("%s%s",a,b) != EOF)
	{
		la = strlen(a);
		lb = strlen(b);
		for (int i = 0;i < la;i++)
			a[la+i] = a[i];
		a[la*2] = 0;
		for (int i = 0;i < lb;i++)
			b[lb+i] = b[i];
		b[lb*2] = 0;
		
		for (int i = 0;i < 26;i++)
		{
			nxta[la*2][i] = -1;
			nxtb[lb*2][i] = -1;
		}
		for (int i = la*2-1;i >= 0;i--)
		{
			for (int j = 0;j < 26;j++)
				nxta[i][j] = nxta[i+1][j];
			nxta[i][a[i]-'a'] = i;
		}
		for (int i = lb*2-1;i >= 0;i--)
		{
			for (int j = 0;j < 26;j++)
				nxtb[i][j] = nxtb[i+1][j];
			nxtb[i][b[i]-'a'] = i;
		}

		int res = 0;
		printf("%d\n",res);
	}
	return 0;
}
