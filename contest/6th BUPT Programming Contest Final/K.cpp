#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
char a[1100],b[1100];
int pa[1100],pb[1100];
bool can[1100][1100];
int pre[1100][1100];

void output(int x,int y)
{
    if (pre[x][y] == 1)
        output(x-1,y);
    else if (pre[x][y] == 2)
        output(x,y-1);
    else    return;
    printf("%d",pre[x][y]);
}

queue<pair<int,int> > Q;

int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
	    scanf("%s%s",a+1,b+1);
	    pa[0] = pb[0] = 0;
	    for (int i = 1;i <= n;i++)
	    {
	        pa[i] = pa[i-1]+a[i]-'0';
	        pb[i] = pb[i-1]+b[i]-'0';
	    }
        for (int i = 0;i <= n;i++)
            for (int j = 0;j <= n;j++)
            {
                pre[i][j] = 3;
                can[i][j] = false;
            }
        can[0][0] = true;

        while (!Q.empty())  Q.pop();
        Q.push(make_pair(0,0));
        while (!Q.empty())
        {
            pair<int,int> now = Q.front();
            Q.pop();
            if (now.first == n && now.second == n)  break;
            if (now.first < n)
            {
                int tota = pa[now.first+1]+pb[now.second];
                int totb = now.first+now.second+1-tota;
                if (abs(tota-totb) <= m)
                    if (can[now.first+1][now.second] == false)
                    {
                        can[now.first+1][now.second] = true;
                        pre[now.first+1][now.second] = 1;
                        Q.push(make_pair(now.first+1,now.second));
                    }
            }
            if (now.second < n)
            {
                int tota = pa[now.first]+pb[now.second+1];
                int totb = now.first+now.second+1-tota;
                if (abs(tota-totb) <= m)
                    if (can[now.first][now.second+1] == false)
                    {
                        can[now.first][now.second+1] = true;
                        pre[now.first][now.second+1] = 2;
                        Q.push(make_pair(now.first,now.second+1));
                    }
            }
        }
        if (can[n][n] == false)
            puts("Poor Alice");
        else
        {
            output(n,n);
            puts("");
        }
	}
	return 0;
}
