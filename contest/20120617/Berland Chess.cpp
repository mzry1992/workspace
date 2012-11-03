#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int step[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int kstep[8][2] = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
int bstep[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
int n,m;
char mp[16][16];
int sx,sy,x[15],y[15],tot,id[15][15],tid[15][15];
bool g[1<<15][15][15];

void Gao(int idx,int x,int y)
{
    if (mp[x][y] == 'K')
    {
        for (int i = 0;i < 8;i++)
        {
            int tx = x+kstep[i][0];
            int ty = y+kstep[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || tid[tx][ty] != -1)    continue;
            g[idx][tx][ty] = false;
        }
    }
    else if (mp[x][y] == 'B')
    {
        for (int i = 0;i < 4;i++)
        {
            int tx = x+bstep[i][0];
            int ty = y+bstep[i][1];
            while (true)
            {
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || tid[tx][ty] != -1)    break;
                g[idx][tx][ty] = false;
                tx += bstep[i][0];
                ty += bstep[i][1];
            }
        }
    }
    else if (mp[x][y] == 'R')
    {
        for (int i = 0;i < 4;i++)
        {
            int tx = x+step[i][0];
            int ty = y+step[i][1];
            while (true)
            {
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || tid[tx][ty] != -1)    break;
                g[idx][tx][ty] = false;
                tx += step[i][0];
                ty += step[i][1];
            }
        }
    }
}

struct node
{
    int x,y,sta,step;
    node(){}
    node(int _sta,int _x,int _y,int _step)
    {
        x = _x;
        y = _y;
        sta = _sta;
        step = _step;
    }
};

bool visit[1<<15][15][15];

int BFS()
{
    queue<node> Q;
    Q.push(node((1<<tot)-1,sx,sy,0));
    memset(visit,false,sizeof(visit));
    visit[(1<<tot)-1][sx][sy] = true;
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        /*cout << now.sta << ' ' << now.x << ' ' << now.y << ' ' << now.step << endl;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
                printf("(%d,%d) ",id[i][j],g[now.sta][i][j]);
            printf("\n");
        }*/
        if (g[now.sta][now.x][now.y] == false)  continue;
        if (now.sta == 0)   return now.step;
        for (int i = 0;i < 8;i++)
        {
            int tx = now.x+step[i][0];
            int ty = now.y+step[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if (id[tx][ty] == -1 || (((now.sta>>id[tx][ty])&1) == 0))
            {
                if (g[now.sta][tx][ty] == false)    continue;
                if (visit[now.sta][tx][ty] == true) continue;
                visit[now.sta][tx][ty] = true;
                //cout << tx << ' ' << ty << ' ' << now.sta << endl;
                Q.push(node(now.sta,tx,ty,now.step+1));
            }
            else
            {
                int newsta = now.sta&(~(1<<id[tx][ty]));
                if (visit[newsta][tx][ty] == true)  continue;
                visit[newsta][tx][ty] = true;
                Q.push(node(newsta,tx,ty,now.step+1));
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);

        tot = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                id[i][j] = -1;
                if (mp[i][j] == '*')
                {
                    sx = i;
                    sy = j;
                }
                else if (mp[i][j] != '.')
                {
                    id[i][j] = tot;
                    x[tot] = i;
                    y[tot++] = j;
                }
            }

        memset(g,true,sizeof(g));
        for (int sta = 0;sta < (1<<tot);sta++)
        {
            for (int i = 0;i < n;i++)
                for (int j = 0;j < m;j++)
                {
                    tid[i][j] = -1;
                    if (id[i][j] != -1)
                        if (((sta>>(id[i][j]))&1) == 1)
                            tid[i][j] = id[i][j];
                }
            for (int i = 0;i < tot;i++)
                if (((sta>>i)&1) == 1)
                    Gao(sta,x[i],y[i]);
        }

        printf("%d\n",BFS());
    }
	return 0;
}
