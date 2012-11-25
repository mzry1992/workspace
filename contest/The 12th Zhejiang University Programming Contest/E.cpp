#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double a,A0,b,x;

int main()
{
    while (scanf("%lf",&A0) != EOF)
    {
        a = A0;
        b = 1;
        x = 30;
        for (int i = 1;i <= 100000;i++)
        {
            b = 1.0+(i-1)/b;
            a = a*b*x/i;
            if (a<1e-14)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
	return 0;
}
