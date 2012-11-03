#include <iostream>
using namespace std;

int r,c,i,j,result,map[200][200],ans[200][200],fans[200][200],step[4][2];

int solve(int x,int y)
{
    if (fans[x][y] == 1) return ans[x][y];
    int i,tx,ty,temp,temp2;
    temp = 0;
    for (i = 1;i <= 4;i++)
    {
        tx = x+step[i][1];
        ty = y+step[i][2];
        if ((tx >= 1) && (tx <= r) && (ty >= 1) && (ty <= c))
        if (map[tx][ty] < map[x][y])
        {
                        temp2 = solve(tx,ty);
                        if (temp2 > temp) temp = temp2;
        }
    }
    ans[x][y] = temp+1;
    fans[x][y] = 1;
    return ans[x][y];
}
                
int main()
{
    step[1][1] = -1; step[1][2] = 0;
    step[2][1] = 1; step[2][2] = 0;
    step[3][1] = 0; step[3][2] = 1;
    step[4][1] = 0; step[4][2] = -1;
    cin >> r >> c;
    for (i = 1;i <= r;i++)
    for (j = 1;j <= c;j++)
    {
        cin >> map[i][j];
        fans[i][j] = 0;
    }
    for (i = 1;i <= r;i++)
    for (j = 1;j <= c;j++)
    if (solve(i,j) > result) result = ans[i][j];
    cout << result << endl;
    //system("pause");
    return 0;
}
