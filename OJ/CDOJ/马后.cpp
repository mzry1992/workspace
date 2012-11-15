#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;
int f[1010][1010][2],sum[2020];

void updata(int& a,int x,int y,int k)
{
    if (x < 0 || y < 0) return;
    a = (a+f[x][y][k])%mod;
}

int main()
{
    f[0][0][0] = 1;
    f[0][0][1] = 0;
    for (int i = 0;i <= 2010;i++)
        sum[i] = 0;
    sum[1000] = 1;
    for (int i = 0;i <= 1000;i++)
        for (int j = 0;j <= 1000;j++)
        {
            if (i == 0 && j == 0)   continue;
            f[i][j][0] = 0;
            //0 : 马，可以随便转移
            updata(f[i][j][0],i-1,j-2,0);
            updata(f[i][j][0],i-1,j-2,1);
            updata(f[i][j][0],i-2,j-1,0);
            updata(f[i][j][0],i-2,j-1,1);
            //1 : 象，只能从f[i-k][j-k][0]转移过来
            //i-j+1000
            f[i][j][1] = sum[i-j+1000];
            sum[i-j+1000] = (sum[i-j+1000]+f[i][j][0])%mod;
        }
    /*for (int i = 0;i < 5;i++)
    {
        for (int j = 0;j < 5;j++)
            printf(" (%2d,%2d)",f[i][j][0],f[i][j][1]);
        printf("\n");
    }*/
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",(f[n][m][0]+f[n][m][1])%mod);
    }
    return 0;
}
