#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXV = 1000;
const double eps = 1e-8;

struct pt
{
    double x, y, z;
    pt() {}
    pt(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
    pt operator - (const pt p1)
    {
        return pt(x - p1.x, y - p1.y, z - p1.z);
    }
    pt operator * (pt p)
    {
        return pt(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);
    }
    double operator ^ (pt p)
    {
        return x*p.x+y*p.y+z*p.z;
    }
};
struct _3DCH
{
    struct fac
    {
        int a, b, c;
        bool ok;
    };
    int n;
    pt P[MAXV];
    int cnt;
    fac F[MAXV*8];
    int to[MAXV][MAXV];

    double vlen(pt a)
    {
        return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    }

    double area(pt a, pt b, pt c)
    {
        return vlen((b-a)*(c-a));
    }

    double volume(pt a, pt b, pt c, pt d)
    {
        return (b-a)*(c-a)^(d-a);
    }

    double ptof(pt &p, fac &f)
    {
        pt m = P[f.b]-P[f.a], n = P[f.c]-P[f.a], t = p-P[f.a];
        return (m * n) ^ t;
    }

    void deal(int p, int a, int b)
    {
        int f = to[a][b];
        fac add;
        if (F[f].ok)
        {
            if (ptof(P[p], F[f]) > eps)
                dfs(p, f);
            else
            {
                add.a = b, add.b = a, add.c = p, add.ok = 1;
                to[p][b] = to[a][p] = to[b][a] = cnt;
                F[cnt++] = add;
            }
        }
    }

    void dfs(int p, int cur)
    {
        F[cur].ok = 0;
        deal(p, F[cur].b, F[cur].a);
        deal(p, F[cur].c, F[cur].b);
        deal(p, F[cur].a, F[cur].c);
    }

    bool same(int s, int t)
    {
        pt &a = P[F[s].a], &b = P[F[s].b], &c = P[F[s].c];
        return fabs(volume(a, b, c, P[F[t].a])) < eps &&
               fabs(volume(a, b, c, P[F[t].b])) < eps &&
               fabs(volume(a, b, c, P[F[t].c])) < eps;
    }

    void construct()
    {
        cnt = 0;
        if (n < 4)
            return;
        bool sb = 1;
        for (int i = 1; i < n; i++)
            if (vlen(P[0] - P[i]) > eps)
            {
                swap(P[1], P[i]);
                sb = 0;
                break;
            }
        if (sb)return;
        sb = 1;
        for (int i = 2; i < n; i++)
            if (vlen((P[0] - P[1]) * (P[1] - P[i])) > eps)
            {
                swap(P[2], P[i]);
                sb = 0;
                break;
            }
        if (sb)return;
        sb = 1;
        for (int i = 3; i < n; i++)
            if (fabs((P[0] - P[1]) * (P[1] - P[2]) ^ (P[0] - P[i])) > eps)
            {
                swap(P[3], P[i]);
                sb = 0;
                break;
            }
        if (sb)return;
        fac add;
        for (int i = 0; i < 4; i++)
        {
            add.a = (i+1)%4, add.b = (i+2)%4, add.c = (i+3)%4, add.ok = 1;
            if (ptof(P[i], add) > 0)
                swap(add.b, add.c);
            to[add.a][add.b] = to[add.b][add.c] = to[add.c][add.a] = cnt;
            F[cnt++] = add;
        }
        for (int i = 4; i < n; i++)
            for (int j = 0; j < cnt; j++)
                if (F[j].ok && ptof(P[i], F[j]) > eps)
                {
                    dfs(i, j);
                    break;
                }
        int tmp = cnt;
        cnt = 0;
        for (int i = 0; i < tmp; i++)
            if (F[i].ok)
                F[cnt++] = F[i];
    }

    double nearstpoint(pt a)
    {
        double res = 1e100;
        for (int i = 0;i < cnt;i++)
            res = min(res,volume(a,P[F[i].a],P[F[i].b],P[F[i].c])/area(P[F[i].a],P[F[i].b],P[F[i].c]));
        return res;
    }
};

_3DCH hull;

int main()
{
    while (true)
    {
        scanf("%d",&hull.n);
        if (hull.n == 0)    break;
        for (int i = 0;i < hull.n;i++)
            scanf("%lf%lf%lf",&hull.P[i].x,&hull.P[i].y,&hull.P[i].z);
        hull.construct();
        int q;
        scanf("%d",&q);
        for (int i = 0;i < q;i++)
        {
            pt p;
            scanf("%lf%lf%lf",&p.x,&p.y,&p.z);
            printf("%.4f\n",hull.nearstpoint(p));
        }
    }
    return 0;
}
