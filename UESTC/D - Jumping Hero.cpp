#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int map[500][500];
int sx,sy,tx,ty;
struct bfsnode
{
    int x,y;
    int step;
    int m,n;
    int jx,jy;
}now,updata;
deque<bfsnode> Q;
bool visit[310][310][7][7];

bfsnode getnode(int x,int y,int step,int m,int n,int jx,int jy)
{
    bfsnode res;
    res.x = x;
    res.y = y;
    res.step = step;
    res.m = m;
    res.n = n;
    res.jx = jx;
    res.jy = jy;
    return res;
}

int BFS()
{
    memset(visit,false,sizeof(visit));
    Q.clear();
    Q.push_back(getnode(sx,sy,0,0,0,0,0));
    visit[sx][sy][0][0] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if (now.x == tx && now.y == ty) return now.step;
        if (now.m == 0)
        {
            for (int i = 0;i < 4;i++)
            {
                int x,y;
                x = now.x+step[i][0];
                y = now.y+step[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m)
                if (map[x][y] > 0)
                {
                    updata.x = x;
                    updata.y = y;
                    updata.step = now.step+1;
                    if (map[x][y] == 1)
                    {
                        updata.n = updata.m = 0;
                        updata.jx = updata.jy = 0;
                    }
                    else
                    {
                        updata.m = map[x][y]/10;
                        updata.n = map[x][y]%10;
                        updata.jx = x;
                        updata.jy = y;
                    }
                    if (visit[updata.x][updata.y][updata.m][updata.n] == false)
                    {
                        visit[updata.x][updata.y][updata.m][updata.n] = true;
                        Q.push_back(updata);
                    }
                }
            }
        }
        else
        {
            for (int i = 0;i < 4;i++)
            {
                int x,y;
                x = now.x+now.n*step[i][0];
                y = now.y+now.n*step[i][1];
                if (x >= 0 && x < n && y >= 0 && y < m)
                if (map[x][y] > 0)
                {
                    updata.x = x;
                    updata.y = y;
                    updata.step = now.step+1;
                    if (map[x][y] == 1 || (updata.jx == x && updata.jy == y))
                    {
                        if (now.m == 1)
                        {
                            updata.n = updata.m = 0;
                            updata.jx = updata.jy = 0;
                        }
                        else
                        {
                            updata.n = now.n;
                            updata.m = now.m-1;
                        }
                    }
                    else
                    {
                        updata.m = map[x][y]/10;
                        updata.n = map[x][y]%10;
                        updata.jx = x;
                        updata.jy = y;
                    }
                    if (visit[updata.x][updata.y][updata.m][updata.n] == false)
                    {
                        visit[updata.x][updata.y][updata.m][updata.n] = true;
                        Q.push_back(updata);
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        if (ft > 1) printf("\n");
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            scanf("%d",&map[i][j]);
        scanf("%d%d",&sx,&sy);
        scanf("%d%d",&tx,&ty);
        int res = BFS();
        if (res == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",res);
    }
}
