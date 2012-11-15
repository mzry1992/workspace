#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,x,y;
double f;
struct point
{
    double x,y;
    double angle;
}p[120];
const double pi = acos(-1.0);
const double eps = 1e-8;
point p0;

int xmultiply(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

double dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)*1.0+(p2.y-p1.y)*(p2.y-p1.y)*1.0);
}

int dmultiply(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

double getd(point a)
{
    double d0;
    double k1 = xmultiply(p0,a,p[0]);
    double k2 = dmultiply(p0,a,p[0]);
    double k3;
    double kk;
    kk = dis(p0,p[0])*dis(p0,a);
    k3 = 180*asin(k1/kk)/pi;
    if (k1 > -eps)
    {
        if (k2 > -eps)
            d0 = 180*asin(k1/kk)/pi;
        else
            d0 = 180-180*asin(k1/kk)/pi;
    }
    else
    {
        if (k2 > -eps)
            d0 = 360-180*asin(-k1/kk)/pi;
        else
            d0 = 180+180*asin(-k1/kk)/pi;
    }
    return d0;
}

bool cmp(point a,point b)
{
    if (a.angle == b.angle)
        return dis(p0,a) < dis(p0,b);
    return a.angle < b.angle;
}

int sum[240];
int dp[240];

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d%d%lf",&n,&x,&y,&f);
        if (n == 0 && x == 0 && y == 0 && f == 0)   break;
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p0.x = x;
        p0.y = y;
        for (int i = 0;i < n;i++)
            p[i].angle = getd(p[i]);
        sort(p+1,p+n,cmp);
        for (int i = 0;i < n;i++)
        {
            sum[i] = 1;
            int j = i+1;
            while (true)
            {
                j = j%n;
                if (j == i) break;
                double xa,xb,ya,yb;
                xa = p[j].x-x;
                ya = p[j].y-y;
                xb = p[i].x-x;
                yb = p[i].y-y;
                double mc;
                double mc1,mc2;
                mc = xa*xb+ya*yb;
                mc = mc/(sqrt(xa*xa+ya*ya)*sqrt(xb*xb+yb*yb));
                mc1 = 180*acos(mc)/pi;
                mc = xa*yb-ya*xb;
                mc = mc/(sqrt(xa*xa+ya*ya)*sqrt(xb*xb+yb*yb));
                mc2 = 180*asin(mc)/pi;
                if (mc2 < -eps)    break;
                if (mc1 > f+eps) break;
                sum[i]++;
                j++;
            }
        }
        int res = 19921005;
        for (int i = 0;i < n;i++)
            sum[i+n] = sum[i];
        for (int i = 0;i < n;i++)
        {
            int ans = 0;
            int j = i;
            while (true)
            {
                ans++;
                j = j+sum[j];
                if (j >= i+n)   break;
            }
            if (res > ans)  res = ans;
        }
        ft++;
        if (n == 0) res = 0;
        printf("Case %d: %d\n",ft,res);
    }
}
