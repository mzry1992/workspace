#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Point
{
    long long x, y;
    int id;
    double theta;
    Point () {}
    Point (long long _x , long long _y)
    {
        x = _x , y = _y;
    }
    Point operator -( const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    long long operator *( const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    long long operator &( const Point &b) const
    {
        return x * b.x + y * b.y;
    }
    long long getMol() const
    {
        return (*this)&(*this);
    }
};

int n,n0,n1,m;
Point p[3000], tp[3000], base;

bool cmp(const Point &a, const Point &b)
{
    //while (fabs(a.theta-b.theta) < 1e-10)   puts("fff");
    //while ((a-base)*(b-base) == 0) puts("fff");
    if ((a-base)*(b-base) == 0)
    {
        return (a-base).getMol() < (b-base).getMol();
    }
    return a.theta < b.theta;
}

int cnt[100][100];
int cntleft[100][100];

int calc(int a,int b,int c)
{
    Point p1 = p[b]-p[a],p2 = p[c]-p[a];
    if (atan2(1.0*p1.y,1.0*p1.x) > atan2(1.0*p2.y,1.0*p2.x))
        swap(b,c);
    int res = cnt[a][c]-cnt[a][b];
    if ((p[b]-p[a])*(p[c]-p[a]) > 0)
        return res;
    else
        return n1-res;
}

int main()
{
    int cas = 0;
    while (scanf("%d%d",&n0,&n1) != EOF)
    {
        n = n1+n0;
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
            p[i].id = i;
        }
        for (int i = 0; i < n0; ++i)
        {
            m = 0;
            base = p[i];
            for (int j = 0; j < n; ++j)
                if (i != j)
                {
                    tp[m] = p[j];
                    Point v = tp[m]-base;
                    tp[m++].theta = atan2(1.0*v.y,1.0*v.x);
                }

            sort(tp, tp + m, cmp);
            for (int j = 0; j < m; ++j)
                tp[m + j] = tp[j];

            for (int j = 0,tot = 0; j < m; ++j)
            {
                if (tp[j].id < n0)
                    cnt[i][tp[j].id] = tot;
                else
                    tot++;
            }

            for (int j = 0, k = 0, tot = 0; j < m; ++j)
            {
                while (k == j || (k < j + m && (tp[j] - base) * (tp[k] - base) > 0))
                {
                    if (tp[k].id >= n0)
                        tot++;
                    k++;
                }
                if (tp[j].id >= n0)
                    tot--;
                else
                    cntleft[i][tp[j].id] = tot;
            }
        }

//        for (int i = 0;i < n;i++)
//        {
//            for (int j = 0;j < n;j++)
//                printf("%d %d cnt = %d, cntleft = %d\n",i,j,cnt[i][j],cntleft[i][j]);
//        }

        int ans = 0;
        for (int i = 0; i < n0; i++)
            for (int j = i+1; j < n0; j++)
                for (int k = j+1; k < n0; k++)
                {
                    int x = i,y = j,z = k;

                    if ((p[z] - p[x]) * (p[y] - p[x]) > 0)
                        swap(y, z);
                    int res = cntleft[x][z] + cntleft[z][y] + cntleft[y][x];

                    res += calc(x, y, z) + calc(y, z, x) + calc(z, x, y);

                    res -= 2 * n1;

                    //printf("%d %d %d %d\n",x,y,z,res);

                    if (res%2 == 1)
                        ans++;
                }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
