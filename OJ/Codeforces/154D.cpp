#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k;
char a[500][500];
int cnt[500][500];
int sam[500][26];
int nxtpos[500];

int geta(int xa,int ya,int xb,int yb)
{
	return cnt[xb][yb]-(cnt[xb][ya-1]+cnt[xa-1][yb]-cnt[xa-1][ya-1]);
}

int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (scanf("%d%d%d",&n,&m,&k) != EOF)
	{
		for (int i = 1;i <= n;i++)
		{
			a[i][0] = ';';
			scanf("%s",a[i]+1);
		}
		memset(cnt,0,sizeof(cnt));
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				cnt[i][j] = cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+(a[i][j] == 'a');

		long long ans = 0;
		for (int xa = 1;xa < n;xa++)
			for (int xb = xa+1;xb <= n;xb++)
			{
				for (int i = 0;i < 26;i++)
					sam[0][i] = 0;
				for (int y = 1;y <= m;y++)
				{
					for (int i = 0;i < 26;i++)
						sam[y][i] = sam[y-1][i];
					if (a[xa][y] == a[xb][y])
						sam[y][a[xa][y]-'a']++;
				}
				/////////////////////////////
				for (int y = 1,nxt = 1;y < m;y++)
				{
					nxt = max(nxt,y);
					while (nxt < m && geta(xa,y,xb,nxt+1) <= k)
						nxt++;
					if (nxt > y)
						nxtpos[y] = nxt;
					else
						nxtpos[y] = -1;
				}

				for (int ya = 1;ya < m;ya++)
					if (a[xa][ya] == a[xb][ya] && geta(xa,ya,xb,ya+1) <= k)
					{
						int yb = nxtpos[ya];
						ans += sam[yb][a[xa][ya]-'a']-sam[ya][a[xa][ya]-'a'];
					}
			}
		cout << ans << endl;
	}
	return 0;
}
