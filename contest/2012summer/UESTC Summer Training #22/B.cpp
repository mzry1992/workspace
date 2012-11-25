#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

pair<int,int> h[1000000];
int n,d,fh[1000000],ans[1000000],f[1000000];
bool add[1000000];

int findf(int x)
{
    if (x != f[x])  f[x] = findf(f[x]);
    return f[x];
}

void uu(int a,int b)
{
    int fa = findf(a);
    int fb = findf(b);
    f[fa] = fb;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d%d",&n,&d);
	    for (int i = 0;i < n;i++)
	    {
	        scanf("%d",&h[i].first);
	        h[i].second = i;
	        f[i] = i;
	        add[i] = false;
	    }
	    sort(h,h+n);
	    for (int i = 0;i < d;i++)
            scanf("%d",&fh[i]);
        int cur = n-1,cnt = 0;
        for (int i = d-1;i >= 0;i--)
        {
            while (cur >= 0 && h[cur].first > fh[i])
            {
                cnt++;
                if (h[cur].second-1 >= 0 && add[h[cur].second-1])
                {
                    uu(h[cur].second,h[cur].second-1);
                    cnt--;
                }
                if (h[cur].second+1 < n && add[h[cur].second+1])
                {
                    uu(h[cur].second,h[cur].second+1);
                    cnt--;
                }
                add[h[cur].second] = true;
                cur--;
            }
            ans[i] = cnt;
        }
        for (int i = 0;i < d;i++)
            printf("%d ",ans[i]);
        printf("\n");
	}
	return 0;
}
