#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[9][9],emp,step;
bool c1[10],c2[9][9][10];
int flag,now,nowx,nowy;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        emp = 0;
        for (int i = 0;i < 9;i++)
            for (int j = 0;j < 9;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j] == 0)   emp++;
            }
        step = 0;
        int pstep = step;
        while (true)
        {
            for (int i = 0;i < 9;i++)
                for (int j = 0;j < 9;j++)
                    if (a[i][j] == 0)
                    {
                        for (int k = 1;k <= 9;k++)
                            c1[k] = false;
                        for (int k = 0;k < 9;k++)
                            c1[a[i][k]] = c1[a[k][j]] = true;
                        for (int x = 0;x < 3;x++)
                            for (int y = 0;y < 3;y++)
                                c1[a[i/3*3+x][j/3*3+y]] = true;
                        flag = now = 0;
                        for (int k = 1;k <= 9;k++)
                            if (c1[k] == false)
                            {
                                flag++;
                                now = k;
                            }
                        if (flag == 1)
                        {
                            a[i][j] = now;
                            step++;
                        }
                    }
            for (int i = 0;i < 9;i++)
                for (int j = 0;j < 9;j++)
                    for (int k = 1;k <= 9;k++)
                        c2[i][j][k] = true;
            for (int i = 0;i < 9;i++)
                for (int j = 0;j < 9;j++)
                {
                    for (int k = 0;k < 9;k++)
                        c2[i][k][a[i][j]] = c2[k][j][a[i][j]] = false;
                    for (int x = 0;x < 3;x++)
                        for (int y = 0;y < 3;y++)
                            c2[i/3*3+x][j/3*3+y][a[i][j]] = false;
                }
            for (int i = 0;i < 3;i++)
                for (int j = 0;j < 3;j++)
                    for (int k = 1;k <= 9;k++)
                    {
                        flag = nowx = nowy = 0;
                        for (int x = 0;x < 3;x++)
                            for (int y = 0;y < 3;y++)
                                if (c2[i*3+x][j*3+y][k] == true)
                                {
                                    flag++;
                                    nowx = x;
                                    nowy = y;
                                }
                        if (flag == 1)
                        {
                            a[i*3+nowx][j*3+nowy] = k;
                            step++;
                        }
                    }
            if (pstep == step)  break;
            pstep = step;
        }
        printf("%d",(emp == step));
    }
    printf("\n");
    return 0;
}
