#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
    int x,y,a,b;
    node(){}
    node(int _x,int _y,int _a,int _b)
    {
        x = _x,y = _y,a = _a,b = _b;
    }
};

const int near[6][4] = {{3,4,2,5},{3,5,2,4},{5,0,4,1},{5,1,4,0},{3,1,2,0},{3,0,2,1}};
const int step[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int go[6][6][4][2];
char pre[10],mp[11][11];
int n,m,sx,sy,ex,ey;
int dis[11][11][6][6],tim[11][11][6][6];
bool inq[11][11][6][6];

int SPFA()
{
    queue<node> Q;
    memset(dis,63,sizeof(dis));
    memset(inq,false,sizeof(inq));
    memset(tim,0,sizeof(tim));
    Q.push(node(sx,sy,5,3));
    dis[sx][sy][5][3] = 0;
    inq[sx][sy][5][3] = true;
    while (!Q.empty())
    {
        node now = Q.front(),upd;
        Q.pop();
        tim[now.x][now.y][now.a][now.b]++;
        if (tim[now.x][now.y][now.a][now.b] > n*m)
            return -214748365;
        inq[now.x][now.y][now.a][now.b] = false;

        //cout << now.x << ' ' << now.y << ' ' << dis[now.x][now.y][now.a][now.b] << endl;

        if (mp[now.x][now.y] == 'T')
            continue;

        for (int i = 0;i < 4;i++)
        {
            upd = node(now.x+step[i][0],now.y+step[i][1],go[now.a][now.b][i][0],go[now.a][now.b][i][1]);
            if (upd.x < 0 || upd.x >= n || upd.y < 0 || upd.y >= m)
                continue;
            if (mp[upd.x][upd.y] == '.')    continue;
            if (mp[upd.x][upd.y] == 'S')    continue;

            if (mp[upd.x][upd.y] == 'T')
            {
                if (dis[upd.x][upd.y][upd.a][upd.b] > dis[now.x][now.y][now.a][now.b])
                {
                    dis[upd.x][upd.y][upd.a][upd.b] = dis[now.x][now.y][now.a][now.b];
                    if (inq[upd.x][upd.y][upd.a][upd.b] == false)
                    {
                        inq[upd.x][upd.y][upd.a][upd.b] = true;
                        Q.push(upd);
                    }
                }
            }
            else
            {
                int cost;
                if (mp[upd.x][upd.y] == pre[upd.a])
                    cost = -2*(mp[upd.x][upd.y]-'0');
                else
                    cost = mp[upd.x][upd.y]-'0'+pre[upd.a]-'0';
                if (dis[upd.x][upd.y][upd.a][upd.b] > dis[now.x][now.y][now.a][now.b]+cost)
                {
                    dis[upd.x][upd.y][upd.a][upd.b] = dis[now.x][now.y][now.a][now.b]+cost;
                    if (inq[upd.x][upd.y][upd.a][upd.b] == false)
                    {
                        inq[upd.x][upd.y][upd.a][upd.b] = true;
                        Q.push(upd);
                    }
                }
            }
        }
    }
//    int tt = 0;
//    for (int i = 0;i < n;i++)
//        for (int j = 0;j < m;j++)
//            for (int k = 0;k < 6;k++)
//                for (int q = 0;q < 6;q++)
//                    tt += tim[i][j][k][q];
//    printf("%d\n",tt);
    int res = -214748364;
    for (int i = 0;i < 6;i++)
        for (int j = 0;j < 6;j++)
            res = max(res,-dis[ex][ey][i][j]);
    return res;
}

bool visit[11][11];

bool BFS()
{
    queue<pair<int,int> > Q;
    memset(visit,false,sizeof(visit));
    Q.push(make_pair(sx,sy));
    visit[sx][sy] = true;
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        if (now.first == ex && now.second == ey) return true;
        for (int i = 0;i < 4;i++)
        {
            pair<int,int> nn = make_pair(now.first+step[i][0],now.second+step[i][1]);
            if (nn.first < 0 || nn.first >= n || nn.second < 0 || nn.second >= m ||
                mp[nn.first][nn.second] == '.')
                    continue;
            if (visit[nn.first][nn.second] == false)
            {
                visit[nn.first][nn.second] = true;
                Q.push(nn);
            }
        }
    }
    return false;
}

int main()
{
    for (int i = 0;i < 6;i++)
        for (int j = 0;j < 4;j++)
        {
            int to = near[i][j];
            go[i][to][0][0] = to;go[i][to][0][1] = i^1;
            go[i][to][2][0] = to^1;go[i][to][2][1] = i;
            go[i][to][1][0] = (near[i][(j+1)%4]);go[i][to][1][1] = to;
            go[i][to][3][0] = (near[i][(j+3)%4]);go[i][to][3][1] = to;
        }
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d%d",&n,&m);
	    scanf("%s",pre);
	    for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (mp[i][j] == 'S')
                    sx = i,sy = j;
                else if (mp[i][j] == 'T')
                    ex = i,ey = j;
        if (!BFS())
        {
            puts("Impossible");
            continue;
        }
        int res = SPFA();
        if (res == -214748365)
            puts("Infinity");
        else
            printf("%d\n",res);
	}
	return 0;
}
