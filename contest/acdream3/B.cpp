#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000000+7;
int n,m;

long long calc(long long n)
{
	return ((n*n/4)*n/2)%mod;
}

int main()
{
	/*int pre;
	for (n = 1;n <= 20;n++)
	{
		for (m = 1;m <= 20;m++)
		{
			int ans = 0;
			for (int xa = 0;xa < n;xa++)
				for (int ya = 0;ya < m;ya++)
					for (int xb = 0;xb < n;xb++)
						for (int yb = 0;yb < m;yb++)
							for (int xc = 0;xc < n;xc++)
								for (int yc = 0;yc < m;yc++)
									if (((xb-xa)*(yc-ya)-(yb-ya)*(xc-xa))%2 != 0)
										ans++;
			printf("%8d",ans-24*calc(n)*calc(m));
		}
		printf("\n");
	}*/
	while (scanf("%d%d",&n,&m) != EOF)
	{
		long long ans = 24;
		ans = calc((long long)n)*ans%mod;
		ans = calc((long long)m)*ans%mod;
		cout << ans << endl;
	}
	return 0;
}
