#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "cmath"
using namespace std;

const double eps = 1e-6;

struct Point
{
    double x, y;
    double operator *(const Point &b)const
    {
        return x * b.y - y * b.x;
    }
    Point operator -(const Point &b)const
    {
        Point res;
        res.x = x - b.x;
        res.y = y - b.y;
        return res;
    }
};

struct Line
{
    Point s, e;
    double k;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
        k = atan2(e.y - s.y, e.x - s.x);
    }
    double operator *(const Line &b)const
    {
        return (e - s) * (b.e-b.s);
    }
    bool operator <(const Line &b)const
    {
        if (fabs(k - b.k) > eps)  return k < b.k;
        return (s - b.s) * (b.e-b.s) < 0;
    }
    Point operator &(const Line &b)const
    {
        Point res = s;
        double t = ((s - b.s) * (b.s - b.e)) / ((s - e) * (b.s - b.e));
        res.x += (e.x - s.x) * t;
        res.y += (e.y - s.y) * t;
        return res;
    }
};

Point ta[500], tb[500], a[500][3], b[500][3], res, p[10];
double w;
int tn, tm, n, m, pn;

double area(Point p[], int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += p[i] * p[(i + 1) % n];
    return res;
}

void convex(Point p[], int n)
{
    if (area(p, n) < 0)
        reverse(p, p + n);
}

bool check(Point a, Point b, Point c, Point d)
{
    return (b - a) * (d - a) > 0 && (d - a) * (c - a) > 0;
}

void split(Point p[], int n, Point res[][3], int &resn)
{
    resn = n - 2;
    for (int i = 0; i < resn; i++)
    {
        for (int j = 0; j < n; j++)
            if ((p[j] - p[(j - 1 + n) % n]) * (p[(j + 1) % n] - p[(j - 1 + n) % n]) >= 0)
            {
                bool flag = true;
                for (int k = 0; k < n; k++)
                    if (k != (j - 1 + n) % n && k != j && k != (j + 1) % n)
                        if (check(p[j], p[(j + 1) % n], p[(j - 1 + n) % n], p[k]) &&
                                check(p[(j + 1) % n], p[(j - 1 + n) % n], p[j], p[k]) &&
                                check(p[(j - 1 + n) % n], p[j], p[(j + 1) % n], p[k]))
                        {
                            flag = false;
                            break;
                        }
                if (flag)
                {
                    res[i][0] = p[(j - 1 + n) % n];
                    res[i][1] = p[j];
                    res[i][2] = p[(j + 1) % n];
                    int tn = 0;
                    for (int k = 0; k < n; k++)
                        if (k != j)
                            p[tn++] = p[k];
                    n = tn;
                    break;
                }
            }
    }
}

void merge(Point c, double m, Point &res, double &w)
{
    if (fabs(w + m) < eps)
        m += eps;
    res.x = (res.x * w + c.x * m) / (w + m);
    res.y = (res.y * w + c.y * m) / (w + m);
    w += m;
}

Point center(Point poly[], int n)
{
    Point p, p0, p1, p2, p3;
    double m, m0;
    p1 = poly[0], p2 = poly[1];
    p.x = p.y = m = 0;
    for (int i = 2; i < n; i++)
    {
        p3 = poly[i];
        p0.x = (p1.x + p2.x + p3.x) / 3.0;
        p0.y = (p1.y + p2.y + p3.y) / 3.0;
        m0 = p1 * p2 + p2 * p3 + p3 * p1;
        merge(p0, m0, p, m);
        p2 = p3;
    }
    return p;
}

void hpi(Point a[], Point b[], Point res[], int &resn)
{
    resn = 0;
    Line line[10], Q[10];
    int n = 0;
    for (int i = 0; i < 3; i++)
        line[n++] = Line(a[i], a[(i + 1) % 3]);
    for (int i = 0; i < 3; i++)
        line[n++] = Line(b[i], b[(i + 1) % 3]);
    sort(line, line + n);
    int tot = 1;
    for (int i = 1; i < n; i++)
        if ((line[i].k - line[i - 1].k) > eps)
            line[tot++] = line[i];
    int head, tail;
    head = 0, tail = 1;
    Q[0] = line[0], Q[1] = line[1];
    resn = 0;
    for (int i = 2; i < tot; i++)
    {
        if ((fabs(Q[tail]*Q[tail - 1]) < eps) || (fabs(Q[head]*Q[head + 1]) < eps)) return;
        while (head < tail && ((Q[tail]&Q[tail - 1]) - line[i].s) * (line[i].e-line[i].s) > eps)
            tail--;
        while (head < tail && ((Q[head]&Q[head + 1]) - line[i].s) * (line[i].e-line[i].s) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while (head < tail && ((Q[tail]&Q[tail - 1]) - line[head].s) * (line[head].e-line[head].s) > eps)
        tail--;
    while (head < tail && ((Q[head]&Q[head + 1]) - line[tail].s) * (line[tail].e-line[tail].s) > eps)
        head++;
    if (tail <= head + 1) return;
    for (int i = head; i < tail; i++)
        res[resn++] = Q[i] & Q[i + 1];
    if (head < tail + 1)
        res[resn++] = Q[head] & Q[tail];
}

int main(int argc, char const *argv[])
{
    freopen("data.in", "r", stdin);
    freopen("data2.out", "w", stdout);
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d", &tn, &tm);
        for (int i = 0; i < tn; i++)
            scanf("%lf%lf", &ta[i].x, &ta[i].y);
        for (int i = 0; i < tm; i++)
            scanf("%lf%lf", &tb[i].x, &tb[i].y);
        convex(ta, tn);
        convex(tb, tm);

        split(ta, tn, a, n);
        split(tb, tm, b, m);

        res.x = res.y = w = 0;
        for (int i = 0; i < n; i++)
            merge(center(a[i], 3), area(a[i], 3), res, w);
        for (int i = 0; i < m; i++)
            merge(center(b[i], 3), area(b[i], 3), res, w);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                hpi(a[i], b[j], p, pn);
                if (pn > 0)
                    merge(center(p, pn), -area(p, pn), res, w);
            }
        printf("Case #%d: %.3f %.3f\n", cas, res.x, res.y);
    }
    return 0;
}