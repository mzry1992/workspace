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
}q[500000];
int head,tail;
int visit[600][600][4];
int godown[600][600][4][2];

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
    res.x = godown[newpos.x][newpos.y][now.w][0];
    res.y = godown[newpos.x][newpos.y][now.w][1];
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
    res.x = godown[newpos.x][newpos.y][now.w][0];
    res.y = godown[newpos.x][newpos.y][now.w][1];
    res.w = now.w;
    res.step = now.step+1;
    if (visit[res.x][res.y][res.w] > res.step)
        return 1;
    else
        return 0;
}

int rotateleft(node now,node &res)
{

    res.x = godown[now.x][now.y][(now.w+1)%4][0];
    res.y = godown[now.x][now.y][(now.w+1)%4][1];
    res.w = (now.w+1)%4;
    res.step = now.step+1;
    if (visit[res.x][res.y][res.w] > res.step)
        return 1;
    else
        return 0;
}

int rotateright(node now,node &res)
{
    res.x = godown[now.x][now.y][(now.w+3)%4][0];
    res.y = godown[now.x][now.y][(now.w+3)%4][1];
    res.w = (now.w+3)%4;
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
    head = 0;
    tail = -1;
    tail++;
    q[tail] = getnode(sx,sy,0,0);
    for (int i = 0;i <= 500;i++)
    for (int j = 0;j <= 500;j++)
    for (int k = 0;k < 4;k++)
        visit[i][j][k] = 19921005;
    while (head <= tail)
    {
        now = q[head];
        head++;
        if ((now.x == ex) && (now.y == ey))
            return now.step;
        int temp;
        temp = goleft(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            tail++;
            q[tail] = updata;
        }
        temp = goright(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            tail++;
            q[tail] = updata;
        }
        temp = rotateleft(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            tail++;
            q[tail] = updata;
        }
        temp = rotateright(now,updata);
        if (temp == 1)
        {
            visit[updata.x][updata.y][updata.w] = updata.step;
            tail++;
            q[tail] = updata;
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
        for (int i = 0;i < n;i++)
        {
            godown[i][0][1][0] = i;
            godown[i][0][1][1] = 0;
            for (int j = 1;j < m;j++)
                if (map[i][j-1] != '#')
                {
                    godown[i][j][1][0] = godown[i][j-1][1][0];
                    godown[i][j][1][1] = godown[i][j-1][1][1];
                }
                else
                {
                    godown[i][j][1][0] = i;
                    godown[i][j][1][1] = j;
                }
            godown[i][m-1][3][0] = i;
            godown[i][m-1][3][1] = m-1;
            for (int j = m-2;j >= 0;j--)
                if (map[i][j+1] != '#')
                {
                    godown[i][j][3][0] = godown[i][j+1][3][0];
                    godown[i][j][3][1] = godown[i][j+1][3][1];
                }
                else
                {
                    godown[i][j][3][0] = i;
                    godown[i][j][3][1] = j;
                }
        }
        for (int i = 0;i < m;i++)
        {
            godown[0][i][2][0] = 0;
            godown[0][i][2][1] = i;
            for (int j = 1;j < n;j++)
                if (map[j-1][i] != '#')
                {
                    godown[j][i][2][0] = godown[j-1][i][2][0];
                    godown[j][i][2][1] = godown[j-1][i][2][1];
                }
                else
                {
                    godown[j][i][2][0] = j;
                    godown[j][i][2][1] = i;
                }
            godown[n-1][i][0][0] = n-1;
            godown[n-1][i][0][1] = i;
            for (int j = n-2;j >= 0;j--)
                if (map[j+1][i] != '#')
                {
                    godown[j][i][0][0] = godown[j+1][i][0][0];
                    godown[j][i][0][1] = godown[j+1][i][0][1];
                }
                else
                {
                    godown[j][i][0][0] = j;
                    godown[j][i][0][1] = i;
                }
        }
        int res = BFS(spx,spy,epx,epy);
        if (res == -1)
            printf("Can not escape!\n");
        else
            printf("%d\n",res);
    }
}
