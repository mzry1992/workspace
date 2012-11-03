#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int n,m,mp,g[100][100],sx,sy,ex,ey;
bool visit[100][100][41],zoc[100][100];

struct node
{
    int x,y,turns,mps;
    node() {}
    node(int _x,int _y,int _turns,int _mps)
    {
        x = _x;
        y = _y;
        turns = _turns;
        mps = _mps;
    }
    friend bool operator < (node a,node b)
    {
        return a.turns > b.turns;
    }
};

priority_queue<node> Q;
node now,updata;
const int step[2][6][2] = {{{-1,0},{0,1},{1,0},{1,-1},{0,-1},{-1,-1}},
    {{-1,1},{0,1},{1,1},{1,0},{0,-1},{-1,0}}
};

int Gao()
{
    memset(visit,false,sizeof(visit));
    while (!Q.empty())  Q.pop();
    Q.push(node(sx,sy,1,mp));
    visit[sx][sy][mp] = true;
    int cost;
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.x == ex && now.y == ey) return now.turns;
        if (now.mps == 0)
        {
            now.turns++;
            now.mps = mp;
            Q.push(now);
            continue;
        }
        for (int f = 0; f < 6; f++)
        {
            updata.x = now.x+step[now.x%2][f][0];
            updata.y = now.y+step[now.x%2][f][1];
            if (updata.x < 0 || updata.x >= n || updata.y < 0 || updata.y >= m) continue;
            if ((((g[updata.x][updata.y])>>3)&1) == 1)  continue;
            if (zoc[now.x][now.y] == true && zoc[updata.x][updata.y] == true)
                cost = -1;
            else if (((((g[now.x][now.y])>>2)&1) == 1) && ((((g[updata.x][updata.y])>>2)&1) == 1))
                cost = 1;
            else if ((((g[now.x][now.y])>>(4+f))&1) == 1)
                cost = -1;
            else
                cost = 0;
            updata.turns = now.turns;
            if (cost == -1)
                updata.mps = 0;
            else if (cost == 1)
                updata.mps = now.mps-1;
            else
            {
                if ((((g[updata.x][updata.y])>>0)&1) == 1)
                    cost = 4;
                else
                    cost = 8;
                updata.mps = now.mps-cost;
                if (updata.mps <= 0)
                    updata.mps = 0;
            }
            if (visit[updata.x][updata.y][updata.mps] == false)
            {
                visit[updata.x][updata.y][updata.mps] = true;
                Q.push(updata);
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d%d",&n,&m,&mp);
        mp *= 4;
        memset(zoc,false,sizeof(zoc));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%d",&g[i][j]);
                if ((((g[i][j])>>3)&1) == 1)
                {
                    for (int f = 0; f < 6; f++)
                    {
                        updata.x = i+step[i%2][f][0];
                        updata.y = j+step[i%2][f][1];
                        if (updata.x < 0 || updata.x >= n || updata.y < 0 || updata.y >= m) continue;
                        zoc[updata.x][updata.y] = true;
                    }
                }
            }
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        printf("Case %d: %d\n",ft,Gao());
    }
    return 0;
}
