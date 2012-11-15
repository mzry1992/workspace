#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
bool map[250][250],visit[250][250];
struct node
{
    int x,y,step;
}now,updata;
deque<node> Q;

node getnode(int x,int y,int step)
{
    node res;
    res.x = x;res.y = y;res.step = step;
    return res;
}

int BFS()
{
    memset(visit,false,sizeof(visit));
    Q.clear();
    Q.push_back(getnode(1,1,0));
    visit[1][1] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if (now.x == n && now.y == m)   return now.step;
        for (int i = 0;i < 4;i++)
        {
            updata.x = now.x+step[i][0];
            updata.y = now.y+step[i][1];
            updata.step = now.step+1;
            if (updata.x >= 1 && updata.x <= n && updata.y >= 1 && updata.y <= m)
            if (map[updata.x][updata.y] == false)
                if (visit[updata.x][updata.y] == false)
                {
                    visit[updata.x][updata.y] = true;
                    Q.push_back(updata);
                }
        }
    }
    return -1;
}

int main()
{
    //freopen("CDOJ1480.in","r",stdin);
    //freopen("CDOJ1480.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%d",&map[i][j]);
        printf("Case #%d: %d\n",ft,BFS());
    }
}
