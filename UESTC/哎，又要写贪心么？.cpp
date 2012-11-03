#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,m,x,y;
int map[220][220];
int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                map[i][j]=19910424;
        for (int i=1;i<=n;i++)
            map[i][i]=0;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }

        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    if (map[j][k]>map[j][i]+map[i][k])
                        map[j][k]=map[j][i]+map[i][k];
        for (int i=m;i>0;i--)
        {
            if ()
        }
    }
}`
