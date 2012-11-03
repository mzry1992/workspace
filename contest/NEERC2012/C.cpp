#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int moves[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
const int step[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char mp[600][600];
int n,m;

struct Node
{
	int x,y,dir;
	Node(){}
	Node(int _x,int _y,int _dir)
	{
		x = _x;
		y = _y;
		dir = _dir;
	}
};
int dist[300][300][8];
bool inq[300][300][8];
bool out(int x,int y)
{
	if (x >= 1 && x < n-1 && y >= 1 && y < m-1)
		return false;
	return true;
}

int BFS(int sx,int sy,int dir)
{
	memset(inq,false,sizeof(inq));
	memset(dist,63,sizeof(dist));
	queue<Node> Q;

	dist[sx][sy][dir] = 0;
	Q.push(Node(sx,sy,dir));

	Node now,nxt;
	int res = 0x3f3f3f3f;
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		inq[now.x][now.y][now.dir] = false;

		int ax,ay,bx,by;
		ax = now.x;
		ay = now.y;
		bx = ax+step[now.dir][0];
		by = ay+step[now.dir][1];

//		printf("1 at (%d, %d), 2 at (%d, %d), dir = %d, step = %d\n",ax,ay,bx,by,now.dir,dist[now.x][now.y][now.dir]);
		if (out(ax,ay) && out(bx,by))
		{
			res = min(res,dist[now.x][now.y][now.dir]);
			continue;
		}
		//move 1
		for (int i = 0;i < 4;i++)
		{
			nxt.x = ax+moves[i][0];
			nxt.y = ay+moves[i][1];
			if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m)	continue;
			if (nxt.x == bx && nxt.y == by)	continue;
			if (abs(nxt.x-bx) > 1 || abs(nxt.y-by) > 1)	continue;

			int nxtdis = dist[now.x][now.y][now.dir];
			if (mp[ax*2+1+moves[i][0]][ay*2+1+moves[i][1]] == '.')
				nxtdis++;
			else if (mp[ax*2+1+moves[i][0]][ay*2+1+moves[i][1]] != ' ')
				continue;

			for (int j = 0;j < 8;j++)
			{
				int tx = nxt.x+step[j][0];
				int ty = nxt.y+step[j][1];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m)		continue;
				if (tx == bx && ty == by)
				{
					nxt.dir = j;
					break;
				}
			}

			if (dist[nxt.x][nxt.y][nxt.dir] > nxtdis)
			{
				dist[nxt.x][nxt.y][nxt.dir] = nxtdis;
				if (inq[nxt.x][nxt.y][nxt.dir] == false)
				{
					Q.push(nxt);
					inq[nxt.x][nxt.y][nxt.dir] = true;
				}
			}
		}

		//moves 2
		for (int i = 0;i < 4;i++)
		{
			int tbx = bx+moves[i][0];
			int tby = by+moves[i][1];
			if (tbx < 0 || tbx >= n || tby < 0 || tby >= m)	continue;
			if (tbx == ax && tby == ay)	continue;
			if (abs(tbx-ax) > 1 || abs(tby-ay) > 1)	continue;

			int nxtdis = dist[now.x][now.y][now.dir];
			if (mp[bx*2+1+moves[i][0]][by*2+1+moves[i][1]] == '.')
				nxtdis++;
			else if (mp[bx*2+1+moves[i][0]][by*2+1+moves[i][1]] != ' ')
				continue;

//			printf("tb = (%d, %d)\n",tbx,tby);
			nxt.x = now.x;
			nxt.y = now.y;

			for (int j = 0;j < 8;j++)
			{
				int tx = nxt.x+step[j][0];
				int ty = nxt.y+step[j][1];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m)		continue;
				if (tx == tbx && ty == tby)
				{
					nxt.dir = j;
					break;
				}
			}

//			printf("dir = %d\n",nxt.dir);
			if (dist[nxt.x][nxt.y][nxt.dir] > nxtdis)
			{
				dist[nxt.x][nxt.y][nxt.dir] = nxtdis;
				if (inq[nxt.x][nxt.y][nxt.dir] == false)
				{
					Q.push(nxt);
					inq[nxt.x][nxt.y][nxt.dir] = true;
				}
			}
		}
	}
	if (res == 0x3f3f3f3f)	res = -1;
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int j = 0;j < m+2;j++)
	{
		mp[2*n+4][2*j] = mp[0][2*j] = '+';
		mp[2*n+4][2*j+1] = mp[0][2*j+1] = ' ';
		mp[2*n+3][2*j] = mp[1][2*j] = ' ';
		mp[2*n+3][2*j+1] = mp[1][2*j+1] = ' ';
	}
	mp[2*n+4][2*m+4] = mp[0][2*m+4] = '+';
	mp[2*n+3][2*m+4] = mp[1][2*m+4] = ' ';
	mp[2*n+3][2*m+5] = mp[1][2*m+5] = mp[2*n+4][2*m+5] = mp[0][2*m+5] = 0;
	int sx,sy,dir;
	gets(mp[599]);
	for (int i = 0;i < 2*n+1;i++)
	{
		gets(mp[i+2]+2);
		if (i%2 == 0)
		{
			mp[i+2][2*m+4] = mp[i+2][0] = '+';
			mp[i+2][2*m+3] = mp[i+2][1] = ' ';
		}
		else
		{
			mp[i+2][2*m+4] = mp[i+2][0] = ' ';
			mp[i+2][2*m+3] = mp[i+2][1] = ' ';
		}
		mp[i+2][2*m+5] = 0;
	}
	n += 2;
	m += 2;
//	for (int i = 0;i < 2*n+1;i++)
//		puts(mp[i]);

	sx = sy = dir = -1;
	for (int i = 0;i < 2*n+1;i++)
		for (int j = 0;j < 2*m+1;j++)
			if (mp[i][j] == '1')
			{
				sx = i/2;
				sy = j/2;
			}
	for (int i = 0;i < 8;i++)
	{
		int tx = sx+step[i][0];
		int ty = sy+step[i][1];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m)		continue;
		if (mp[tx*2+1][ty*2+1] == '2')
			dir = i;
	}
	if (sx == -1 || dir == -1)
		puts("Death");
	else
	{
		int ret = BFS(sx,sy,dir);
		if (ret == -1)
			puts("Death");
		else
			printf("%d\n",ret);
	}
    return 0;
}

