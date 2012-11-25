#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double r = 0.57721566490153286060651209008240243104215;
double a;
char buf[1000];

int main()
{
    while (scanf("%lf",&a) != EOF)
    {
        printf("%.12e\n",(pow(2,a)-1)*r);
    }
	return 0;
}
