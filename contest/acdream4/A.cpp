#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
int n;
double d,ang[20];

int main()
{
	while (scanf("%d%lf",&n,&d) != EOF)
	{
		for (int i = 0;i < n;i++)
			scanf("%lf",&ang[i]);
		double area = 0;
		for (int i = 0;i < n;i++)
		{
			ang[i] = ang[i]/180*pi;
			area += d*d*sin(ang[i]);
		}
		printf("%.3f\n",area/2);
	}
	return 0;
}
