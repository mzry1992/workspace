#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double r;
int n;
int tot;
struct point
{
    double x,y;
}c,p,v;

bool intersect()
{
    double A,B,C;
    A = v.y; B = -v.x; C = v.x*p.y-v.y*p.x;
    if (fabs(A*c.x+B*c.y+C)/sqrt(A*A+B*B) <= r)
        return true;
    return false;
}

int main()
{
    freopen("给趣味赛出的题1的数据.txt","r",stdin);
    freopen("给趣味赛出的题1的数据myout.txt","w",stdout);
    int ft = 0;
    while (scanf("%lf%lf%lf",&c.x,&c.y,&r) != EOF)
    {
        scanf("%d",&n);
        tot = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lf%lf%lf%lf",&p.x,&p.y,&v.x,&v.y);
            if (intersect())
                tot++;
        }
        ft++;
        printf("Case #%d: %d\n",ft,tot);
    }
}
