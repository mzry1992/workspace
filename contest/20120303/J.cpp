#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int x,y,tim;
    char ch;
};
const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,dis[510][510];
char mp[510][510];

int main()
{
	int t;
	scanf("%d",&t);
	for (int ft = 1;ft <= t;ft++)
	{
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        queue<node> Q;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                dis[i][j] = -1;
                if (mp[i][j] >= 'a' && mp[i][j] <= 'z')
                {
                    node tmp;
                    tmp.x = i,tmp.y = j,tmp.tim = 0,tmp.ch = mp[i][j];
                    Q.push(tmp);
                    dis[i][j] = 0;
                }
            }
        while (!Q.empty())
        {
            node now = Q.front();
            Q.pop();
            if (mp[now.x][now.y] == '*')    continue;
            for (int i = 0;i < 4;i++)
            {
                int tx = now.x+step[i][0];
                int ty = now.y+step[i][1];
                if (tx < 0 || tx >= n)  continue;
                if (ty < 0 || ty >= m)  continue;
                if (mp[tx][ty] == '#')  continue;
                if (mp[tx][ty] == now.ch)   continue;
                if (mp[tx][ty] == '.')
                {
                    mp[tx][ty] = now.ch;
                    dis[tx][ty] = now.tim+1;
                    node tmp;
                    tmp.x = tx,tmp.y = ty,tmp.tim = now.tim+1,tmp.ch = now;
                    Q.push(tmp);
                }
                else if (now.tim+1 == dis[tx][ty])
                    mp[tx][ty] = '*';
            }
        }
        for (int i = 0;i < n;i++)
            puts(mp[i]);
        puts("");
	}
	return 0;
}
