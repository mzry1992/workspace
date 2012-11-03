#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-7;
double x,y,r,a[3],b[3],c[3],d[3],p[3][3],q[3],ta,tb,tc;
int m,ma;
double xa,ya,ra;

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
    for (int ft = 1;ft <= t;ft++)
    {
        for (int i = 0;i < 3;i++)
        {
            scanf("%lf%lf%lf%d",&x,&y,&r,&m);
            if (i == 0)
            {
                xa = x;
                ya = y;
                ra = r;
                ma = m;
            }
            a[i] = -2*x;
            b[i] = -2*y;
            c[i] = 2*r;
            d[i] = x*x+y*y-r*r;
            if (m == 1) c[i] = -c[i];
        }
        for (int i = 0;i < 3;i++)
        {
            p[i][0] = (a[i]-a[(i+1)%3]);
            p[i][1] = (b[i]-b[(i+1)%3]);
            p[i][2] = (c[i]-c[(i+1)%3]);
            q[i] = d[(i+1)%3]-d[i];
        }
        for (int i = 0;i < 3;i++)
        {
            if (cmp(p[i][i],0.0) == 0)
            {
                for (int j = i+1;j < 3;j++)
                    if (cmp(p[j][i],0.0) != 0)
                    {
                        for (int k = 0;k < 3;k++)
                            swap(p[i][k],p[j][k]);
                        swap(q[i],q[j]);
                        break;
                    }
            }
            if (cmp(p[i][i],0.0) == 0)
                continue;
            for (int j = 0;j < 3;j++)
                if (i != j)
                {
                    double tmp = p[j][i]/p[i][i];
                    for (int k = i;k < 3;k++)
                        p[j][k] = p[j][k]-p[i][k]*tmp;
                    q[j] = q[j]-q[i]*tmp;
                }
        }
        if (cmp(p[2][2],0.0) != 0)
        {
            r = q[2]/p[2][2];
            if (cmp(r,0.0) < 0)
                printf("NO SOLUTION!\n");
            else
            {
                if (cmp(p[0][0],0.0) == 0)
                {
                    if (cmp(p[1][1],0.0) == 0)
                        printf("NO SOLUTION!\n");
                    else
                    {
                        y = q[1]/p[1][1];
                        x = (r+((ma == 0)?-1.0:1.0)*ra)*(r+((ma == 0)?-1.0:1.0)*ra)
                            -(y-ya)*(y-ya);
                        if (cmp(x,0.0) < 0)
                            printf("NO SOLUTION!\n");
                        else
                        {
                            x = sqrt(x)+xa;
                            if (cmp(r,0.0) != 0)
                                printf("%.4f %.4f %.4f\n",x,y,r);
                            else
                                printf("%.4f %.4f\n",x,y);
                        }
                    }
                }
                else if (cmp(p[1][1],0.0) == 0)
                {
                    if (cmp(p[0][0],0.0) == 0)
                        printf("NO SOLUTION!\n");
                    else
                    {
                        x = q[0]/p[0][0];
                        y = (r+((ma == 0)?-1.0:1.0)*ra)*(r+((ma == 0)?-1.0:1.0)*ra)
                            -(x-xa)*(x-xa);
                        if (cmp(y,0.0) < 0)
                            printf("NO SOLUTION!\n");
                        else
                        {
                            y = sqrt(y)+ya;
                            if (cmp(r,0.0) != 0)
                                printf("%.4f %.4f %.4f\n",x,y,r);
                            else
                                printf("%.4f %.4f\n",x,y);
                        }
                    }
                }
                else
                {
                    x = q[0]/p[0][0];
                    y = q[1]/p[1][1];
                    if (cmp(r,0.0) != 0)
                        printf("%.4f %.4f %.4f\n",x,y,r);
                    else
                        printf("%.4f %.4f\n",x,y);
                }
            }
        }
        else
        {
            if (cmp(q[2],0.0) != 0)
                printf("NO SOLUTION!\n");
            else
            {
                ta = (p[0][2]/p[0][0])*(p[0][2]/p[0][0])+(p[1][2]/p[1][1])*(p[1][2]/p[1][1])-1.0;
                tb = -2*q[0]*p[0][2]/(p[0][0]*p[0][0])-2*q[1]*p[1][2]/(p[1][1]*p[1][1])-a[0]*p[0][2]/p[0][0]-b[0]*p[1][2]/p[1][1]+c[0];
                tc = (q[0]/p[0][0])*(q[0]/p[0][0])+(q[1]/p[1][1])*(q[1]/p[1][1])+a[0]*q[0]/p[0][0]+b[0]*q[1]/p[1][1]+d[0];
                if (cmp(tb*tb-4*ta*tc,0.0) < 0)
                    printf("NO SOLUTION!\n");
                else
                {
                    r = (-tb+sqrt(tb*tb-4*ta*tc))/(2.0*ta);
                    x = (q[0]-p[0][2]*r)/p[0][0];
                    y = (q[1]-p[1][2]*r)/p[1][1];
                    if (cmp(r,0.0) < 0)
                        printf("NO SOLUTION!\n");
                    else if (cmp(r,0.0) != 0)
                        printf("%.4f %.4f %.4f\n",x,y,r);
                    else
                        printf("%.4f %.4f\n",x,y);
                }
            }
        }
    }
    return 0;
}
