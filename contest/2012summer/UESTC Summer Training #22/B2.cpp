#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;

const int inf = 1000000000;
const int maxn = 100000+10;
const ll ll_inf = 9223372036854775800ll;
struct point
{
    int x,y;
    point() {}
    point(int p,int q):x(p),y(q) {}
};
vector<point> a;
int tx[maxn];
int ty[maxn];
bool divX[maxn];
int n;

bool cmpX(point a, point b)
{
    return a.x < b.x;
}

bool cmpY(point a, point b)
{
    return a.y < b.y;
}

void buildTree(int left, int right, point a[])
{
    if (left >= right) return;
    int mid = (left + right) >> 1;
    int minx = inf;
    int maxx = -inf;
    int miny = inf ;
    int maxy = -inf;
    for (int i = left; i<right; ++i)
    {
        minx=min(minx,a[i].x);
        miny=min(miny,a[i].y);
        maxx = max(maxx, a[i].x);
        maxy = max(maxy, a[i].y);
    }
    divX[mid] = (maxx - minx) >= (maxy - miny);
    nth_element(a + left, a + mid, a + right, divX[mid] ? cmpX : cmpY);

    tx[mid] = a[mid].x;
    ty[mid] = a[mid].y;
    if (left+1==right) return;
    buildTree(left,mid,a);
    buildTree(mid+1,right,a);
}

long long closestDist;
int closestNode;

void findD(int left,int right,int x,int y)
{
    if (left>=right) return;
    int mid=(left+right)>>1;
    ll dx=x-tx[mid];
    ll dy=y-ty[mid];
    ll d=dx*dx+dy*dy;
    if (closestDist>d && d)
    {
        closestDist=d;
        closestNode = mid;
    }
    if (left + 1 == right) return;
    ll delta = divX[mid] ? dx : dy;
    ll delta2 = delta * delta;
    int l1 = left;
    int r1 = mid;
    int l2 = mid + 1;
    int r2 = right;
    if (delta>0)
    {
        swap(l1,l2);
        swap(r1,r2);
    }
    findD(l1, r1, x, y);
    if (delta2 < closestDist)
        findD(l2, r2, x, y);
}

int solve(int n,int x,int y)
{
    closestDist = ll_inf;
    findD(0, n, x, y);
    return closestNode;
}

int main()
{
    int _;
    scanf("%d",&_);
    while (_--)
    {
        a.clear();
        scanf("%d",&n);
        int p1,p2;
        for (int i=0; i<n; ++i)
        {
            scanf("%d%d",&p1,&p2);
            a.push_back(point(p1,p2));
        }
        vector<point> b(a);
        buildTree(0,n,&b[0]);
        for (int i=0; i<n; ++i)
        {
            solve(n,a[i].x,a[i].y);
            printf("%I64d\n",closestDist);
        }
    }
    return 0;
}
