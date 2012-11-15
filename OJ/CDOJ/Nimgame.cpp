#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool SG[4][6][8];
bool visit[4][6][8];

bool Gao(int a,int b,int c)
{
    if (visit[a][b][c] == true)
        return SG[a][b][c];
    bool flag = false;
    for (int i = 0;i < a;i++)
        if (Gao(i,b,c) == false)
            flag = true;
    for (int i = 0;i < b;i++)
        if (Gao(a,i,c) == false)
            flag = true;
    for (int i = 0;i < c;i++)
        if (Gao(a,b,i) == false)
            flag = true;
    if (flag == false)  SG[a][b][c] = false;
    else SG[a][b][c] = true;
    visit[a][b][c] = true;
}

int main()
{
    memset(visit,false,sizeof(visit));
    visit[0][0][0] = true;
    SG[0][0][0] = false;
    Gao(3,5,7);
    for (int i = 0;i <= 3;i++)
        for (int j = 0;j <= 5;j++)
            for (int k = 0;k <= 7;k++)
                if (SG[i][j][k] != true)
                {
                    cout << i << ' ' << j << ' ' << k << endl;
                    cout << (i^j^k) << endl;
                }
                //printf("(%d %d %d) will %s    \n",i,j,k,SG[i][j][k]?"win":"loose");
}
