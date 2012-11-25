#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

bool check(long long p)
{
	int n = (1+(int)sqrt(1.0+24.0*p))/6;
	return (long long)n*(3*n-1)/2 == p;
}

void run()
{

	for (int resn = 1;resn <= 10;resn++)
	{
		long long res = (long long)resn*(3*resn-1)/2;

		long long parta = 3;
		long long partb = 1;
		long long cntb = 1;
		for (int dist = 1;dist <= 10;dist++)
		{
			printf("parta = %lld, partb = %lld\n",parta,partb);
			if (res%parta == partb)
			{
				int n = (res-partb)/parta;
				//if (n == 0)	continue;

				long long pj = (long long)n*(3*n-1)/2;
				long long pk = pj+res;

				printf("D = %lld, pj = %lld, pk = %lld\n",res,pj,pk);
				if (check(pj+pk))
				{
					printf("Find!\n");
					//return;
				}
			}

			cntb += 3;
			parta += 3;
			partb += cntb;
		}
	}
}

int main()
{
	run();
	return 0;
}
