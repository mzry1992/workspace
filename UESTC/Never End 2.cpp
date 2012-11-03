#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>
using namespace std;

const int step[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
int n,m;
char map[600][600];
struct node
{
    int x,y,w;
    int step;
};
deque<node> Q;
int visit[600][600][4];

node getnode(int x,int y,int w,int step)
{
    node res;
    res.x = x;res.y = y;res.w = w;res.step = step;
    return res;
}

int goleft(node now,node &res)
{
    int left = (now.w+1)%4;
    node newpos,downnewpos;
    newpos.x = now.x+step[left][0];
    newpos.y = now.y+step[left][1];
    if ((newpos.x < 0) || (newpos.x >= n) || (newpos.y < 0) || (newpos.y >= m)) return 0;
    if (map[newpos.x][newpos.y] == '#') return 0;
    while (true)
    {
        downnewpos.x = newpos.x+step[now.w][0];
        downnewpos.y = newpos.y+step[now.w][1];
        if ((downnewpos.x < 0) || (downnewpos.x >= n) || (downnewpos.y < 0) || (downnewpos.y >= m)) break;
        if (map[downnewpos.x][downnewpos.y] == '#') break;
        newpos.x = downnewpos.x;
        newpos.y = downnewpos.y;
    }
    res.x = newpos.x;
    res.y = newpos.y;
    res.w = now.w;
    res.step = now.step+1;
    if (visit[res.x][res.y][res.w] > res.step)
        return 1;
    else
        return 0;
}

int goright(node now,node &res)
{
    int right = (now.w+3)%4;
    node newpos,downnewpos;
    newpos.x = now.x+step[right][0];
    newpos.y = now.y+step[right][1];
    if ((newpos.x < 0) || (newpos.x >= n) || (newpos.y < 0) || (newpos.y >= m)) return 0;
    if (map[newpos.x][newpos.y] == '#') return 0;
    while (true)
    {
        downnewpos.x = newpos.x+step[now.w][0];
        downnewpos.y = newpos.y+step[now.w][1];
        if ((downnewpos.x < 0) || (downnewpos.x >= n) || (downnewpos.y < 0) || (downnewpos.y >= m)) break;
        if (map[downnewpos.x][downnewpos.y] == '#') break;
        newpos.x = downnewpos.x;
        newpos.y = downnewpos.y;
    }
    res.x = newpos.x;
    res.y = newpos.y;
    res.w = now.w;
    res.step = now.step+1;
    if (visit[res.x][res.y][res.w] > res.step)
        return 1;
    else
        return 0;
}

int rotateleft(node now,node &res)
{
    node newpos,downnewpos;
    newpos.x = now.x;
    newpos.y = now.y;
    newpos.w = (now.w+1)%4;
    while (true)
    {
        downnewpos.x = newpos.x+step[newpos.w][0];
        downnewpos.y = newpos.y+step[newpos.w][1];
        if ((downnewpos.x < 0) || (downnewpos.x >= n) || (downnewpos.y < 0) || (downnewpos.y >= m)) break;
        if (map[downnewpos.x][downnewpos.y] == '#') break;
        newpos.x = downnewpos.x;
        newpos.y = downnewpos.y;
    }
    res.x = newpos.x;
    res.y = newpos.y;
    res.w = newpos.w;
    res.step = now.step+1;
    if (visit[res.x][res.y][res.w] > res.step)
        return 1;
    else
        return 0;
}

int rotateright(node now,node &res)
{
    node newpos,downnewpos;
    newpos.x = now.x;
    newpos.y = now.y;
    newpos.w = (now.w+3)%4;
    while (true)
    {
        downnewpos.x = newpos.x+step[newpos.w][0];
        downnewpos.y = newpos.y+step[newpos.w][1];
        if ((downnewpos.x < 0) || (downnewpos.x >= n) || (downnewpos.y < 0) || (downnewpos.y >= m)) break;
        if (map[downnewpos.x][downnewpos.y] == '#') break;
        newpos.x = downnewpos.x;
        newpos.y = downnewpos.y;
    }
    res.x = newpos.x;
    res.y = newpos.y;
    res.w = newpos.w;
    res.step = now.step+1;
    if (visit[res.x][res.y][res.w] > res.step)
        return 1;
    else
        return 0;
}

int BFS(int sx,int sy,int ex,int ey)
{
    node now;
    node updata;
    Q.clear();
    Q.push_back(getnode(sx,sy,0,0));
    for (int i = 0;i <= 500;i++)
    for (int j = 0;j <= 500;j++)
    for (int k = 0;k < 4;k++)
        visit[i][j][k] = 19921005;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if ((now.x == ex) && (now.y == ey))
            return now.step;
        int temp;
        temp = goleft(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            Q.push_back(updata);
        }
        temp = goright(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            Q.push_back(updata);
        }
        temp = rotateleft(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            Q.push_back(updata);
        }
        temp = rotateright(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            Q.push_back(updata);
        }
    }
    return -1;
}

int main()
{
    freopen("Never End.in","r",stdin);
    while (scanf("%d%d\n",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            gets(map[i]);
        int spx,spy,epx,epy;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        {
            if (map[i][j] == '|')
            {
                spx = i; spy = j;
            }
            if (map[i][j] == 'E')
            {
                epx = i; epy = j;
            }
        }
        int res = BFS(spx,spy,epx,epy);
        if (res == -1)
            printf("Can not escape!\n");
        else
            printf("%d\n",res);
    }
}

