#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps 1e-8
struct P
{
    double x,y;
    P () {}
    P(double x,double y) :x(x),y(y) {}
    P operator - (const P & b)
    {
        return P(x-b.x,y-b.y);
    }
    double operator * (const P & b)
    {
        return x*b.y-y*b.x;
    }
    double operator & (const P & b)
    {
        return x*b.x+y*b.y;
    }
    double dorm()
    {
        return sqrt(x*x+y*y);
    }
} s,pt[10],c;
double r;
int sgn(double x)
{
    return x<-eps?-1:x>eps;
}
double cal(P t)
{
    double ans;
    for(int i=0; i<4; i++)
    {
        P a=pt[i],b=pt[i+1];
        int t1=sgn((t-a)&(b-a));
        int t2=sgn((t-b)&(a-b));
        double dis;
        if(t1*t2>0) dis=fabs((t-a)*(b-a))/(a-b).dorm();
        else dis=min((t-a).dorm(),(t-b).dorm());
        if(i==0||dis<ans) ans=dis;
    }
    return ans;
}
int main()
{
    while(scanf("%lf%lf",&s.x,&s.y)==2)
    {
        if(sgn(s.x)==0&&sgn(s.y)==0) break;
        scanf("%lf%lf%lf",&c.x,&c.y,&r);
        scanf("%lf%lf%lf%lf",&pt[0].x,&pt[0].y,&pt[2].x,&pt[2].y);
        pt[1].x=pt[0].x,pt[1].y=pt[2].y;
        pt[3].x=pt[2].x,pt[3].y=pt[0].y;
        pt[4]=pt[0];
        int time=10000;
        double ang=2*acos(-1.0)/time;
        double ans = 0.0;
        for(int i=0; i<time; i++)
        {
            P m=P(c.x+cos(ang*i)*r,c.y+sin(ang*i)*r);
            double dis=(m-s).dorm()+cal(m);
            if(i==0||dis<ans) ans=dis;
        }
        printf("%.2f\n",ans);
    }
}
