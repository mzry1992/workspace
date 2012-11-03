#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
struct point
{
	int x,y;
}ci[300000],p[300000],a[300000],ans[300000];
int cnt;
int tot;

bool cmp(point a,point b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

point findp(int x,int y)
{
    if (x < a[1].x)
    {
        point temp;
        temp.x = x;
        temp.y = y-1;
        return temp;
    }
    int l,r,mid;
    l = 1;
    r = cnt;
    while (l < r)
    {
        mid = (l+r+1)/2;
        //cout << l << ' ' << r << endl;
        //'cout << a[mid].x << ' ' << x << endl;
        if (a[mid].x==x) return a[mid];
        if (a[mid].x <= x)
            l = mid;
        else
            r = mid-1;
    }
    return a[l];
}

int main()
{
	while (scanf("%d%d",&m,&n) != EOF)
	{
		for (int i = 1;i <= m;i++)
			scanf("%d%d",&ci[i].x,&ci[i].y);
		for (int i = 1;i <= n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p+1,p+n+1,cmp);
		cnt = 0;
		int pre = 1;
		for (int i = 2;i <= n;i++)
		{
			if (p[i].x == p[pre].x)
				pre = i;
			else if (p[i].y > p[pre].y)
			{
				cnt++;
				a[cnt] = p[pre];
				pre = i;
			}
		}
		cnt++;
		a[cnt] = p[pre];
		sort(a+1,a+cnt+1,cmp);
		tot = 0;
		for (int i = 1;i <= m;i++)
		{
			int x,y;
			x = ci[i].x;
			y = ci[i].y;
			point tp = findp(x,y);
			//cout << x << ' ' << y << ' ' << tp.x << ' ' << tp.y << endl;
			if (tp.y < y)
			{
				tot++;
				ans[tot].x = x;
				ans[tot].y = y;
			}
		}
		sort(ans+1,ans+tot+1,cmp);
		printf("%d\n",tot);
		for (int i = 1;i <= tot;i++)
			printf("%d %d\n",ans[i].x,ans[i].y);
	}
}
