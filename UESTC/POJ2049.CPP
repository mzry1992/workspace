#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int m,n;
int map[210][210][4];
const int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int use[210][210];
struct statue
{
    int x,y,door;
	bool operator < (const statue &a) const
	{
		return  a.door < door;
	}
};
priority_queue<statue> Q;

statue getstatue(int x,int y,int door)
{
    statue res;
    res.x = x;
    res.y = y;
    res.door = door;
    return res;
}

int BFS(int sx,int sy,int ex,int ey)
{
    while (!Q.empty())  Q.pop();
    for (int i = 0;i <= 205;i++)
    for (int j = 0;j <= 205;j++)
        use[i][j] = 19921005;
    use[sx][sy] = 0;
    Q.push(getstatue(sx,sy,0));
    statue now,updata;
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.x == ex && now.y == ey)
            return now.door;
        for (int i = 0;i < 4;i++)
        {
            updata.x = now.x+step[i][0];
            updata.y = now.y+step[i][1];
            if (updata.x >= 0 && updata.x <= 200)
            if (updata.y >= 0 && updata.y <= 200)
            {
                updata.door = now.door;
                if (map[now.x][now.y][i] != 1)
                {
                    if (map[now.x][now.y][i] == 2)
                        updata.door++;
                    if (use[updata.x][updata.y] > updata.door)
                    {
                        use[updata.x][updata.y] = updata.door;
                        Q.push(updata);
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        scanf("%d%d",&m,&n);
        memset(map,0,sizeof(map));
        if ((m == -1) && (n == -1)) break;
        for (int i = 1;i <= m;i++)
        {
            int x,y,d,t;
            scanf("%d%d%d%d",&x,&y,&d,&t);
            if (d == 0)
            for (int j = 1;j <= t;j++)
            {
                map[x+j][y][0] = 1;
                map[x+j][y+1][2] = 1;
            }
            else
            for (int j = 1;j <= t;j++)
            {
                map[x][y+j][1] = 1;
                map[x+1][y+j][3] = 1;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            if (d == 0)
            {
                map[x+1][y][0] = 2;
                map[x+1][y+1][2] = 2;
            }
            else
            {
                map[x][y+1][1] = 2;
                map[x+1][y+1][3] = 2;
            }
        }
        double ex,ey;
        cin >> ex >> ey;
        if (n==0 && m==0)
			printf ("0\n");
		else if (ex<0||ey<0||ex>199||ey>199)
			printf ("0\n");
		else
		{
            int res = BFS(0,0,(int)ex+1,(int)ey+1);
            printf("%d\n",res);
		}
    }
}
