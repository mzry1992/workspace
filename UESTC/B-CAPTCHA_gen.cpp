#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[10][10][20];
int res[300][2];
int tot;
const char alp[26][7] = {"123"};

int main()
{
    freopen("BC.txt","r",stdin);
    freopen("BC_out.txt","w",stdout);
    for (int k = 1;k <= 4;k++)
    {
        for (int i = 0;i < 7;i++)
        {
            for (int j = 1;j <= 6;j++)
                scanf("%s",s[j][i]);
        }
        for (int i = 1;i <= 6;i++)
        {
            bool first = false;
            int sx,sy;
            tot = 0;
            for (int j = 0;j < 7;j++)
            for (int k = 0;k < 16;k++)
            if (s[i][j][k] == 'M')
            {
                if (first == false)
                {
                    first = true;
                    sx = j;
                    sy = k;
                    tot++;
                    res[tot][0] = sx;
                    res[tot][1] = sy;
                }
                else
                {
                    tot++;
                    res[tot][0] = j-sx;
                    res[tot][1] = k-sy;
                }
            }
            cout << tot << endl;
            for (int j = 1;j <= tot;j++)
                cout << res[j][0] << ' ' << res[j][1] << endl;
        }
    }
    for (int i = 0;i < 7;i++)
        {
            for (int j = 1;j <= 2;j++)
                scanf("%s",s[j][i]);
        }
        for (int i = 1;i <= 2;i++)
        {
            bool first = false;
            int sx,sy;
            tot = 0;
            for (int j = 0;j < 7;j++)
            for (int k = 0;k < 16;k++)
            if (s[i][j][k] == 'M')
            {
                if (first == false)
                {
                    first = true;
                    sx = j;
                    sy = k;
                    tot++;
                    res[tot][0] = sx;
                    res[tot][1] = sy;
                }
                else
                {
                    tot++;
                    res[tot][0] = j-sx;
                    res[tot][1] = k-sy;
                }
            }
            cout << tot << endl;
            for (int j = 1;j <= tot;j++)
                cout << res[j][0] << ' ' << res[j][1] << endl;
        }
}
