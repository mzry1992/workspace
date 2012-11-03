#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
int n,pre;
double v,l[5000],r[5000],mid[5000],h[5000],res;
bool full[5000];

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

void Calc(int pre,int now,double hi,double &area,double &len)
{
    double x,y,tx;
    area = 0.0,len = 0.0;
    for (int i = pre; i < now; i++)
    {
        y = (r[i]-l[i+1])/((r[i]-mid[i])/h[i]+(mid[i+1]-l[i+1])/h[i+1]);
        x = l[i+1]+y*(mid[i+1]-l[i+1])/h[i+1];
        if (cmp(h[i],hi) > 0)
        {
            tx = (h[i]-hi)*(r[i]-mid[i])/h[i]+mid[i];
            area += (hi-y)*(x-tx)/2;
        }
        else
            area += (hi-h[i]+hi-y)*(x-mid[i])/2;

        if (cmp(h[i+1],hi) > 0)
        {
            tx = mid[i+1]-(mid[i+1]-l[i+1])*(h[i+1]-hi)/h[i+1];
            area += (hi-y)*(tx-x)/2;
        }
        else
            area += (hi-y+hi-h[i+1])*(mid[i+1]-x)/2;
    }
    len = mid[now]-mid[pre];
}

double area,len;
struct valley
{
    int s,e;
    double area,len,ready;
    valley() {}
    valley(int _s,int _e,double _area,double _len)
    {
        s = _s;
        e = _e;
        area = _area;
        len = _len;
        ready = 0;
    }
    friend bool operator < (const valley& a,const valley& b)
    {
        return a.s < b.s;
    }
};

valley a[5000];
int tota;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%lf",&n,&v);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf",&l[i],&r[i],&h[i]);
        for (int i = 0; i < n; i++)
            mid[i] = (l[i]+r[i])/2;
        pre = 0;
        tota = 0;
        for (int i = 1; i < n; i++)
            if (cmp(l[i],r[i-1]) > 0)
                pre = i;
            else if (cmp(h[pre],h[i]) <= 0)
            {
                Calc(pre,i,h[pre],area,len);
                a[tota++] = valley(pre,i,area,len);
                pre = i;
            }
        pre = n-1;
        for (int i = n-2; i >= 0; i--)
            if (cmp(r[i],l[i+1]) < 0)
                pre = i;
            else if (cmp(h[pre],h[i]) <= 0)
            {
                Calc(i,pre,h[pre],area,len);
                a[tota++] = valley(i,pre,area,len);
                pre = i;
            }
        sort(a,a+tota);
        res = 0;
        double mintim,nowtim;
        for (int i = 0;i < tota;i++)
            full[i] = false;
        for (int i = 0; i < tota; i++)
        {
            mintim = 1e100;
            for (int j = 0; j < tota; j++)
                if (cmp(a[j].area,a[j].ready) != 0)
                {
                    nowtim = (a[j].area-a[j].ready)/(a[j].len*v);
                    if (cmp(nowtim,mintim) < 0)
                        mintim = nowtim;
                }
            res += mintim;
            for (int j = 0; j < tota; j++)
                if (cmp(a[j].area,a[j].ready) != 0)
                    a[j].ready += a[j].len*v*mintim;
            for (int j = 0; j < tota; j++)
                if (full[j] == false && cmp(a[j].area,a[j].ready) == 0)
                {
                    full[j] = true;
                    if (cmp(h[a[j].s],h[a[j].e]) > 0)
                    {
                        if (j+1 < tota)
                            a[j+1].len += a[j].len;
                    }
                    else if (j > 0)
                        a[j-1].len += a[j].len;
                }
        }
        printf("%.3f\n",res);
    }
    return 0;
}
