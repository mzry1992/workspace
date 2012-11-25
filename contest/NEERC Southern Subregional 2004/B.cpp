#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-12;
struct Point
{
    double x , y ;
    Point () {}
    Point ( double _x , double _y )
    {
        x = _x , y = _y ;
    }
    Point operator -( const Point & b ) const
    {
        return Point ( x - b .x , y - b . y ) ;
    }
    double operator *( const Point & b ) const
    {
        return x * b . y - y * b . x ;
    }
    double operator &( const Point & b ) const
    {
        return x * b . x + y * b . y ;
    }
};
bool GScmp ( Point a , Point b )
{
    if ( fabs ( a . x - b . x ) < eps )
        return a . y < b . y - eps ;
    return a . x < b . x - eps ;
}
void GS ( Point p [] , int n , Point res [] , int & resn )
{
    resn = 0;
    int top = 0;
    sort (p , p + n , GScmp ) ;
    for ( int i = 0; i < n ;)
        if ( resn < 2 || ( res [ resn - 1] - res [ resn - 2]) * ( p [ i ] - res [ resn -
                1]) > eps )
            res [ resn ++] = p [ i ++];
        else
            -- resn ;
    top = resn - 1;
    for ( int i = n - 2; i >= 0;)
        if ( resn < top + 2 || ( res [ resn - 1] - res [ resn - 2]) * ( p [ i ] - res [
                    resn - 1]) > eps )
            res [ resn ++] = p [i --];
        else
            -- resn ;
    resn --;
    if ( resn < 3)
        resn = 0;
}

double CalcArea ( Point p [] , int n )
{
    double res = 0;
    for ( int i = 0; i < n ; i ++)
        res += ( p [ i ] * p [( i + 1) % n ]) / 2;
    return res ;
}

int n,m,pn;
Point tp[4],p[4],a,b;
pair<double,double> area[1000];

bool cmpa(pair<double,double> a,pair<double,double> b)
{
    if (fabs(a.first-b.first) < eps)
        return a.second < b.second;
    return a.first > b.first;
}

bool cmpb(pair<double,double> a,pair<double,double> b)
{
    if (fabs(a.first-b.first) < eps)
        return a.second > b.second;
    return a.first > b.first;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
                scanf("%lf%lf",&tp[j].x,&tp[j].y);
            GS(tp,4,p,pn);

            Point mid = Point((p[0].x+p[2].x)/2,(p[0].y+p[2].y)/2);

            scanf("%lf%lf",&a.x,&a.y);
            scanf("%lf%lf",&b.x,&b.y);

            area[i].first = CalcArea(p,4);
            if (fabs((a-mid)*(b-mid)) < eps && ((a-mid)&(b-mid)) > -eps)
                area[i].second = 0;
            else
                area[i].second = CalcArea(p,4);

            //printf("%.3f %.3f\n",area[i].first,area[i].second);
        }
//        for (int i = 0;i < n;i++)
//            printf("%.3f ",area[i]);
//        printf("\n");

        sort(area,area+n,cmpa);
        double ansa = 0;
        for (int i = 0;i < m;i++)
            ansa += area[i].second;

        sort(area,area+n,cmpb);
        double ansb = 0;
        for (int i = 0;i < m;i++)
            ansb += area[i].second;

        ansa /= 2;
        ansb /= 2;
        printf("%.3f %.3f\n",ansa,ansb);
    }
    return 0;
}

