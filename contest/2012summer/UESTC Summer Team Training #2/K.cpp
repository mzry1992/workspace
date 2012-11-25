#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int mp[121][121],pos[14401][2];
bool prime[14401];

void Gao()
{
    memset(prime,false,sizeof(prime));
    for (int i = 2;i <= 110*110;i++)
    {
        prime[i] = true;
        for (int j = 2;j*j <= i;j++)
            if (i%j == 0)
                prime[i] = false;
    }
    memset(mp,0,sizeof(mp));
    int x,y,d;
    x = y = d = 0;
    for (int ss = 110*110;ss >= 1;ss--)
    {
        pos[ss][0] = x;
        pos[ss][1] = y;
        mp[x][y] = ss;
        int tx,ty;
        tx = x+step[d][0];
        ty = y+step[d][1];
        if (tx < 0 || tx >= 110 || ty < 0 || ty >= 110 || mp[tx][ty] != 0)
        {
            d = (d+1)%4;
            tx = x+step[d][0];
            ty = y+step[d][1];
        }
        x = tx;
        y = ty;
    }
}

int x,y;
bool inq[111][111];
int dist[111][111];

queue<pair<int,int> > Q;

int BFS()
{
    memset(inq,false,sizeof(inq));
    memset(dist,-1,sizeof(dist));
    inq[pos[x][0]][pos[x][1]] = true;
    dist[pos[x][0]][pos[x][1]] = 0;
    Q.push(make_pair(pos[x][0],pos[x][1]));
    int xa,ya,xb,yb;
    xa = max(0,min(pos[x][0]-5,pos[y][0]-5));
    ya = max(0,min(pos[x][1]-5,pos[y][1]-5));
    xb = min(109,max(pos[x][0]+5,pos[y][0]+5));
    yb = min(109,max(pos[x][1]+5,pos[y][1]+5));
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        inq[now.first][now.second] = false;
        for (int i = 0;i < 4;i++)
        {
            int x = now.first+step[i][0];
            int y = now.second+step[i][1];
            if (x < xa || x > xb || y < ya || y > yb || prime[mp[x][y]] == true)  continue;
            if (dist[x][y] == -1 || dist[x][y] > dist[now.first][now.second]+1)
            {
                dist[x][y] = dist[now.first][now.second]+1;
                if (inq[x][y] == false)
                {
                    inq[x][y] = true;
                    Q.push(make_pair(x,y));
                }
            }
        }
    }
    return dist[pos[y][0]][pos[y][1]];
}

int main()
{
    Gao();
    int cas = 0;
    while (scanf("%d%d",&x,&y) != EOF)
    {
        cas++;
        printf("Case %d: ",cas);
        int res = BFS();
        if (res == -1)
            puts("impossible");
        else
            printf("%d\n",res);
    }
	return 0;
}
