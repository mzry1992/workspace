#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    int x,y,typ,val;
};

struct Event
{
    double theta;
    int typ,val;
    Event(){}
    Event(double _theta,int _typ,int _val)
    {
        theta = _theta;
        typ = _typ;
        val = _val;
    }
    bool operator < (const Event& b)const
    {
        return cmp(theta,b.theta) < 0;
    }
};

Point p[2000];
Event e[4000];
int n,m,res;
int l,r,sum[2],tot[2];

int main()
{
    //printf("%.12f %.12f\n",atan2(100000,100000),atan2(100000+1,100000));
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        res = tot[0] = tot[1] = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].val);
            p[i].typ = 0;
            tot[0] += p[i].val;
        }
        for (int i = n;i < n+m;i++)
        {
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].val);
            p[i].typ = 1;
            tot[1] += p[i].val;
        }
        res = min(tot[0],tot[1]);
        n = n+m;
        for (int i = 0;i < n;i++)
        {
            m = 0;
            for (int j = 0;j < n;j++)
                if (i != j)
                    e[m++] = Event(atan2(p[j].y-p[i].y,p[j].x-p[i].x),p[j].typ,p[j].val);
            sort(e,e+m);
            /*printf("p = (%d,%d)\n",p[i].x,p[i].y);
            for (int j = 0;j < m;j++)
                printf("(%.4f,%d,%d) ",e[j].theta,e[j].typ,e[j].val);
            printf("\n");*/
            for (int j = 0;j < m;j++)
                e[m+j] = Event(e[j].theta+2*pi,e[j].typ,e[j].val);
            l = r = sum[0] = sum[1] = 0;
            while (l < m)
            {
                while (cmp(e[l].theta+pi,e[r].theta) > 0)
                {
                    //printf("%.6f %.6f\n",e[l].theta+pi,e[r].theta);
                    sum[e[r].typ] += e[r].val;
                    r++;
                }
                //printf("l = %d, r = %d, sum[0] = %d, sum[1] = %d\n",l,r,sum[0],sum[1]);
                //printf("res = %d\n",sum[0]+tot[1]-sum[1]);
                res = min(res,sum[0]+tot[1]-sum[1]);
                double tmp = e[l].theta;
                while (cmp(e[l].theta,tmp) == 0)
                {
                    sum[e[l].typ] -= e[l].val;
                    l++;
                }
            }
        }
        printf("%d\n",res);
    }
	return 0;
}
