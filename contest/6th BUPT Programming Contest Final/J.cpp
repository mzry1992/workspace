#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int d;
double x,y;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d%lf%lf",&d,&x,&y);
        bool gao = false;
        x -= 2.5;
        if (x < 0)
        {
            gao = true;
            x = -x;
        }
        double len = sqrt(x*x+y*y);
        x *= (double)d/len;
        y *= (double)d/len;
        x += 2.5;
        if (y >= 20)
            puts("-1");
        else
        {
            if (y > 10) y = 20-y;
            int tt = (int)(x/10);
            x = x-10*tt;
            if (x > 5)  x = 10-x;
            double r = min(min(x,5-x),min(y,10-y));
            if (gao == true)
                x = 5-x;
            printf("%.3f %.3f %.3f\n",x,y,r);
        }
	}
	return 0;
}
