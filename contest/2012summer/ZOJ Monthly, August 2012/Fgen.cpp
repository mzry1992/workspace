#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const char a[2][10] = {"less","ffff"};

int main()
{
	freopen("F.in","w",stdout);
	for (int cas = 1;cas <= 5;cas++)
	{
	    int n = 16,m = 10000000;
	    printf("%d %d\n",n,m);
	    for (int i = 0;i < n;i++)
	        printf("a: %s than %d\n",a[rand()%2],rand());
	}
	printf("0 0\n");
	return 0;
}
