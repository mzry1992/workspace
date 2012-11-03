#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
double p[100],s1,s2;
const double pi = acos(-1.0);
const double eps = 1e-12;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%lf",&p[i]);
        double l,r,mid,tl,tr;
        l = -1e100;
        r = 1e100;
        for (int i = 0; i < n; i++)
        {
            s1 = p[i];
            s2 = p[(i+1)%n];
            tl = fabs(s1-s2);
            tr = s1+s2;
            l = max(l,tl);
            r = min(r,tr);
        }
        printf("Case %d: ",ft);
        if (l > r)
        {
            puts("impossible");
            continue;
        }
        tl = l;
        tr = r;
        double sum = 0;
        for (int ii = 0; ii < 80; ii++)
        {
            mid = (l+r)/2;
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                s1 = p[i];
                s2 = p[(i+1)%n];
                sum += acos((s1*s1+s2*s2-mid*mid)/(2*s1*s2));
            }
            if (sum > 2*pi) r = mid;
            else l = mid;
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            s1 = p[i];
            s2 = p[(i+1)%n];
            sum += acos((s1*s1+s2*s2-l*l)/(2*s1*s2));
        }
        //cout << sum << endl;
        if (cmp(sum,2*pi) != 0)
            puts("impossible");
        else
            printf("%.3f\n",l);
    }
    return 0;
}
