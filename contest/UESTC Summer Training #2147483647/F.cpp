#include <cstdio>
#include <algorithm>
using namespace std;

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
};

Point pl[30000],pr[30000];
int cnt[30000];
int n,m,w,h,s;

int calc(int a)
{
    if (a < 0)  return 0;
    return ((pl[a].y+pr[a].y)*w);
}

int main()
{
    while (scanf("%d",&n),n)
    {
        scanf("%d%d%d%d",&m,&w,&h,&s);
        for (int i = 0;i < m;i++)
        {
            scanf("%lf%lf",&pl[i].y,&pr[i].y);
            pl[i].x = 0;
            pr[i].x = w;
            cnt[i] = 0;
        }
        for (int i = 0;i < n;i++)
        {
            Point p;
            scanf("%lf%lf",&p.x,&p.y);
            int l,r,mid;
            l = 0,r = m-1;
            while (l < r)
            {
                mid = l+r>>1;
                if ((p-pl[mid])*(pr[mid]-pl[mid]) > 0)
                    r = mid;
                else
                    l = mid+1;
            }
            cnt[l]++;
            //printf("l = %d\n",l);
        }
        int pre = -1,res = 0,tot = 0;
        for (int i = 0;i < m;i++)
        {
            tot += cnt[i];
            while (calc(i)-calc(pre) > (w*h-s)*2)
            {
                tot -= cnt[pre+1];
                pre++;
            }
            //printf("%d %d %d\n",i,pre,tot);
            res = max(res,tot);
        }
        printf("%d\n",n-res);
    }
    return 0;
}
