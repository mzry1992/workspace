#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y,z,r;
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
    void transYZ(double B)
    {
        double ty = y,tz = z;
        y = ty*cos(B) - tz*sin(B);
        z = ty*sin(B) + tz*cos(B);
    }
    void view()
    {
        printf("(%.3f, %.3f, %.3f, r = %.3f) ",x,y,z,r);
    }
    void viewln()
    {
        printf("(%.3f, %.3f, %.3f, r = %.3f)\n",x,y,z,r);
    }
};

double sqr(double x)
{
    return x*x;
}

Point sun,pa,pb,vz;
double theta;

int main()
{
    while (true)
    {
        scanf("%lf",&sun.x);
        if (cmp(sun.x,0) < 0)   break;
        scanf("%lf%lf%lf",&sun.y,&sun.z,&sun.r);
        scanf("%lf%lf%lf%lf",&pa.x,&pa.y,&pa.z,&pa.r);
        scanf("%lf%lf%lf%lf",&pb.x,&pb.y,&pb.z,&pb.r);
        //把sun搞到原点
        pa.x -= sun.x;
        pa.y -= sun.y;
        pa.z -= sun.z;
        pb.x -= sun.x;
        pb.y -= sun.y;
        pb.z -= sun.z;
        //把pa旋转到Z轴上面去
        theta = pi/2-atan2(pa.y,pa.x);
        pa.transXY(theta);
        pb.transXY(theta);
        theta = pi/2-atan2(pa.z,pa.y);
        pa.transYZ(theta);
        pb.transYZ(theta);
        if (cmp(pa.z,0) < 0)
        {
            pa.z = -pa.z;
            pb.z = -pb.z;
        }
        //把pb转到YOZ面上去
        theta = pi/2-atan2(pb.y,pb.x);
        pb.transXY(theta);
        if (cmp(pb.y,0) < 0)
            pb.y = -pb.y;
        //二维了= =
        //分类讨论？
        if (cmp(pb.z,pa.z) < 0)
            puts("No solar eclipse");
        else
        {
            double a,b,c,h0,ym,adjust;
            c = pa.z;
            b = fabs(pa.r-sun.r);
            a = sqrt(sqr(c)-sqr(b));
            h0 = sun.r*c/a;
            if (cmp(sun.r,pa.r) > 0)
                ym = h0-b*pb.z/a;
            else
                ym = h0+b*pb.z/a;
            adjust = pb.r*c/a;
            if (cmp(pb.y,ym-adjust) <= 0)
                puts("Entire total solar eclipse");
            else if (cmp(pb.y,ym+adjust) <= 0)
                puts("Part total solar eclipse");
            else
            {
                b = sun.r+pa.r;
                a = sqrt(sqr(c)-sqr(b));
                h0 = sun.r*c/a;
                ym = b*pb.z/a-h0;
                if (cmp(pb.y,ym-adjust) <= 0)
                    puts("Entire partial solar eclipse");
                else if (cmp(pb.y,ym+adjust) <= 0)
                    puts("Part partial solar eclipse");
                else
                    puts("No solar eclipse");
            }
        }
    }
    return 0;
}
