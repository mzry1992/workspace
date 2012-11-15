#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;

bool mp[40][40];

const int step[5][2] = {{-1,0},{1,0},{0,-1},{0,1},{0,0}};

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(mp,false,sizeof(mp));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
            {
                for (int k = 0;k < 5;k++)
                {
                    int x = i+step[k][0];
                    int y = j+step[k][1];
                    if (x >= 0 && x < n && y >= 0 && y < m)
                        mp[i*m+j][x*m+y] = mp[x*m+y][i*m+j] = true;
                }
            }
    }
    return 0;
}
