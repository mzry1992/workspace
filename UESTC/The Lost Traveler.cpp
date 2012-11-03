#include <cstdio>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
int n;
double tmp,cur,a,b,c,d;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        cur = 0.0;
        bool a0,a1,b0,b1,c0,c1,d0,d1;
        a0 = a1 = b0 = b1 = c0 = c1 = d0 = d1 = false;
        a1 = c1 = d1 = true;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lf",&tmp);
            cur += tmp;
            if (cur < 0.0)    cur += 360.0;
            if (cur >= 360.0) cur -= 360.0;
            a = cos(pi*cur/180.0);
            b = sin(pi*cur/180.0);
            c = a-b;
            d = a+b;
            if (a < 0.0)    a0 = true;
            if (a > 0.0)    a1 = true;
            if (b < 0.0)    b0 = true;
            if (b > 0.0)    b1 = true;
            if (c < 0.0)    c0 = true;
            if (c > 0.0)    c1 = true;
            if (d < 0.0)    d0 = true;
            if (d > 0.0)    d1 = true;
        }
        if ((a0 == a1) && (b0 == b1) && (c0 == c1) && (d0 == d1)) printf("Yes\n");
        else printf("No\n");
    }
}
