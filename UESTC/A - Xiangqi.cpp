#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,sx,sy,x[7],y[7],nx,ny;
char typ[7];
bool p[11][10],a[11][10];

int main()
{
    while (true)
    {
        scanf("%d%d%d",&n,&sx,&sy);
        if (n == 0 && sx == 0 && sy == 0)   break;
        for (int i = 0; i < n; i++)
            scanf(" %c%d%d",&typ[i],&x[i],&y[i]);
        memset(p,false,sizeof(p));
        for (int i = 0; i < n; i++)
            p[x[i]][y[i]] = true;
        memset(a,false,sizeof(a));
        for (int i = 0; i < n; i++)
        {
            if (typ[i] == 'R' || typ[i] == 'G')
            {
                for (int j = 0; j < 4; j++)
                    for (int k = 1;; k++)
                    {
                        nx = x[i]+step[j][0]*k;
                        ny = y[i]+step[j][1]*k;
                        if (nx < 1 || nx > 10 || ny < 1 || ny > 9)  break;
                        a[nx][ny] = true;
                        if (p[nx][ny] == true)  break;
                    }
            }
            else if (typ[i] == 'H')
            {
                for (int j = 0; j < 4; j++)
                {
                    nx = x[i]+step[j][0];
                    ny = y[i]+step[j][1];
                    if (nx < 1 || nx > 10 || ny < 1 || ny > 9)  continue;
                    if (p[nx][ny] == true)  continue;
                    nx = x[i]+step[j][0]*2+step[j][1];
                    ny = y[i]+step[j][1]*2+step[j][0];
                    if (nx >= 1 && nx <= 10 && ny >= 1 && ny <= 9)
                        a[nx][ny] = true;
                    nx = x[i]+step[j][0]*2-step[j][1];
                    ny = y[i]+step[j][1]*2-step[j][0];
                    if (nx >= 1 && nx <= 10 && ny >= 1 && ny <= 9)
                        a[nx][ny] = true;
                }
            }
            else
            {
                for (int j = 0; j < 4; j++)
                    for (int k = 1;; k++)
                    {
                        nx = x[i]+step[j][0]*k;
                        ny = y[i]+step[j][1]*k;
                        if (nx < 1 || nx > 10 || ny < 1 || ny > 9)  break;
                        if (p[nx][ny] == true)
                        {
                            for (k = k+1;; k++)
                            {
                                nx = x[i]+step[j][0]*k;
                                ny = y[i]+step[j][1]*k;
                                if (nx < 1 || nx > 10 || ny < 1 || ny > 9)  break;
                                a[nx][ny] = true;
                                if (p[nx][ny] == true)  break;
                            }
                            break;
                        }
                    }
            }
        }
        bool res = false;
        for (int i = 0;i < 4;i++)
        {
            nx = sx+step[i][0];
            ny = sy+step[i][1];
            if (nx < 1 || nx > 3 || ny < 4 || ny > 6)  continue;
            if (a[nx][ny] == false)
                res = true;
        }
        if (res == true)    puts("NO");
        else    puts("YES");
    }
    return 0;
}
