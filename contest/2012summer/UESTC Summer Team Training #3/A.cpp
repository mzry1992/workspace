#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int sx,sy,ex,ey;
int id[501][501],typ[120],tot,pos[120][2],dist[120][120],dis[501][501];
char mp[501][501];
int n,m,tid;

queue<pair<int,int> > Q;

void go(pair<int,int> now,int dir)
{
    int tx = now.first+step[dir][0];
    int ty = now.second+step[dir][1];
    if (tx < 0 || tx >= n || ty < 0 || ty >= m) return;
    if (mp[tx][ty] == 'W' || mp[tx][ty] == '#') return;
    if (dis[tx][ty] != -1)  return;
    dis[tx][ty] = dis[now.first][now.second]+1;
    Q.push(make_pair(tx,ty));
}

void BFS(int s)
{
    memset(dis,-1,sizeof(dis));
    Q.push(make_pair(pos[s][0],pos[s][1]));
    dis[pos[s][0]][pos[s][1]] = 0;
    while (!Q.empty())
    {
        pair<int,int> now;
        now = Q.front();
        Q.pop();
        if (mp[now.first][now.second] == 'L')
            go(now,2);
        else if (mp[now.first][now.second] == 'U')
            go(now,0);
        else if (mp[now.first][now.second] == 'D')
            go(now,1);
        else if (mp[now.first][now.second] == 'R')
            go(now,3);
        else
        {
            for (int i = 0; i < 4; i++)
                go(now,i);
        }
    }
    for (int i = 0; i < tot; i++)
        dist[s][i] = dis[pos[i][0]][pos[i][1]];
}

int d[120][1<<10];
bool inq[120][1<<10];

int SPFA()
{
    queue<pair<int,int> > Q;
    memset(d,-1,sizeof(d));
    memset(inq,false,sizeof(inq));
    int tmp = 0;
    if (typ[0] != -1)   tmp = 1<<typ[0];
    d[0][tmp] = 0;
    inq[0][tmp] = true;
    Q.push(make_pair(0,tmp));
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        inq[now.first][now.second] = false;
        for (int i = 0; i < tot; i++)
            if (dist[now.first][i] != -1)
            {
                int nsta = now.second;
                if (d[i][nsta] == -1 ||
                        d[i][nsta] > d[now.first][now.second]+dist[now.first][i])
                {
                    d[i][nsta] = d[now.first][now.second]+dist[now.first][i];
                    if (inq[i][nsta] == false)
                    {
                        inq[i][nsta] = true;
                        Q.push(make_pair(i,nsta));
                    }
                }

                if (typ[i] != -1)
                    if (((now.second>>typ[i])&1) == 0)
                    {
                        nsta = now.second|(1<<typ[i]);
                        if (d[i][nsta] == -1 ||
                                d[i][nsta] > d[now.first][now.second]+dist[now.first][i]+2)
                        {
                            d[i][nsta] = d[now.first][now.second]+dist[now.first][i]+2;
                            if (inq[i][nsta] == false)
                            {
                                inq[i][nsta] = true;
                                Q.push(make_pair(i,nsta));
                            }
                        }
                    }
            }
    }
    int maxt = -1,mint = -1;
    for (int i = 0; i < (1<<tid); i++)
        if (d[1][i] != -1)
        {
            int cnt = 0;
            for (int j = 0; j < tid; j++)
                if (((i>>j)&1) == 1)
                    cnt++;
            if (cnt < maxt) continue;
            if (cnt == maxt)
                mint = min(mint,d[1][i]);
            else
            {
                maxt = cnt;
                mint = d[1][i];
            }
        }
    return mint;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        sx--;
        sy--;
        ex--;
        ey--;
        memset(id,-1,sizeof(id));
        tot = 0;
        pos[tot][0] = sx;
        pos[tot][1] = sy;
        typ[tot++] = -1;
        pos[tot][0] = ex;
        pos[tot][1] = ey;
        typ[tot++] = -1;
        if (mp[sx][sy] == 'W' || mp[sx][sy] == '#' || mp[ex][ey] == 'W' || mp[ex][ey] == '#')
        {
            puts("-1");
            continue;
        }
        tid = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] == '0' || mp[i][j] == '$')
                {
                    id[i][j] = tot;
                    pos[tot][0] = i;
                    pos[tot][1] = j;
                    if (mp[i][j] == '0')
                        typ[tot++] = -1;
                    else
                        typ[tot++] = tid++;
                }
        for (int i = 2; i < tot; i++)
        {
            if (pos[i][0] == pos[0][0] && pos[i][1] == pos[0][1])
                typ[0] = typ[i];
            if (pos[i][0] == pos[1][0] && pos[i][1] == pos[1][1])
                typ[1] = typ[i];
        }
        for (int i = 0; i < tot; i++)
            BFS(i);
        printf("%d\n",SPFA());
    }
    return 0;
}
