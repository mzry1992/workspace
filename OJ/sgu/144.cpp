#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x,y;
double z,xx;

int main()
{
    scanf("%d%d%lf",&x,&y,&z);
    xx = (double)(y-x)*60;
    printf("%.8f\n",z*(2*xx-z)/(xx*xx));
	return 0;
}
