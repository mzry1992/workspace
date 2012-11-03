#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Point
{
    friend bool operator < (const Point& a,const Point& b)
    {
        if (a.y == b.y)  return a.x < b.x;
        return a.y < b.y;
    }
    int x,y;
};

Point p[1000],tp[1000];
int n,R,x[1000],totx,totp;

int main()
{
    while (scanf("%d%d",&n,&R) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            x[i] = p[i].x;
        }
        sort(x,x+n);
        totx = unique(x,x+n)-x;
        sort(p,p+n);
        int res = 0,l,r,u,tot;
        for (int i = 0;i < totx;i++)
        {
            l = x[i];
            r = l+R;
            totp = 0;
            for (int j = 0;j < n;j++)
                if (p[j].x >= l && p[j].x <= r)
                    tp[totp++] = p[j];
            tot = u = 0;
            for (int j = 0;j < totp;j++)
            {
                while (true)
                {
                    if (u == totp)  break;
                    if (tp[u].y > tp[j].y+R)    break;
                    u++;
                    tot++;
                }
                res = max(res,tot);
                tot--;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
