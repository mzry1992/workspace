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
    int id;
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
Point p[200],tp[400];
int n;

int power(long long a,int b)
{
    long long ret=1;
    for(; b; b>>=1,a=a*a%mod)
        if (b&1)
            ret=ret*a%mod;
    return ret;
}

int cnt[200][200];

Point mid;

bool cmp(Point a,Point b)
{
    Point v1 = a-mid,v2 = b-mid;
    return atan2(v1.y,v1.x) < atan2(v2.y,v2.x);
}

void init()
{
    memset(cnt,0,sizeof(cnt));
    for (int i = 0;i < n;i++)
    {
        int m = 0;
        for (int j = 0;j < n;j++)
            if (i != j)
                tp[m++] = p[j];
        mid = p[i];
        sort(tp,tp+m,cmp);
        if (m > 1)
        {

        }
    }
}

int calc(int a,int b,int c)
{
}

int in(int a,int b,int c)
{
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
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
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
        {
            scanf("%lld%lld",&p[i].x,&p[i].y);
            p[i].id = i;
        }
        init();
        long long ans = 1;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
            {
                int k=calc(i,j);
                //printf("%d\n",k);
                ans=ans*(power(k,f[k])+1)%mod;
            }
        printf("%lld\n",ans);
    }
    return 0;
}
