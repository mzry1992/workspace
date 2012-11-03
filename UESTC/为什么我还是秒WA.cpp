#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);
int n,k;
struct point
{
    int x,y;
}p[120000];
int d[100000];

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
        temp = (sqrt((double)r)*sqrt((double)r)*(2*PI-acos(temp)))/2.0;
    return temp;
}

int main()
{
    int ft = 0;
    freopen("out.txt","r",stdin);
    while (true)
    {
        scanf("%d%d",&n,&k);
        if (n == 0 && k == 0) break;
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        p[0].x = 0;
        p[0].y = 0;
        sort(p+1,p+n+1,cmp);
        for (int i = 1;i <= n;i++)
            p[n+i] = p[i];
        double ans = 1e300;
        for (int i = 1;i <= n;i++)
        {
            int dis = Distance(p[0],p[i]);
            int head,tail,cnt;
            head = 1;
            while (Distance(p[0],p[head]) > dis)
                head++;
            d[1] = head;
            tail = head+1;
            cnt = 1;
            while (cnt < k)
            {
                if (Distance(p[0],p[tail]) <= dis)
                {
                    cnt++;
                    d[cnt] = tail;
                }
                tail++;
            }
            int pre = 1;
            double tans = getarea(p[d[pre]],p[d[cnt]],dis);
            if (ans > tans+EPS)
                ans = tans;
            for (int j = tail+1;j <= 2*n;j++)
            {
                if (Distance(p[0],p[j]) <= dis)
                {
                    cnt++;
                    d[cnt] = j;
                    pre++;
                    tans = getarea(p[d[pre]],p[d[cnt]],dis);
                    if (ans > tans+EPS)
                        ans = tans;
                    if (d[cnt]-n == d[1])   break;
                }
            }
        }
        ft++;
        printf("Case #%d: %.2lf\n",ft,ans);
    }
}
