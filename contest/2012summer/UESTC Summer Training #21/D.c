#include <stdio.h>
#include <math.h>

const double r = 0.57721566490153286060651209008240243104215;
double a;

int main()
{
    while (scanf("%lf",&a) != EOF)
        printf("%.12e\n",(pow(2,a)-1)*r);
	return 0;
}
