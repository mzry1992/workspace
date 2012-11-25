#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long r(long long val)
{
	long long res = 0;
	while (val)
	{
		res = res*10+val%10;
		val /= 10;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	freopen("J.in","w",stdout);
	for (int i = 0; i < 100000; ++i)
	{
		long long tmp = 0;
		for (int j = 0; j < 5; ++j)
			tmp = tmp*10+rand()%10;
		printf("%lld\n",tmp+r(tmp));
	}
	puts("0");
	return 0;
}