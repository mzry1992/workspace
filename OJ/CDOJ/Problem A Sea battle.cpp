#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int step[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char s[15][15];
int r,d,tot[5];

bool check(int x,int y)
{
    return (x >= 0) && (x < 10) && (y >= 0) && (y < 10);
}

int main()
{
    for (int i = 0;i < 10;i++)
        scanf("%s",s[i]);
    tot[1] = tot[2] = tot[3] = tot[4] = 0;
    bool res = true;
    for (int i = 0;i < 10;i++)
        if (s[0][i] == '1' || s[9][i] == '1' || s[i][0] == '1' || s[i][9] == '1')   res = false;
    for (int i = 0;i < 10 && res == true;i++)
        for (int j = 0;j < 10 && res == true;j++)
            if (s[i][j] == '1')
            {
                //cout << i << ' ' << j << endl;
                r = d = 0;
                while (i+d < 10 && s[i+d][j] == '1')
                    d++;
                while (j+r < 10 && s[i][j+r] == '1')
                    r++;
                if (d > 1 && r > 1)
                    res = false;
                if (d == 1)
                {
                    tot[r]++;
                    for (int k = 0;k < r;k++)
                        s[i][j+k] = '.';
                    for (int k = 0;k < r;k++)
                        for (int f = 0;f < 8;f++)
                            if (check(i+step[f][0],j+k+step[f][1]) == true)
                                if (s[i+step[f][0]][j+k+step[f][1]] == '1')
                                    res = false;
                }
                else
                {
                    tot[d]++;
                    for (int k = 0;k < d;k++)
                        s[i+k][j] = '.';
                    for (int k = 0;k < d;k++)
                        for (int f = 0;f < 8;f++)
                            if (check(i+k+step[f][0],j+step[f][1]) == true)
                                if (s[i+k+step[f][0]][j+step[f][1]] == '1')
                                    res = false;
                }
            }
    if (tot[4] != 1 || tot[3] != 2 || tot[2] != 3 || tot[1] != 4)   res = false;
    if (res == true)
        puts("correct");
    else
        puts("incorrect");
}
