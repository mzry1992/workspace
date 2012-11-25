#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("B.in","w",stdout);
	for (int cas = 1;cas <= 10;cas++)
	{
	    int n = 100000,x = rand(),y = rand();
	    printf("%d %d %d\n",n,x,y);
	    for (int i = 0;i < n;i++)
            printf("%.2f %.2f\n",1.0*rand()+1,1.0*(rand()%1001)/10000);
	}
	return 0;
}
