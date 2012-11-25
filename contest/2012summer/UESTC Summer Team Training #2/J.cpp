#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	double N,P,Q;
	int cas=1;
	while(scanf("%lf%lf%lf",&N,&P,&Q)==3)
	{
	    printf("Case %d: %.4f\n",cas++,(Q+1)/(P+2));
	}
	return 0;
}
