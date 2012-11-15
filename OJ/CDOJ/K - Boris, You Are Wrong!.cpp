#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-10;
double xa,xb,xc,ya,yb,yc;
double x,y;
double k,tx;
bool flag;

int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc) != EOF)
    {
        flag = true;
        if (ya-yc == 0)
        {
            k = 0;
            y = yc;
            if ((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc)-(y-yb)*(y-yb) <= eps)
                flag = false;
            else
            {
                tx = sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc)-(y-yb)*(y-yb));
                if (fabs(tx+xb-xc) > eps)
                    x = tx+xb;
                else
                    x = xb-tx;
                flag = true;
            }
        }
        else
        {
            k = (xa-xc)/(ya-yc);
            double a,b,c,d;
            a = k*k+1;
            b = -k*k*2*yc+(xc-xb)*2*k-2*yb;
            c = k*k*yc*yc-(xc-xb)*2*k*yc+(xc-xb)*(xc-xb)+yb*yb-((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
            if (b*b-4*a*c <= eps)
                flag = false;
            else
            {
                d = sqrt(b*b-4*a*c);
                y = (-b+d)/(2*a);
                if (fabs(y-yc) <= eps)    y = (-b-d)/(2*a);
                x = k*(y-yc)+xc;
                flag = true;
            }
        }
        if (fabs(sqrt((x-xa)*(x-xa)+(y-ya)*(y-ya))+sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc))-sqrt((xc-x)*(xc-x)+(yc-y)*(yc-y))) < eps)
            flag = false;
        if (fabs(x-xa) < eps && fabs(y-ya) < eps)
            flag = false;
        if (fabs(x-xb) < eps && fabs(y-yb) < eps)
            flag = false;
        if (fabs(x-xc) < eps && fabs(y-yc) < eps)
            flag = false;
        if (flag == false)  printf("YES\n");
        else
        {
            printf("NO\n");
            printf("%.10f %.10f\n%.10f %.10f\n%.10f %.10f\n",xa,ya,xb,yb,x,y);
        }
    }
}
