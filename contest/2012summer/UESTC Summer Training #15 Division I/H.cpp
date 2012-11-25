#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int la,a[60],n,A,B,C,D,E,F,M,p[1000001],q[1000001];
long long can[1000001];
pair<int,int> ta[60];
long long sum[60];
inline int get1(int x)
{
    int l=0,r=la-1;
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (ta[mid].first>=x)
            r=mid-1;
        else
            l=mid;
    }
    return l;
}
inline int get2(int x)
{
    int l=0,r=la-1;
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (ta[mid].first>x)
            r=mid-1;
        else
            l=mid;
    }
    return l;
}
int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&la);
	    for (int i = 0;i < la;i++)
	    {
            scanf("%d",&a[i]);
            ta[i] = make_pair(a[i],i);
	    }
	    sort(ta,ta+la);
	    sum[0] = 1LL<<ta[0].second;
	    for (int i = 1;i < la;i++)
            sum[i] = sum[i-1]|(1LL<<ta[i].second);

        scanf("%d%d%d%d%d%d%d%d%d%d",&n,&p[0],&q[0],&A,&B,&C,&D,&E,&F,&M);
        int res = 0,l,r;
        if (n >= la)
        {
            can[0] = 0;
            for (int i = 1;i <= n;i++)
            {
                p[i] = (A * p[i-1] + B * q[i-1] + C) % M;
                q[i] = (D * p[i-1] + E * q[i-1] + F) % M;
                if (q[i] < p[i])    swap(p[i],q[i]);
                if (p[i] > ta[0].first || q[i] < ta[la-1].first)
                    can[i] = 0;
                else
                {
                    l = get1(p[i]);
                    r = get2(q[i]);
                    long long sl = sum[l],sr = sum[r];
                    if (p[i] < ta[0].first)
                        sl = 0;
                    can[i] = (can[i-1]<<1)&(sr^sl);
                    if (p[i] <= a[0] && a[0] <= q[i])
                        can[i] |= 1;
                    if (((can[i]>>(la-1))&1) == 1)
                        res++;
                }
            }
        }
        printf("Case %d: %d\n",cas,res);
	}
	return 0;
}
