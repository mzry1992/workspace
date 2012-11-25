#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstring"
#include "cmath"
using namespace std;

const double eps = 1e-12;

struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y)
    {
        x = _x, y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator *(const Point &b)const
    {
        return x * b.y - y * b.x;
    }
    double operator &(const Point &b)const
    {
        return x * b.x + y * b.y;
    }
};

struct Line
{
    Point s, e;
    double k;
    Line() {}
    Line(Point _s, Point _e)
    {
        s = _s, e = _e;
        k = atan2(e.y - s.y, e.x - s.x);
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

bool HPIcmp(Line a, Line b)
{
    if (fabs(a.k - b.k) > eps)    return a.k < b.k;
    return ((a.s - b.s) * (b.e-b.s)) < 0;
}

Line Q[100];
void HPI(Line line[], int n, Point res[], int &resn)
{
    int tot = n;
    sort(line, line + n, HPIcmp);
    tot = 1;
    for (int i = 1; i < n; i++)
        if (fabs(line[i].k - line[i - 1].k) > eps)
            line[tot++] = line[i];
    int head = 0, tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2; i < tot; i++)
    {
        if (fabs((Q[tail].e-Q[tail].s) * (Q[tail - 1].e-Q[tail - 1].s)) < eps ||
                fabs((Q[head].e-Q[head].s) * (Q[head + 1].e-Q[head + 1].s)) < eps)
            return;
        while (head < tail && (((Q[tail]&Q[tail - 1]) - line[i].s) * (line[i].e-line[i].s)) > eps)
            tail--;
        while (head < tail && (((Q[head]&Q[head + 1]) - line[i].s) * (line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while (head < tail && (((Q[tail]&Q[tail - 1]) - Q[head].s) * (Q[head].e-Q[head].s)) > eps)
        tail--;
    while (head < tail && (((Q[head]&Q[head + 1]) - Q[tail].s) * (Q[tail].e-Q[tail].s)) > eps)
        head++;
    if (tail <= head + 1) return;
    for (int i = head; i < tail; i++)
        res[resn++] = Q[i] & Q[i + 1];
    if (head < tail + 1)
        res[resn++] = Q[head] & Q[tail];
}

bool GScmp(Point a, Point b)
{
    if (fabs(a.x - b.x) < eps)
        return a.y < b.y - eps;
    return a.x < b.x - eps;
}

void GS(Point p[], int n, Point res[], int &resn)
{
    resn = 0;
    int top = 0;
    sort(p, p + n, GScmp);
    for (int i = 0; i < n;)
        if (resn < 2 || (res[resn - 1] - res[resn - 2]) * (p[i] - res[resn - 1]) > eps)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn - 1;
    for (int i = n - 2; i >= 0;)
        if (resn < top + 2 || (res[resn - 1] - res[resn - 2]) * (p[i] - res[resn - 1]) > eps)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

double CalcArea(Point p[], int n)
{
    double res = 0;
    for (int i = 0; i < n; i++)
        res += (p[i] * p[(i + 1) % n]) / 2;
    return res;
}

double dist2(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double dist2(Point p1, Point p2, Point p)
{
    Point res;
    double a, b, t;
    a = p2.x - p1.x;
    b = p2.y - p1.y;
    t = ((p.x - p1.x) * a + (p.y - p1.y) * b) / (a * a + b * b);
    if (t >= 0 && t <= 1)
    {
        res.x = p1.x + a * t;
        res.y = p1.y + b * t;
    }
    else
    {
        if (dist2(p, p1) < dist2(p, p2))
            res = p1;
        else
            res = p2;
    }
    return dist2(p, res);
}

double r0, r1;
int n, pn[30];
Point p[30][30], tp[30], vp[30];
Line line[100];

bool check1(Point a, Point b, double r)
{
    Point v = b-a;
    Point pv = Point(v.y, -v.x);
    double len = sqrt(dist2(Point(0, 0), pv));
    pv = Point(pv.x * r / len, pv.y * r / len);
    int tn = 0;
    tp[tn++] = Point(a.x + pv.x, a.y + pv.y);
    tp[tn++] = Point(a.x - pv.x, a.y - pv.y);
    tp[tn++] = Point(b.x + pv.x, b.y + pv.y);
    tp[tn++] = Point(b.x - pv.x, b.y - pv.y);
    int ttn = 0;
    GS(tp, tn, vp, ttn);
    for (int i = 0; i < n; i++)
    {
        int totline = 0;
        for (int j = 0; j < ttn; j++)
            line[totline++] = Line(vp[j], vp[(j + 1) % ttn]);
        for (int j = 0; j < pn[i]; j++)
            line[totline++] = Line(p[i][j], p[i][(j + 1) % pn[i]]);
        HPI(line, totline, tp, tn);
        if (CalcArea(tp, tn) > eps)  return false;
    }
    return true;
}

bool check2(Point a, double r)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < pn[i]; j++)
            if (dist2(p[i][j], p[i][(j + 1) % pn[i]], a) < r * r)
                return false;
    return true;
}

int main()
{
    while (true)
    {
        scanf("%lf%lf%d", &r0, &r1, &n);
        if (n == 0)
            break;
        for (int i = 0; i <= n; i++)
        {
            scanf("%d", &pn[i]);
            for (int j = 0; j < pn[i]; j++)
                scanf("%lf%lf", &tp[j].x, &tp[j].y);
            if (i < n)
            {
                int tn = pn[i];
                GS(tp, tn, p[i], pn[i]);
            }
            else
                for (int j = 0; j < pn[i]; j++)
                    p[i][j] = tp[j];
        }
        for (int i = 1; i < pn[n]; i++)
        {
            double l = 0, r = r1, mid;
            for (int tim = 0; tim < 100; tim++)
            {
                mid = (l + r) / 2;
                if (check1(p[n][i - 1], p[n][i], mid) && check2(p[n][i - 1], mid) && check2(p[n][i], mid))
                    l = mid;
                else
                    r = mid;
            }
            if (l < r0) l = 0;
            if (i > 1)
                printf(" ");
            printf("%.0f", round(l));
        }
        printf("\n");
    }
    return 0;
}