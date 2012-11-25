#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int x[4],y[4],rx[4],ry[4];

bool check()
{
    for (int i = 0; i < 4; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 4; j++)
            if (i != j && (x[i] == x[j] || y[i] == y[j]))
            {
                bool flag = true;
                for (int k = 0; k < 4 && flag; k++)
                    if (k != i && k != j)
                    {
                        if (x[i] == x[j] && x[i] == x[k])
                        {
                            if (x[i] < x[j])
                            {
                                if (x[i] < x[k] && x[k] < x[j])
                                    flag = false;
                            }
                            else
                            {
                                if (x[i] > x[k] && x[k] > x[j])
                                    flag = false;
                            }
                        }
                        else if (y[i] == y[j] && y[i] == y[k])
                        {
                            if (y[i] < y[j])
                            {
                                if (y[i] < y[k] && y[k] < y[j])
                                    flag = false;
                            }
                            else
                            {
                                if (y[i] > y[k] && y[k] > y[j])
                                    flag = false;
                            }
                        }
                    }
                if (flag)
                    cnt++;
            }
        if (cnt != 1)   return false;
    }
    return true;
}

bool check1()
{
    for (int i = 0;i < 4;i++)
        for (int j = i+1;j < 4;j++)
            if (x[i] == x[j] && y[i] == y[j])
                return false;
    return true;
}

const int a[3][2] = {{1,0},{2,1},{3,1}};

void Gao()
{
    if (check())    return;
    for (int i = 0; i < 4; i++)
    {
        for (x[i] = 1; x[i] <= 20; x[i]++)
            for (y[i] = 1; y[i] <= 20; y[i]++)
                if (check1() && check())    return;
        x[i] = rx[i];
        y[i] = ry[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (x[i] = 1; x[i] <= 20; x[i]++)
            for (y[i] = 1; y[i] <= 20; y[i]++)
            {
                for (int j = i+1; j < 4; j++)
                {
                    for (x[j] = 1; x[j] <= 20; x[j]++)
                        for (y[j] = 1; y[j] <= 20; y[j]++)
                            if (check1() && check())    return;
                    x[j] = rx[j];
                    y[j] = ry[j];
                }
            }
        x[i] = rx[i];
        y[i] = ry[i];
    }

    int pos = 0;
    for (int i = 1;i < 4;i++)
        if (x[i] < x[pos] || (x[i] == x[pos] && y[i] < y[pos]))
            pos = i;
    int dx = 1,dy = 1;
    if (y[pos]+3 > 20)
        dy = -1;
    if (x[pos]+1 > 20)
        dx = -1;
    int id = 0;
    for (int i = 0;i < 4;i++)
        if (i != pos)
        {
            x[i] = x[pos]+a[id][0];
            y[i] = y[pos]+a[id++][1];
        }
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        rx[i] = x[i];
        ry[i] = y[i];
    }
    Gao();
    for (int i = 0; i < 4; i++)
        printf("%d %d\n",x[i],y[i]);
    return 0;
}
