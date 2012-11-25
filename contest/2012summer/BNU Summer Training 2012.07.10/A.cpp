#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n;
char mp[1000][1001];
long long dp[1000][1000];
long long mod = (1<<31)-1;
bool visit[1000][1000];

bool BFS()
{
    queue<pair<int,int> > Q;
    memset(visit,false,sizeof(visit));
    Q.push(make_pair(0,0));
    visit[0][0] = true;
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        if (now.first == n-1 && now.second == n-1)   return true;
        for (int i = 0;i < 4;i++)
        {
            int tx = now.first+step[i][0];
            int ty = now.second+step[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
            if (mp[tx][ty] == '#')  continue;
            if (visit[tx][ty] == false)
            {
                visit[tx][ty] = true;
                Q.push(make_pair(tx,ty));
            }
        }
    }
    return false;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != 0 || j != 0)
                    if (mp[i][j] == '.')
                    {
                        if (i)
                            dp[i][j] += dp[i-1][j];
                        if (j)
                            dp[i][j] += dp[i][j-1];
                        dp[i][j] %= mod;
                    }
        if (dp[n-1][n-1] != 0)
            printf("%lld\n",dp[n-1][n-1]);
        else if (BFS())
            puts("THE GAME IS A LIE");
        else
            puts("INCONCEIVABLE");
    }
    return 0;
}
