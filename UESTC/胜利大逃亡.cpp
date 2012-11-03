#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,t,sx,sy,ex,ey;
char map[30][30];
struct node
{
    int x,y,step,key;
}now;
deque<node> Q;
bool visit[30][30][1030];

node getnode(int x,int y,int step,int key)
{
    node res;
    res.x = x;
    res.y = y;
    res.step = step;
    res.key = key;
    return res;
}

int BFS()
{
    memset(visit,false,sizeof(visit));
    Q.clear();
    Q.push_back(getnode(sx,sy,0,0));
    visit[sx][sy][0] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if (now.step >= t)  continue;
        if (now.x == ex && now.y == ey) return now.step;
        for (int i = 0;i < 4;i++)
        {
            int tx,ty;
            tx = now.x+step[i][0];
            ty = now.y+step[i][1];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m)
                if (map[tx][ty] != '*')
                {
                    if (map[tx][ty] >= 'A' && map[tx][ty] <= 'J')
                    {
                        if (((now.key>>(map[tx][ty]-'A'))&1) == 1)
                        {
                            if (visit[tx][ty][now.key] == false)
                            {
                                visit[tx][ty][now.key] = true;
                                Q.push_back(getnode(tx,ty,now.step+1,now.key));
                            }
                        }
                    }
                    else if (map[tx][ty] >= 'a' && map[tx][ty] <= 'j')
                    {
                        int tkey = now.key|(1<<(map[tx][ty]-'a'));
                        if (visit[tx][ty][tkey] == false)
                        {
                            visit[tx][ty][tkey] = true;
                            Q.push_back(getnode(tx,ty,now.step+1,tkey));
                        }
                    }
                    else if (visit[tx][ty][now.key] == false)
                    {
                        visit[tx][ty][now.key] = true;
                        Q.push_back(getnode(tx,ty,now.step+1,now.key));
                    }
                }
        }
    }
    return -1;
}

int main()
{
    int ft = 0;
    while (scanf("%d%d%d",&n,&m,&t) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%s",map[i]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                if (map[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
                if (map[i][j] == '^')
                {
                    ex = i;
                    ey = j;
                }
            }
        ft++;
        printf("Case %d: %d\n",ft,BFS());
    }
}
