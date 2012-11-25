#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    long long x,y;
};

Point p[200000],c;
int n,q;
long long res;
bool flag;

long long xmult(Point a,Point b,Point c,Point d)
{
    return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = n-1;i >= 0;i--)
        {
            //I64d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
            p[i+n] = p[i];
        }
        scanf("%d",&q);
        for (int i = 0;i < q;i++)
        {
            //I64d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            scanf("%I64d%I64d",&c.x,&c.y);
            flag = true;
            for (int j = 0;j < n;j++)
                if (xmult(p[j],p[(j+1)%n],p[j],c) < 0)
                {
                    flag = false;
                    break;
                }
            if (flag == false)
            {
                printf("0\n");
                continue;
            }
            res = (long long)n*(n-1)*(n-2)/6;
            for (int j = 0,k = 2;j < n;j++)
            {
                while (xmult(p[j],c,p[j],p[k]) < 0)
                    k = k++;
                res -= (long long)(k-1-j)*(k-2-j)/2;
            }
            cout << res << endl;
        }
    }
    return 0;
}
