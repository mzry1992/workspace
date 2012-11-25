#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[8][2] = {{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
char mp[11][11];
bool res[11][11];

int check()
{
    memset(res,false,sizeof(res));
    for (int i = 0;i < 10;i++)
        for (int j = 0;j < 10;j++)
            if (mp[i][j] != '.')
                for (int k = 0;k < 8;k++)
                {
                    int cnt = 0,x = i,y = j;
                    while (x >= 0 && x < 10 && y >= 0 && y < 10 && mp[x][y] == mp[i][j])
                    {
                        cnt++;
                        x += step[k][0];
                        y += step[k][1];
                    }
                    if (cnt >= 5)
                        for (int q = 0;q < cnt;q++)
                            res[i+step[k][0]*q][j+step[k][1]*q] = true;
                }
    int ans = 0;
    for (int i = 0;i < 10;i++)
        for (int j = 0;j < 10;j++)
            if (res[i][j] == true)
                ans++;
    return ans;
}

bool cango[11][11];

void Gao(int x,int y)
{
    cango[x][y] = true;
    for (int i = 0;i < 4;i++)
    {
        int tx = x+step[i][0];
        int ty = y+step[i][1];
        if (tx >= 0 && tx < 10 && ty >= 0 && ty < 10 && cango[tx][ty] == false && mp[tx][ty] == '.')
            Gao(tx,ty);
    }
}

int main()
{
    int cas = 0;
	while (scanf("%s",mp[0]) != EOF)
	{
	    for (int i = 1;i < 10;i++)
            scanf("%s",mp[i]);
        if (cas > 0)
            puts("");
        printf("Case #%d: ",++cas);
        if (check() > 0)
            puts("Waiting!");
        else
        {
            int ans = 0;
            for (int i = 0;i < 10;i++)
                for (int j = 0;j < 10;j++)
                    if (mp[i][j] != '.')
                    {
                        memset(cango,false,sizeof(cango));
                        Gao(i,j);
                        for (int x = 0;x < 10;x++)
                            for (int y = 0;y < 10;y++)
                                if (cango[x][y] == true && mp[x][y] == '.')
                                {
                                    mp[x][y] = mp[i][j];
                                    mp[i][j] = '.';
                                    ans = max(ans,check());
                                    mp[i][j] = mp[x][y];
                                    mp[x][y] = '.';
                                }
                    }
            printf("%d\n",ans);
        }
	}
	return 0;
}
