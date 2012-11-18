#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool g[200][200];
int n;

int main()
{
	while (scanf("%d",&n) != EOF)
	{
		int x,y;
		x = y = 100;
		memset(g,false,sizeof(g));
		g[x][y] = true;
		for (int i = 0;i < n;i++)
		{
			char dir;
			int dis,_dir;
			scanf(" %c%d",&dir,&dis);
			if (dir == 'U')
				_dir = 0;
			else if (dir == 'D')
				_dir = 1;
			else if (dir == 'L')
				_dir = 2;
			else
				_dir = 3;

			for (int j = 0;j < dis;j++)
			{
				g[x][y] = true;
				x += step[_dir][0];
				y += step[_dir][1];
			}
		}
		int ans = 0;
		for (int i = 0;i < 200;i++)
			for (int j = 0;j < 200;j++)
				if (g[i][j])
					ans++;
		printf("%d\n",ans);
	}
	return 0;
}
