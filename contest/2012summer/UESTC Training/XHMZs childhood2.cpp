#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int MaxN = 505;
const double eps = 1e-8;

int sgn(double x)
{
    return x < -eps ? -1 : x > eps;
}

struct P
{
    double x, y;
    P() { }
    P(double x, double y) : x(x), y(y) { }
    P operator+(const P &p) const
    {
        return P(x + p.x, y + p.y);
    }
    P operator-(const P &p) const
    {
        return P(x - p.x, y - p.y);
    }
    P operator*(const double &d) const
    {
        return P(x * d, y * d);
    }
    P operator/(const double &d) const
    {
        return P(x / d, y / d);
    }
    double operator*(const P &p) const
    {
        return x * p.y - y * p.x;
    }
    double norm()
    {
        return hypot(x, y);
    }
    void init()
    {
        scanf("%lf%lf", &x, &y);
    }
} lhs[MaxN], rhs[MaxN], p[MaxN], tmp[MaxN];
const P O = P(0, 0);
int N, M, top, tp;

double getA(P *p, int N)
{
    double ret = 0;
    p[N] = p[0];
    for (int i = 0; i < N; i++)
    {
        ret += p[i] * p[i + 1];
    }
    if (sgn(ret) < 0)
    {
        reverse(p, p + N);
        ret = -ret;
    }
    p[N] = p[0];
    return ret;
}

P sol(const P *poly, int N)
{
    P p, p0, p1, p2, p3;
    double m, m0;
    p1 = poly[0], p2 = poly[1];
    p.x = p.y = m = 0;
    for (int i = 2; i < N; i++)
    {
        p3 = poly[i];
        p0 = (p1 + p2 + p3) / 3.0;
        m0 = p1 * p2 + p2 * p3 + p3 * p1;
        if (!sgn(m + m0)) m0 += eps;
        p = (p * m + p0 * m0) / (m + m0);
        m += m0;
        p2 = p3;
    }
    return p;
}

P ins_point(const P &a, const P &b, const P &c, const P &d)
{
    double u = (b - a) * (c - a);
    double v = (a - b) * (d - b);
    return (c * v + d * u) / (u + v);
}

void cut(const P &A, const P &B)
{
    p[top] = p[0];
    tp = 0;
    for (int i = 0; i < top; i++)
    {
        int rel1 = sgn((B - A) * (p[i] - A));
        int rel2 = sgn((B - A) * (p[i + 1] - A));
        if (rel1 >= 0)
        {
            if (rel2 >= 0)
            {
                tmp[tp++] = p[i];
            }
            else
            {
                tmp[tp++] = p[i];
                tmp[tp++] = ins_point(p[i], p[i + 1], A, B);
            }
        }
        else if (rel2 > 0)
        {
            tmp[tp++] = ins_point(p[i], p[i + 1], A, B);
        }
    }
    top = tp;
    for (int i = 0; i < top; i++)
        p[i] = tmp[i];
}

pair<double, P> triangle(P A, P B, P C, P D)
{
    double rel = 1.0;
    int rel1 = sgn(A * B), rel2 = sgn(C * D);
    rel *= rel1 * rel2;
    if (rel1 < 0) swap(A, B);
    if (rel2 < 0) swap(C, D);
    top = 0;
    p[top++] = P(0, 0);
    p[top++] = A;
    p[top++] = B;
    cut(O, C);
    cut(C, D);
    cut(D, O);
    double res = 0;
    p[top] = p[0];
    for (int i = 0; i < top; i++)
        res += p[i] * p[i + 1];
    return make_pair(rel * res, sol(p, top));
}

int main()
{
    int T, cas = 1;

    //freopen("test.in", "r", stdin);
    //freopen("fish.out", "w", stdout);

    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            lhs[i].init();
        for (int i = 0; i < M; i++)
            rhs[i].init();
        double s1 = getA(lhs, N), s2 = getA(rhs, M);
        P pL = sol(lhs, N);
        P pR = sol(rhs, M);
        P p = (pL * s1 + pR * s2) / (s1 + s2);
        P p0;
        double m = s1 + s2, m0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                pair<double, P> pr = triangle(lhs[i], lhs[i + 1], rhs[j], rhs[j + 1]);
                m0 = -pr.first;
                p0 = pr.second;
                if (!sgn(m + m0)) m0 += eps;
                p = (p * m + p0 * m0) / (m + m0);
                m += m0;
            }
        }
        printf("Case #%d: %.3f %.3f\n", cas++, p.x, p.y);
    }

    return 0;
}

