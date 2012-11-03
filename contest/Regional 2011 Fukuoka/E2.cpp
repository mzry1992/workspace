#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int dir[20][3] =
{{4,5,1},{0,6,2},{1,7,3},{2,8,4},{3,9,0}
,{10,11,0},{11,12,1},{12,13,2},{13,14,3},{14,10,4}
,{9,15,5},{5,16,6},{6,17,7},{7,18,8},{8,19,9}
,{19,16,10},{15,17,11},{16,18,12},{17,19,13},{18,15,14}};

int d[20][20];
int x,y,n;

void init()
{
    for (int i = 0;i < 20;i++)
        for (int j = 0;j < 3;j++)
            for (int k = 0;k < 3;k++)
                if (dir[dir[i][j]][k] == i)
                    d[i][dir[i][j]] = (k-j+3)%3;
}

struct node
{
    int x,y,b,d,dis;
    node(){}
    node(int _x,int _y,int _b,int _d,int _dis)
    {
        x = _x;
        y = _y;
        b = _b;
        d = _d;
        dis = _dis;
    }
};

bool visit[300][300][20][3];
const int step[2][3][2] = {{{-1,0},{0,1},{1,0}},
                             {{1,0},{0,-1},{-1,0}}};
int Gao()
{
    queue<node> Q;
    memset(visit,false,sizeof(visit));
    Q.push(node(150,150,0,0,0));
    visit[150][150][0][0] = true;
    node now,upd;
    int typ;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (now.x == x && now.y == y && now.b == n) return now.dis;
        typ = (now.x+now.y)%2;
        for (int i = 0;i < 3;i++)
        {
            upd = node(now.x+step[typ][i][0],now.y+step[typ][i][1],
                        dir[now.b][(now.d+i)%3],(now.d+d[now.b][dir[now.b][(now.d+i)%3]])%3,now.dis+1);
            if (visit[upd.x][upd.y][upd.b][upd.d] == false)
            {
                visit[upd.x][upd.y][upd.b][upd.d] = true;
                Q.push(upd);
            }
        }
    }
}

int main()
{
	init();
	while (true)
	{
        scanf("%d%d%d",&x,&y,&n);
        if (x == 0 && y == 0 && n == 0) break;
        x += 150;
        y += 150;
        printf("%d\n",Gao());
	}
	return 0;
}

