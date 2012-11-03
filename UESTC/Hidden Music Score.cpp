#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct point
{
    double x,y;
}p[30];
int n;
char ch1,ch2;

int getleve(char c)
{
    if (c >= 'C') return c-'C';
    return c-'A'+5;
}

double dist(point a,point b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

point Rotate(point p, double a,double b)
{
    point result;
    double sina = a/b;
    double cosa = sqrt(1-a*a/(b*b));
    result.x = p.x * cosa - p.y * sina;
    result.y = p.x * sina + p.y * cosa;
    return result;
}

double disttoline(point p,point a,point v)
{
    double A = v.y;
    double B = -v.x;
    double C = v.x*a.y-v.y*a.x;
    return ((A*p.x+B*p.y+C)/sqrt(A*A+B*B));
}

char charleve(int i)
{
    if (i <= 4) return 'C'+i;
    return 'A'+i-5;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf(" %c %c",&ch1,&ch2);
        for (int i = 1;i <= n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for (int i = 2;i <= n-1;i++)
        {
            double angle = asin(((getleve(ch2)-getleve(ch1))*0.5)/dist(p[i-1],p[n]));
            point line;
            line.x = p[n].x-p[i-1].x;
            line.y = p[n].y-p[i-1].y;
            //cout << ((getleve(ch2)-getleve(ch1))*0.5) << ' ' << dist(p[1],p[n]) << ' ' << line.x << ' ' << line.y << ' ';
            line = Rotate(line,((getleve(ch2)-getleve(ch1))*0.5),dist(p[i-1],p[n]));
            //printf("%c",ch1);
            double tdist = disttoline(p[i],p[i-1],line);
            cout << tdist << ' ' << ((int)(tdist/0.5)) << endl;
            //printf("%c",charleve(getleve(ch1)+(int)(tdist/0.5)));
        }
            //printf("%c\n",ch2);
    }
}
