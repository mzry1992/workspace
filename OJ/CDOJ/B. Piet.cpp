#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
char mp[60][60];
int next[60][60][4][2][2],nDP[60][60][4][2],nCP[60][60][4][2];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++)
        scanf("%s",mp[i]);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            if (i == 0 || mp[i-1][j] != mp[i][j])
                if (j == 0 || mp[i][j-1] != mp[i][j])
                    for (int DP = 0;DP < 4;DP++)
                        for (int CP = -1;CP < 2;CP += 2)
                        {
                            int fa = DP;
                            int fb = (DP+CP+4)%4;

                        }
    return 0;
}
