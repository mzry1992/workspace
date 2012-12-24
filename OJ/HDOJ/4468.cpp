#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100010];
int p[100010];

int main()
{
	int cas = 1;
	while (scanf("%s",s) != EOF)
	{
		int len = strlen(s);
		int j = 0;
		while (j < len && s[j] == s[j+1])
			j++;
		p[0] = len,p[1] = j;
		int k = 1;
		for (int i = 2;i < len;i++)
		{
			int Len = k+p[k]-1,L = p[i-k];
			if (L < Len-i+1)
				p[i] = L;
			else
			{
				j = max(0,Len-i+1);
				while (i+j < len && s[i+j] == s[j])
					j++;
				p[i] = j,k = i;
			}
		}
		int res = 0;
		for (int i = 1;i < len;i++)
		{
		}
		printf("Case %d: %d\n",cas++,len-res);
	}
	return 0;
}
