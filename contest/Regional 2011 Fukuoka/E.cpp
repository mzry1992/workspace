#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int x,y,n;
bool visit[300][300][20][20];
int nxtb[2][20][20][3],nxtl[2][20][20][3];

struct node
{
    int x,y,b,l,dis;
    node(){}
    node(int _x,int _y,int _b,int _l,int _dis)
    {
        x = _x;
        y = _y;
        b = _b;
        l = _l;
        dis = _dis;
    }
};

void init()
{

}

int BFS()
{
    memset(visit,false,sizeof(visit));
    queue<node> Q;
    Q.push(node(150,150,0,5,0));
    visit[150][150][0][5] = true;
    node now,upd;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (now.x == x && now.y == y && now.b == n) return now.dis;
        if ((now.x+now.y)%2 == 0)
        {
            upd = node(now.x,now.y+1,nxtb[0][now.b][now.l][0],nxtl[0][now.b][now.l][0],now.dis+1);
            if (visit[upd.x][upd.y][upd.b][upd.l] == false)
            {
                visit[upd.x][upd.y][upd.b][upd.l] = true;
                Q.push(upd);
            }
            upd = node(now.x+1,now.y,nxtb[0][now.b][now.l][1],nxtl[0][now.b][now.l][1],now.dis+1);
            if (visit[upd.x][upd.y][upd.b][upd.l] == false)
            {
                visit[upd.x][upd.y][upd.b][upd.l] = true;
                Q.push(upd);
            }
            upd = node(now.x-1,now.y,nxtb[0][now.b][now.l][2],nxtl[0][now.b][now.l][2],now.dis+1);
            if (visit[upd.x][upd.y][upd.b][upd.l] == false)
            {
                visit[upd.x][upd.y][upd.b][upd.l] = true;
                Q.push(upd);
            }
        }
        else
        {
            upd = node(now.x-1,now.y,nxtb[1][now.b][now.l][0],nxtl[1][now.b][now.l][0],now.dis+1);
            if (visit[upd.x][upd.y][upd.b][upd.l] == false)
            {
                visit[upd.x][upd.y][upd.b][upd.l] = true;
                Q.push(upd);
            }
            upd = node(now.x+1,now.y,nxtb[1][now.b][now.l][1],nxtl[1][now.b][now.l][1],now.dis+1);
            if (visit[upd.x][upd.y][upd.b][upd.l] == false)
            {
                visit[upd.x][upd.y][upd.b][upd.l] = true;
                Q.push(upd);
            }
            upd = node(now.x,now.y-1,nxtb[1][now.b][now.l][2],nxtl[1][now.b][now.l][2],now.dis+1);
            if (visit[upd.x][upd.y][upd.b][upd.l] == false)
            {
                visit[upd.x][upd.y][upd.b][upd.l] = true;
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
	    printf("%d\n",BFS());
	}
	return 0;
}
