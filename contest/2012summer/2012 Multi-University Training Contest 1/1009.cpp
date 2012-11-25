#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char mp[5100];
int n,m,cost,disY,disC,dis[5100];

int BFS(int s,char ed)
{
    queue<int > Q;
    memset(dis,-1,sizeof(dis));
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        if (mp[now] == ed) return dis[now]-1;
        int x = now/m;
        int y = now%m;
        for (int i = 0;i < 4;i++)
        {
            int tx = x+step[i][0];
            int ty = y+step[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            int tnow = tx*m+ty;
            if (mp[tnow] == '#')    continue;
            if (dis[tnow] == -1)
            {
                dis[tnow] = dis[now]+1;
                Q.push(tnow);
            }
        }
    }
    return -1;
}

int main()
{
	while (scanf("%d%d%d",&n,&m,&cost) != EOF)
	{
	    for (int i = 0;i < n;i++)
            scanf("%s",mp+i*m);
        disY = disC = -1;
        int totdis;
        for (int i = 0;i < n*m;i++)
            if (mp[i] == 'Y')
            {
                disY = BFS(i,'P');
                totdis = BFS(i,'C');
            }
            else if (mp[i] == 'C')
                disC = BFS(i,'P');
        if (totdis == -1 && (disY == -1 || disC == -1))
            puts("Damn teoy!");
        else
        {
            if (disY != -1 && disC != -1)
                if (totdis == -1 || totdis > disY+disC)
                    totdis = disY+disC;
            printf("%d\n",totdis*cost);
        }
	}
	return 0;
}
