#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[20],b[20];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		scanf("%s%s",a,b);
		int la = strlen(a);
		int lb = strlen(b);
		if (la > lb)
		{
			puts("no");
			continue;
		}

		int suma = 0,sumb = 0;
		for (int i = 0;i < la;i++)
			suma += a[i]-'0';
		for (int i = 0;i < lb;i++)
			sumb += b[i]-'0';
		if (la == lb)
		{
			if (suma == sumb)
				puts("yes");
			else
				puts("no");
			continue;
		}

		while (la < lb)
		{
			suma -= 9;
			la++;
		}
		if (suma <= 0)
		{
			puts("no");
			continue;
		}
		if (suma == sumb)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
