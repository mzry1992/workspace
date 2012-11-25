#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int n,m,g[20][20];
bool mark[20][20];

bool DFS(int x,int y,int id)
{
	mark[x][y] = true;
	for (int i = 0;i < 4;i++)
	{
		int tx = x+step[i][0];
		int ty = y+step[i][1];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n || g[tx][ty] == 1-id || mark[tx][ty] == true)
			continue;
		if (g[tx][ty] == id)
			DFS(tx,ty,id);
		else
			return false;
	}
	return true;
}

void DEL(int x,int y,int id)
{
	g[x][y] = 0;
	for (int i = 0;i < 4;i++)
	{
		int tx = x+step[i][0];
		int ty = y+step[i][1];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n || g[tx][ty] == 0)
			continue;
		DEL(tx,ty,id);
	}
}

void Gao(int id)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (g[i][j] == id)
			{
				memset(mark,false,sizeof(mark));
				bool flag = DFS(i,j,id);
				if (flag)
					DEL(i,j,id);
			}
}

int main(int argc, char const *argv[])
{
	freopen("G.in","r",stdin);
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
		scanf("%d%d",&n,&m);
		memset(g,-1,sizeof(g));
		int err = -1;
		for (int i = 0;i < m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--;
			y--;
			if (x < 0 || x >= n || y < 0 || y >= n || g[x][y] != 0)
				err = i;
			else 
			{
				g[x][y] = i%2;
				Gao(g[x][y]^1);
				Gao(g[x][y]);
			}
		}
		if (err != -1)
			printf("Invalid %d\n",err+1);
		else
		{
			puts("FUCK");
		}
	}
	return 0;
}