#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y;
};
int n;
long long k;
Point p[2000];

long long xmult(int xa,int ya,int xb,int yb)
{
    return (long long)xa*yb-(long long)ya*xb;
}

long long check(int a,int b,int c)
{
    return xmult(p[b].x-p[a].x,p[b].y-p[a].y,p[c].x-p[a].x,p[c].y-p[a].y);
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d%lld",&n,&k);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[n+i] = p[i];
        }
        k *= 2;
        int res = 0;
        for (int i = 0;i < n;i++)
            for (int j = i+2;j < i+n;j++)
            {
                int l,r,mid1,mid2,mid;
                l = 1;
                r = j-i-1;
                while (l+10 < r)
                {
                    mid1 = (l*2+r)/3;
                    mid2 = (l+r*2)/3;
                    if (check(i,i+mid1,j) < check(i,i+mid2,j))
                        l = mid1;
                    else
                        r = mid2;
                }
                int mx = l;
                for (int ff = l;ff <= r;ff++)
                    if (check(i,i+mx,j) < check(i,i+ff,j))
                        mx = ff;
                if (check(i,i+mx,j) <= k)   continue;
                l = 1;
                r = mx;
                while (l < r)
                {
                    mid = l+r>>1;
                    if (check(i,i+mid,j) > k)
                        r = mid;
                    else
                        l = mid+1;
                }
                mid1 = l;
                l = mx;
                r = j-i-1;
                while (l < r)
                {
                    mid = l+r+1>>1;
                    if (check(i,i+mid,j) > k)
                        l = mid;
                    else
                        r = mid-1;
                }
                mid2 = r;
                res += mid2-mid1+1;
            }
        res /= 3;
        res = n*(n-1)*(n-2)/6-res;
        printf("%d\n",res);
	}
	return 0;
}
