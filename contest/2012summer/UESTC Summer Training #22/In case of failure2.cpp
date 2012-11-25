#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

const int MaxN = 100000;
const int inf = 0x7fffffff;

struct Point
{
    long long x, y;
};

bool cmpX(const Point &a, const Point &b)
{
    return a.x < b.x;
}

bool cmpY(const Point &a, const Point &b)
{
    return a.y < b.y;
}

Point a[MaxN], b[MaxN];
bool Div[MaxN];
int n;

void BuildKD(int l, int r, Point p[])
{
    if (l > r) return;
    int mid = l + r >> 1;
    int minX, minY, maxX, maxY;
    minX = min_element(p + l, p + r + 1, cmpX)->x;
    minY = min_element(p + l, p + r + 1, cmpY)->y;
    maxX = max_element(p + l, p + r + 1, cmpX)->x;
    maxY = max_element(p + l, p + r + 1, cmpY)->y;
    Div[mid] = (maxX - minX >= maxY - minY);
    nth_element(p + l, p + mid, p + r + 1, Div[mid] ? cmpX : cmpY);
    BuildKD(l, mid - 1, p);
    BuildKD(mid + 1, r, p);
}

long long res;

long long dist2(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void Find(int l, int r, Point a, Point p[])
{
    if (l > r)  return;
    int mid = l + r >> 1;
    long long dist = dist2(a, p[mid]);
    if (dist > 0)//如果有重点不能这样判断
        res = min(res, dist);
    long long d = Div[mid] ? (a.x - p[mid].x) : (a.y - p[mid].y);
    int l1, l2, r1, r2;
    l1 = l, l2 = mid + 1;
    r1 = mid - 1, r2 = r;
    if (d > 0)
        swap(l1, l2), swap(r1, r2);
    Find(l1, r1, a, p);
    if (d * d < res)
        Find(l2, r2, a, p);
}

int main(int argc, char const *argv[])
{
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%I64d%I64d", &a[i].x, &a[i].y);
            b[i] = a[i];
        }
        BuildKD(0, n - 1, b);
        for (int i = 0; i < n; i++)
        {
            res = 0x7fffffffffffffffLL;
            Find(0, n - 1, a[i], b);
            printf("%I64d\n", res);
        }
    }
    return 0;
}