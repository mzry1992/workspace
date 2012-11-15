#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

const int step[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};
int r,c,m,n,w;
int map[120][120];
bool visit[120][120];
struct node
{
    int x,y;
};
deque<node> Q;

node getnode(int x,int y)
{
    node res;
    res.x = x;
    res.y = y;
    return res;
}

void BFS()
{
    Q.clear();
    Q.push_back(getnode(0,0));
    map[0][0] = 3;
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop_front();
        for (int i = 0;i < 4;i++)
        {
            int tx,ty;
            tx = now.x+m*step[i][0];
            ty = now.y+n*step[i][1];
            if (tx >= 0 && tx < r && ty >= 0 && ty < c)
            if (map[tx][ty] == 0)
            {
                map[tx][ty] = 3;
                Q.push_back(getnode(tx,ty));
            }
            tx = now.x+n*step[i][0];
            ty = now.y+m*step[i][1];
            if (tx >= 0 && tx < r && ty >= 0 && ty < c)
            if (map[tx][ty] == 0)
            {
                map[tx][ty] = 3;
                Q.push_back(getnode(tx,ty));
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d%d",&r,&c,&m,&n);
        memset(map,0,sizeof(map));
        scanf("%d",&w);
        for (int i = 1;i <= w;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y] = 1;
        }
        BFS();
        int res1,res2;
        res1 = res2 = 0;
        memset(visit,false,sizeof(visit));
        for (int x = 0;x < r;x++)
        for (int y = 0;y < c;y++)
        if (map[x][y] == 3)
        {
            for (int i = 0;i < 4;i++)
            {
                int tx,ty;
                tx = x+m*step[i][0];
                ty = y+n*step[i][1];
                if (tx >= 0 && tx < r && ty >= 0 && ty < c)
                if (map[tx][ty] == 3)
                    visit[tx][ty] = true;
                tx = x+n*step[i][0];
                ty = y+m*step[i][1];
                if (tx >= 0 && tx < r && ty >= 0 && ty < c)
                if (map[tx][ty] == 3)
                    visit[tx][ty] = true;
            }
            int tot = 0;
            for (int i = 0;i < 4;i++)
            {
                int tx,ty;
                tx = x+m*step[i][0];
                ty = y+n*step[i][1];
                if (tx >= 0 && tx < r && ty >= 0 && ty < c)
                if (visit[tx][ty] == true)
                {
                    visit[tx][ty] = false;
                    tot++;
                }
                tx = x+n*step[i][0];
                ty = y+m*step[i][1];
                if (tx >= 0 && tx < r && ty >= 0 && ty < c)
                if (visit[tx][ty] == true)
                {
                    visit[tx][ty] = false;
                    tot++;
                }
            }
            if (tot%2 == 0) res1++;
            else    res2++;
        }
        printf("Case %d: %d %d\n",ft,res1,res2);
    }
}
