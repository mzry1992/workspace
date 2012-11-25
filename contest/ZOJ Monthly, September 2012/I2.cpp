#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,l;
int id[50][50];
int mp[50][50];
int sx,sy,ex,ey;

struct Node
{
    int x,y,sta;
    int step,ener;

    Node(){}
    Node(int _x,int _y,int _sta,int _step,int _ener)
    {
        x = _x;
        y = _y;
        sta = _sta;
        step = _step;
        ener = _ener;
    }

    bool operator <(const Node& b)const
    {
        if (step == b.step)
            return ener < b.ener;
        return step > b.step;
    }
};

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
const int inf = 0x3f3f3f3f;
pair<int,int> dist[50][50][32];

int calc()
{
    priority_queue<Node> Q;
    Q.push(Node(sx,sy,0,0,0));

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            for (int k = 0;k < 32;k++)
                dist[i][j][k] = make_pair(inf,-inf);

    dist[sx][sy][0] = make_pair(0,0);

    Node now,nxt;

    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();

        if (dist[now.x][now.y][now.sta] < make_pair(now.step,-now.ener))
            continue;
        if (now.x == ex && now.y == ey)
            return now.step;

        if (now.ener == 0)
        {
            now.step++;
            now.ener = l;
        }

        for (int i = 0;i < 4;i++)
        {
            nxt.x = now.x+dx[i];
            nxt.y = now.y+dy[i];

            if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m) continue;
            if (mp[nxt.x][nxt.y] == -1) continue;

            nxt.sta = now.sta;

            nxt.step=now.step;
            nxt.ener =now.ener-1;

            if (mp[nxt.x][nxt.y] && (((nxt.sta>>(mp[nxt.x][nxt.y]-1))&1) == 0))
                nxt.ener=0;

            if (id[nxt.x][nxt.y] > 0)
                nxt.sta |= (1<<(id[nxt.x][nxt.y]-1));

            if (dist[nxt.x][nxt.y][nxt.sta] > make_pair(nxt.step,-nxt.ener))
            {
                dist[nxt.x][nxt.y][nxt.sta] = make_pair(nxt.step,-nxt.ener);
                Q.push(nxt);
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&l) != EOF)
    {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                id[i][j] = 0;
                scanf("%d",&mp[i][j]);
                while (mp[i][j] >= 6 || mp[i][j] < -1)  puts("fuck");
            }
        int tmp;
        scanf("%d",&tmp);
        for (int i = 1;i <= tmp;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            id[x][y] = i;
        }

        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        sx--;
        sy--;
        ex--;
        ey--;

        int ret = calc();
        if (ret == -1)
            puts("We need God's help!");
        else
            printf("%d\n",ret);
    }
    return 0;
}

