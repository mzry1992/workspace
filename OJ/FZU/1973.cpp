#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
        return Point (x - b.x, y - b.y);
    }
    long long operator *( const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    long long operator &( const Point &b) const
    {
        return x * b.x + y * b.y;
    }
};

Point p[1000], tp[2000], base;

bool cmp(const Point &a, const Point &b)
{
	return a.theta < b.theta;
}

int cnt[1000][1000];
int cntleft[1000][1000];
int n, m;

int calc(int a, int b, int c)
{
    Point p1 = p[b] - p[a], p2 = p[c] - p[a];
    if (atan2(p1.y, p1.x) > atan2(p2.y, p2.x))
        swap(b, c);
    if ((p[b] - p[a]) * (p[c] - p[a]) > 0)
        return cnt[a][c] - cnt[a][b] - 1;
    else
        return n - 3 - (cnt[a][c] - cnt[a][b] - 1);
}

int main(int argc, char const *argv[])
{
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; ++cas)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld%lld", &p[i].x, &p[i].y);
            p[i].id = i;
        }
        for (int i = 0; i < n; ++i)
        {
            m = 0;
            base = p[i];
            for (int j = 0; j < n; ++j)
                if (i != j)
                {
                    tp[m] = p[j];
                    Point v = tp[m]-base;
                    tp[m++].theta = atan2(v.y,v.x);
                }

            sort(tp, tp + m, cmp);
            for (int j = 0; j < m; ++j)
                tp[m + j] = tp[j];

            //calc cnt
            for (int j = 0; j < m; ++j)
                cnt[i][tp[j].id] = j;

            //calc cntleft
            for (int j = 0, k = 0, tot = 0; j < m; ++j)
            {
                while (k == j || (k < j + m && (tp[j] - base) * (tp[k] - base) > 0))
                    k++, tot++;
                cntleft[i][tp[j].id] = --tot;
            }
        }

        printf("Case %d:\n", cas);
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; ++i)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if ((p[z] - p[x]) * (p[y] - p[x]) > 0)
                swap(y, z);
            int res = cntleft[x][z] + cntleft[z][y] + cntleft[y][x];
            res += calc(x, y, z) + calc(y, z, x) + calc(z, x, y);
            res -= 2 * (n - 3);
            printf("%d\n", res);
        }
    }
    return 0;
}