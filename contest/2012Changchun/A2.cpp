#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,lp,rp,acnt,bcnt;
bool a[10000];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A2.out","w",stdout);
	while (scanf("%d",&n) != EOF)
	{
		scanf("%d%d",&lp,&rp);
		scanf("%d%d",&acnt,&bcnt);
		memset(a,false,sizeof(a));
		for (int i = 0;i < n;i++)
		{
			int pos;
			scanf("%d",&pos);
			a[pos] = true;
		}
		int res = 0;
		for (int i = lp;i+acnt-1 <= rp;i++)
		{
			int tres = n;
			for (int l = 0;l <= bcnt;l++)
			{
				int cnt = 0;
				for (int j = 0;j < acnt-bcnt;j++)
					if (a[i+l+j] == true)
						cnt++;
				tres = min(tres,cnt);
			}
			res = max(res,tres);
		}
		printf("%d\n",res);
	}
    return 0;
}
