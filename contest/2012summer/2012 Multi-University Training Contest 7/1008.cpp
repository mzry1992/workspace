#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

struct Point
{
    long long x, y;
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

const int mod = 1000000007;
Point p[200];
int n;

int power(long long a,int b)
{
    long long ret=1;
    for(; b; b>>=1,a=a*a%mod)
        if (b&1)
            ret=ret*a%mod;
    return ret;
}

int down[200][200],cnt[200][200];

void init()
{
    memset(down,0,sizeof(down));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            if (p[i].x < p[j].x)
                for (int k = 0;k < n;k++)
                    if (k != i && k != j)
                        if (p[k].x >= p[i].x && p[k].x < p[j].x && (p[k]-p[i])*(p[j]-p[i]) > 0)
                            down[i][j]++;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            if (i != j)
            {
                cnt[i][j] = 0;
                for (int k = 0;k < n;k++)
                    if (i != k && j != k)
                    {
                        Point p1 = p[j]-p[i],p2 = p[k]-p[i];
                        if (atan2(p1.y,p1.x) > atan2(p2.y,p2.x))
                            cnt[i][j]++;
                    }
            }
}

int calc(int a,int b,int c)
{
    Point p1 = p[b]-p[a],p2 = p[c]-p[a];
    if (atan2(p1.y,p1.x) > atan2(p2.y,p2.x))
        swap(b,c);
    if ((p[b]-p[a])*(p[c]-p[a]) > 0)
        return cnt[a][c]-cnt[a][b]-1;
    else
        return n-3-(cnt[a][c]-cnt[a][b]-1);
}

int in(int a,int b,int c)
{
    if (p[a].x > p[b].x || (p[a].x == p[b].x && p[a].y < p[b].y))
        swap(a,b);
    if (p[a].x > p[c].x || (p[a].x == p[c].x && p[a].y < p[c].y))
        swap(a,c);
    if (p[b].x > p[c].x || (p[b].x == p[c].x && p[b].y > p[c].y))
        swap(b,c);
    int res = down[a][b]+down[b][c]-down[a][c];
    if (res < 0)
        res = -res-1;
    return res;
}

int calc(int a,int b)
{
    int res = 0;
    for (int i = 0;i < n;i++)
        if (i != a && i != b)
           res += calc(i,a,b)-in(i,a,b);
    return res/2;
}

int f[40000];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data2.out","w",stdout);
    f[1]=f[0]=1;
    for (int i=2; i<40000; i++)
    {
        f[i]=f[i-1]+f[i-2];
        if (f[i]>mod-2)
            f[i]-=mod-1;
    }
    while (scanf("%d",&n)!=EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
        init();
        long long ans = 1;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
            {
                int k=calc(i,j);
                //printf("%d\n",k);
                ans=ans*(power(k,f[k])+1)%mod;
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
