#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long double a,b,c,d;
    while (cin >> a >> b >> c >> d)
    {
        long double p1,p2,q1,q2,res=1e100;
        if (a*d>=c*b)
        {
            if (b*b<=a*d && c*c<=a*d)
            {
                p1 = 1;
                p2 = sqrt(d/a);
                q1 = a;
                q2 = sqrt(a*d);
                res=a+d+2*sqrt(a*d);
            }
            else if (c>b)
            {
                p1 = 1;
                p2 = c/a;
                q1 = a;
                q2 = a*d/c;
                res = a+d+c+a*d/c;
            }
            else
            {
                p1 = 1;
                p2 = d/b;
                q1 = a;
                q2 = b;
                res = a+d+b+a*d/b;
            }
        }
        else
        {
            if (a*a<=b*c && d*d<=b*c)
            {
                p1=1;
                p2=sqrt(c/b);
                q1=sqrt(b*c);
                q2=b;
                res=b+c+2*sqrt(b*c);
            }
            else if (a>d)
            {
                p1=1;
                p2=c/a;
                q1=a;
                q2=b;
                res=b+c+b*c/a+a;
            }
            else
            {
                p1=b/d;
                p2=1;
                q1=c;
                q2=d;
                res=b+c+b*c/d+d;
            }
        }
        double dres,dp1,dp2,dq1,dq2;
        dres = res;
        dp1 = p1;
        dp2 = p2;
        dq1 = q1;
        dq2 = q2;
        printf("%.10f\n%.10f %.10f %.10f %.10f\n",dres,dp1,dp2,dq1,dq2);
    }
    return 0;
}
