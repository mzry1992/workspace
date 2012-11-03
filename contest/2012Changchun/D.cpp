#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double A,B,C,D,E;

double f(double x)
{
	return (A*x*x+B*x+C)/(x*x+D*x+E);
}

int main()
{
	while (scanf("%lf%lf%lf%lf%lf",&A,&B,&C,&D,&E) != EOF)
	{
		double x;
		while (scanf("%lf",&x) != EOF)
		{
			printf("%.12f\n",f(x));
		}
	}
    return 0;
}

