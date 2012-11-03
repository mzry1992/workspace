#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int a[8][8],sum[8][8];
double res[64],g[64][64];

inline int getid(int x,int y)
{
    return x*8+y;
}

int main()
{
    while (scanf("%d",&a[0][0]) != EOF)
    {
        for (int i = 1;i < 8;i++)   scanf("%d",&a[0][i]);
        for (int i = 1;i < 8;i++)
            for (int j = 0;j < 8;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i < 8;i++)
            for (int j = 0;j < 8;j++)
            {
                sum[i][j] = 0;
                for (int k = 0;k < 4;k++)
                    if (i+step[k][0] >= 0 && i+step[k][0] < 8 && j+step[k][1] >= 0 && j+step[k][1] < 8)
                        sum[i][j] += a[i+step[k][0]][j+step[k][1]];
            }
        for (int i = 0;i < 64;i++)
            for (int j = 0;j < 64;j++)
                g[i][j] = 0.0;
        for (int i = 0;i < 8;i++)
            for (int j = 0;j < 8;j++)
            {
                g[getid(i,j)][getid(i,j)] = 1.0;
                for (int k = 0;k < 4;k++)
                    if (i+step[k][0] >= 0 && i+step[k][0] < 8 && j+step[k][1] >= 0 && j+step[k][1] < 8)
                        g[getid(i,j)][getid(i+step[k][0],j+step[k][1])] = -(double)a[i][j]/(double)sum[i+step[k][0]][j+step[k][1]];
            }
        for (int i = 0;i < 64;i++)
        {
            if (i < 10)
            {
                cout << i << " : " << endl;
                for (int j = 0;j < 8;j++)
                {
                    for (int k = 0;k < 8;k++)
                        cout << g[j][k] << ' ';
                    cout << endl;
                }
            }
            if (fabs(g[i][i]) < eps)
                for (int j = i+1;j < 64;j++)
                    if (fabs(g[j][i]) > eps)
                    {
                        for (int k = 0;k < 64;k++)
                            swap(g[i][k],g[j][k]);
                        break;
                    }
            for (int j = i+1;j < 64;j++)
                if (fabs(g[j][i]) > eps)
                {
                    double tmp = g[j][i]/g[i][i];
                    for (int k = i;k < 64;k++)
                        g[j][k] = g[j][k]-g[i][k]*tmp;
                }
        }
        for (int i = 0;i < 64;i++)
        {
            cout << i << ' ';
            for (int j = 0;j < 64;j++)
                if (fabs(g[i][j]) > eps)
                    printf("(%d %.5f) ",j,g[i][j]);
            puts("");
        }
    }
}
