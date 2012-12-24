#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[110];
int xa,ya,xb,yb;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		
		int ans = 0x3f3f3f3f;
		for (int mid = 1;mid <= n;mid++)
		{
			int dt;
			int curx = xa;
			int cury = ya;
			int step = 0;

			//from s go to line mid
			if (mid < curx)	dt = -1;
			else	dt = 1;
			while (curx != mid)
			{
				curx += dt;
				cury = min(cury,a[curx]+1);
				step++;
			}

			//from line mid go to line xb
			if (xb < curx)	dt = -1;
			else	dt = 1;
			while (curx != xb)
			{
				curx += dt;
				cury = min(cury,a[curx]+1);
				step++;
			}

//			printf("(%d, %d)\n",curx,cury);

			//from (curx,cury) go to (xb,yb)
			if (yb < cury)	dt = -1;
			else	dt = 1;
			while (cury != yb)
			{
				cury += dt;
				step++;
			}

//			printf("step = %d\n",step);
			ans = min(ans,step);
		}
		printf("%d\n",ans);
	}
	return 0;
}
