#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

double x,y;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf",&x,&y);
        double ly,ry,mid,calc;
        ly = y;
        ry = 1e8;
        while (fabs(ry-ly) > 1e-7)
        {
            mid = (ry+ly)/2.0;
            calc = ((mid-y)*(mid-y)-x)*((mid-y)*(mid-y)-x)-mid;
            cout << mid << ' ' << calc << ' ' << x << ' ' << y << endl;
            if (calc > 0.0)
                ry = mid;
            else
                ly = mid;
        }
        mid = 0.0;
        calc = ((mid-y)*(mid-y)-x)*((mid-y)*(mid-y)-x)-mid;
        cout << calc << endl;
        cout << ly << endl;
    }
}
