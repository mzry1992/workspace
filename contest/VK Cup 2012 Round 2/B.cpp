#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct lemming
{
    int w,v,id;
    bool operator < (const lemming& b)const
    {
        if (w == b.w)   return v < b.v;
        return w < b.w;
    }
};

int n,m,h;
lemming a[100000];

bool check(long double t)
{
    for (int i = 0,j = 0;i < n;i++)
        if ((long double)(j+1)*h <= t*a[i].v)
        {
            j++;
            if (j == m) return true;
        }
    return false;
}

void output(long double t)
{
    for (int i = 0,j = 0;i < n && j < m;i++)
    {
        if ((long double)(j+1)*h <= t*a[i].v+1e-10)
        {
            printf("%d ",a[i].id);
            j++;
        }
    }
    printf("\n");
}

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for (int i = 0;i < n;i++)
        scanf("%d",&a[i].w);
	for (int i = 0;i < n;i++)
        scanf("%d",&a[i].v);
	for (int i = 0;i < n;i++)
        a[i].id = i+1;
    sort(a,a+n);
    long double l = 0,r = 1000000000;
    for (int tim = 0;tim < 1000;tim++)
    {
        long double mid = (l+r)/2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    output(l);
    /*for (int i = 0;i < n;i++)
        cout << a[i].w << ' ' << a[i].v << ' ' << a[i].id << endl;*/
	return 0;
}
