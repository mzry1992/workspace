#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[5][2] = {{-1,0},{1,0},{0,-1},{0,0},{0,1}};
int n,m,a[110],res,tmp[110];
int g[16][3][1<<15],cost[16][1<<15];
int rg[16][1<<15];

void output(int i)
{
    for (int j = m-1;j >= 0;j--)
        cout << (((i>>j)&1) == 1) << ' ';
    cout << endl;
}

void Gao(int i)
{
    for (int j = 0;j < n;j++)
        tmp[j] = a[j];
    tmp[0] ^= g[m][1][i];
    tmp[1] ^= g[m][2][i];
    int tres = cost[m][i];
    if (tres > res) return;
    /*output(i);
    output(tmp[0]);
    output(tmp[1]);*/
    //cout << "I = " << i << endl;
    for (int j = 1;j < n;j++)
    {
        tres += cost[m][rg[m][tmp[j-1]]];
        if (tres > res) return;
        tmp[j] ^= g[m][1][rg[m][tmp[j-1]]];
        if (j+1 < n)
            tmp[j+1] ^= g[m][2][rg[m][tmp[j-1]]];
        tmp[j-1] ^= g[m][0][rg[m][tmp[j-1]]];
    }
    if (tmp[n-1] != (1<<m)-1)   return;
    res = tres;
}

int main()
{
    for (int i = 1;i <= 15;i++)
        for (int j = 0;j < (1<<i);j++)
        {
            g[i][0][j] = g[i][1][j] = g[i][2][j] = cost[i][j] = rg[i][j] = 0;
            for (int k = 0;k < i;k++)
                if (((j>>k)&1) == 1)
                {
                    cost[i][j]++;
                    for (int q = 0;q < 5;q++)
                        if (1+step[q][0] >= 0 && 1+step[q][0] < 3)
                            if (k+step[q][1] >= 0 && k+step[q][1] < i)
                                g[i][1+step[q][0]][j] ^= (1 << (k+step[q][1]));
                }
            for (int k = i-1;k >= 0;k--)
            {
                rg[i][j] <<= 1;
                if (((j>>k)&1) == 0)
                    rg[i][j] |= 1;
            }
        }
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            a[i] = 0;
            for (int j = 0;j < m;j++)
            {
                int tt;
                scanf("%d",&tt);
                a[i] = (a[i]<<1)|tt;
            }
        }
        res = 200*30;
        for (int i = 0;i < (1<<m);i++)
            Gao(i);
        if (res == 200*30)  puts("no solution");
        else
            printf("%d\n",res);
    }
}
