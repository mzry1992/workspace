#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double a,b,c;

int main()
{
    while (scanf("%lf%lf%lf",&a,&b,&c) != EOF)
    {
        double p = 1000/(1.0+a/b+a/c);
        double q = a/b*p;
        double k = 1000-p-q;
        double kk = min(p*a,min(q*b,k*c))+0.5;
        printf("%d\n",(int)kk);
        //cout << p << ' ' << q << ' ' << k << ' ' << kk << endl;
    }
}
