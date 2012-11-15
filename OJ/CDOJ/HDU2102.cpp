#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
struct Event
{
    int f,x,y,step;
    Event(){}
    Event(int _f,int _x,int _y,int _step)
        {
            f = _f;
            x = _x;
            y = _y;
            step = _step;
        }
};

int n,m,tim;
char mp[2][15][15];
bool visit[2][15][15];
Event sp,ep,now,updata;

queue<Event> Q;

void BFS()
{
    while (!Q.empty())  Q.pop();
    Q.push(sp);
    memset(visit,false,sizeof(visit));
    visit[sp.f][sp.x][sp.y] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if (now.step > tim) continue;
        if (now.f == ep.f && now.x == ep.x && now.y == ep.y)
        {
            printf("YES\n");
            return;
        }
        for (int i = 0;i < 4;i++)
        {
            updata = Event(now.f,now.x+step[i][0],now.y+step[i][1],now.step+1);
            if (updata.x >= 0 && updata.x < n && updata.y >= 0 && updata.y < m)
            {
                if (mp[updata.f][updata.x][updata.y] == '#')
                    updata.f = 1-updata.f;
                if (mp[updata.f][updata.x][updata.y] != '*' && mp[updata.f][updata.x][updata.y] != '#')
                    if (visit[updata.f][updata.x][updata.y] == false)
                    {
                        visit[updata.f][updata.x][updata.y] = true;
                        Q.push(updata);
                    }
            }
        }
    }
    printf("NO\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&tim);
        for (int i = 0;i < n;i++)
            scanf("%s",mp[0][i]);
        for (int i = 0;i < n;i++)
            scanf("%s",mp[1][i]);
        for (int i = 0;i < 2;i++)
            for (int j = 0;j < n;j++)
                for (int k = 0;k < n;k++)
                {
                    if (mp[i][j][k] == 'S')
                        sp = Event(i,j,k,0);
                    if (mp[i][j][k] == 'P')
                        ep = Event(i,j,k,0);
                }
        BFS();
    }
    return 0;
}
