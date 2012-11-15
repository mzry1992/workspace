#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-8;
int n,k;
struct point
{
    int x,y;
}p[6000];
int d[12000];

int cross(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int Distance(point p1,point p2)
{
    return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
}

bool cmp(const point & p1,const point & p2)                                                                                       //¼«½ÇÅÅÐòº¯Êý
{
     int temp;
     temp=cross(p[0],p1,p2);
     if(temp>0)
        return true;
     else if(temp==0&&Distance(p[0],p1)<Distance(p[0],p2))
        return true;
     return false;
}

double getarea(point a,point b,int r)
{
    double temp = (double)(a.x*b.x+a.y*b.y);
    temp = temp/(sqrt((double)Distance(p[0],a))*sqrt((double)Distance(p[0],b)));
    if (cross(p[0],a,b) >= 0)
        temp = (sqrt((double)r)*sqrt((double)r)*acos(temp))/2.0;
    else
        temp = (sqrt((double)r)*sqrt((double)r)*(2*acos(-1.0)-acos(temp)))/2.0;
    return temp;
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&k);
        if ((n == 0) && (k == 0))   break;
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        if (k == 0 || k == 1)
        {
            ft++;
            printf("Case #%d: %.2lf\n",ft,0.0);
        };
        p[0].x = 0;
        p[0].y = 0;
        sort(p+1,p+n+1,cmp);
        //cout << "----------------" << endl;
        //for (int i = 1;i <= n;i++)
        //    cout << p[i].x << ' ' << p[i].y << endl;
        double ans = 1e300;
        for (int i = 1;i <= n;i++)
        {
            int dis = Distance(p[0],p[i]);
            int cnt;
            cnt = 0;
            for (int j = 1;j <= n;j++)
                if (Distance(p[0],p[j]) <= dis)
                {
                    cnt++;
                    d[cnt] = j;
                }
            for (int j = 1;j <= cnt;j++)
                d[cnt+j] = d[j];
            cnt *= 2;
            for (int j = 1;j <= cnt-k+1;j++)
            {
                if (j+k-1 > cnt/2)
                    if (d[j] <= d[j+k-1])
                        break;
                double tans = getarea(p[d[j]],p[d[j+k-1]],dis);
                //if (tans == 0)
                //{
                    //cout << tans << ' ' << j << ' '<< j+k-1 << ' ' << d[j] << ' ' << d[j+k-1] << ' ' << p[d[j]].x << ' ' << p[d[j]].y << ' ' << p[d[j+k-1]].x << ' ' << p[d[j+k-1]].y << endl;
                    //for (int q = 1;q <= cnt;q++)
                    //    cout << d[q] << ' ';
                    //cout << endl;
                //}
                if (ans > tans+EPS)
                    ans = tans;
            }
        }
        ft++;
        printf("Case #%d: %.2lf\n",ft,ans);
    }
}
