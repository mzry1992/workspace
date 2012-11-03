#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("K.in","w",stdout);
	for (int cas = 0; cas < 10; ++cas)
	{
		int n = 80000;
		printf("%d\n",n);
		for (int i = 0; i < n; ++i)
		{
			printf("%d %d\n",i*2 <= n,rand());
		}
	}
	return 0;
}
