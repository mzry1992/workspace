#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double a,b;
int resa,resb,ta,ta2,tb;

int main()
{
    while (scanf("%lf%lf",&a,&b) != EOF)
    {
        resa = floor(a)*floor(b);
        ta = floor(a);
        if (0.5+ta <= a)
            ta2 = ta;
        else
            ta2 = ta-1;
        tb = floor(2.0*(b-1)/sqrt(3))+1;
        resb = ta2*(tb/2)+ta*(tb-tb/2);
        swap(a,b);
        ta = floor(a);
        if (0.5+ta <= a)
            ta2 = ta;
        else
            ta2 = ta-1;
        tb = floor(2.0*(b-1)/sqrt(3))+1;
        resb = max(resb,ta2*(tb/2)+ta*(tb-tb/2));
        if (resa >= resb)
            printf("%d grid\n",resa);
        else
            printf("%d skew\n",resb);
    }
}
